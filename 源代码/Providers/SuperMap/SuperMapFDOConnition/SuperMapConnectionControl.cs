using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;
using Autodesk.Gis.Map.DataConnect.Plugins;


using System.Diagnostics;


namespace SuperMapConnectionPlugin
{


    [DataConnectPluginAttribute("SuperMap.SuperMap SDX.1.0")]
    public partial class SuperMapConnectionControl : UserControl
            , IDataConnectConnectionPlugin
    {

#if LANGUAGE_ZH_CN
        protected const string strDatasourceTypeLabel = "����Դ����:";
        protected const string strDatasourceInfoGroupBox = "����Դ��Ϣ";
        protected const string strSeverNameLabel = "�ļ���:";
        protected const string strSeverNameLabelDb = "����������:";
        protected const string strSeverNameLabelIntance = "ʵ������:";
        protected const string strDbNameLabel = "���ݿ�����:";
        protected const string strUserLabel = "�û�����:";
        protected const string strPasswordLabel = "����:";
        protected const string strOpenModeGroupBox = "����ѡ��";
        protected const string strImageCheckBox = "ֻ��ȡӰ��";
        protected const string strEncryptCheckBox = "����";
        protected const string strReadOnlyRadioButton = "ֻ��";
        protected const string strExclusiveRadioButton = "��ռ";

        protected const string strSdbEng = "SuperMap SDB Plus �ļ�(*.SDB)";
        protected const string strSITEng = "SuperMap SIT Ӱ���ļ�(*.SIT)";
        protected const string strSQLEng = "SQL Plus ����Դ";
        protected const string strOracleEng = "Oracle ����Դ";

        protected const string strOpenFile = "���ļ�";
        protected const string strErrNoUseFunction = "ϵͳ����,����ʹ�øù���!";

        protected const string strlnkHomepage = "http://www.supermap.com.cn";
        //protected const string strlnkHelp = "����";

#else
        protected const string strDatasourceTypeLabel = "DataSource Type:";
        protected const string strDatasourceInfoGroupBox = "DataSource Information";
        protected const string strSeverNameLabel = "File";
        protected const string strSeverNameLabelDb = "Server";
        protected const string strSeverNameLabelIntance = "Instance";
        protected const string strDbNameLabel = "Database:";
        protected const string strUserLabel = "User:";
        protected const string strPasswordLabel = "Password:";
        protected const string strOpenModeGroupBox = "Connection Option";
        protected const string strImageCheckBox = "Only read Image";
        protected const string strEncryptCheckBox = "Encrypt";
        protected const string strReadOnlyRadioButton = "Read Only";
        protected const string strExclusiveRadioButton = "Exclusive";

        protected const string strSdbEng = "SuperMap SDB Plus File(*.SDB)";
        protected const string strSITEng = "SuperMap Image File(*.SIT)";
        protected const string strSQLEng = "SQL Plus DataSource";
        protected const string strOracleEng = "Oracle DataSource";

        protected const string strOpenFile = "Open File";
        protected const string strErrNoUseFunction = "System Error!This function is disabled!";

        protected const string strlnkHomepage = "http://www.supermap.com";
        protected const string strlnkHelp = "help";
#endif


        public SuperMapConnectionControl()
        {
            InitializeComponent();

            this.datasourceTypeComboBox.Items.AddRange(new object[] {
            strSdbEng,//"SuperMap SDB�ļ�(*.SDB)",
            strSITEng, //"SuperMap SITӰ���ļ�(*.SIT)",
            strSQLEng, //"SQL����Դ",
            strOracleEng //"Oracle����Դ"
            });
            this.datasourceTypeLabel.Text = strDatasourceTypeLabel;// "����Դ����:";
            this.datasourceInfoGroupBox.Text = strDatasourceInfoGroupBox;// "����Դ��Ϣ";
            this.passwordLabel.Text = strPasswordLabel;// "����:";
            this.userLabel.Text = strUserLabel;// "�û�����:";
            this.dbNameLabel.Text = strDbNameLabel;// "���ݿ�����:";
            this.severNameLabel.Text = strSeverNameLabel;// "�ļ���:";
            this.openModeGroupBox.Text = strOpenModeGroupBox;// "����ѡ��";
            this.encryptCheckBox.Text = strEncryptCheckBox;// "����";
            this.exclusiveRadioButton.Text = strExclusiveRadioButton;// "��ռ";
            this.readOnlyRadioButton.Text = strReadOnlyRadioButton;// "ֻ��";
            this.imageCheckBox.Text = strImageCheckBox;// "ֻ��ȡӰ��";
            this.openSDBDialog.Title = strOpenFile;// "���ļ�";

            //this.lnkHelp.Text = strlnkHelp;
            this.lnkHomepage.Text = strlnkHomepage;

            this.datasourceTypeComboBox.SelectedIndex = 0;

            bInitialize = true;

            //DEBUG_TRACE("Initializing SuperMapConnectionControl and  checkConnectionParametersValid ...");
        }

        #region IDataConnectPlugin implementation
        // IDataConnectPlugin implementation
        protected IDataConnectPluginHost m_host;
        //protected string m_providerName;

        public void Attach(IDataConnectPluginHost host)
        {
            //DEBUG_TRACE("Attach host");

            m_host = host;
        }

        public void Detach() { m_host = null; }

        public IDataConnectPluginHost Host
        {
            get
            {
                return m_host;
            }
        }

        public UserControl ClientControl
        {
            get
            {
                return this;
            }
        }

        #endregion

        #region IPlugin implementation
        // IPlugin implementation

#if CHINESE
        protected string title = "title";
        protected string description = "description";
        protected string company = "SuperMap GIS Technologies, Inc";
        protected string version = "1.0.0";
        protected Type[] dependencies;
#else
        protected string title = "title";
        protected string description = "description";
        protected string company = "SuperMap GIS Technologies, Inc";
        protected string version = "1.0.0";
        protected Type[] dependencies;
#endif



        public string Title
        {
            get
            {
                return title;
            }

            set
            {
                title = value;
            }
        }

        public string Description
        {
            get
            {
                return description;
            }
            set
            {
                description = value;
            }
        }

        public string Company
        {
            get
            {
                return company;
            }
            set
            {
                company = value;
            }
        }

        public string Version
        {
            get
            {
                return version;
            }
            set
            {
                version = value;
            }
        }

        public Type[] Dependencies
        {
            get
            {
                return dependencies;
            }
        }

        #endregion

        #region IDataConnectConnectionPlugin Property

        private Dictionary<string, string> m_connection = new Dictionary<string, string>();
        private bool m_isParametersValid = false;
        private string m_ProviderName;// = "SuperMap.SDB&SDX.1.0";
        public string[] ConnectionParameterNames
        {
            get
            {
                //DEBUG_TRACE("Getting ConnectionParameterNames ...");

                string[] names = new string[this.m_connection.Keys.Count];
                this.m_connection.Keys.CopyTo(names, 0);

                return names;
            }
        }

        public bool ConnectionParametersValid
        {
            get
            {
                return m_isParametersValid;
            }
        }

        public string ProviderName
        {
            get
            {
                return m_ProviderName;
            }
        }

        #endregion

        #region IDataConnectConnectionPlugin methods

        public string GetConnectionParameter(string name)
        {
            //DEBUG_TRACE("���뺯��GetConnectionParameter. ConnectionParameter " + name + " is " + this.m_connection[name]);

            try
            {
                return this.m_connection[name];
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
                return "";
            }
        }

        public void Initialize(string providerName)
        {
            m_ProviderName = providerName;
        }

        public void SetConnectionParameter(string name, string value)
        {
            this.m_connection[name] = value;
        }

        public void SetConnectionParametersToDefaults()
        {
            if (!bInitialize)   //��ʼ����ʱ������ֵ��Ϊ��
            {
                m_connection.Clear();
                m_isParametersValid = false;
            }
            else   //���ѡ����SuperMap Provider,Ȼ���ֵ�ѡ������Provider,�ٻ�����ʱ����Ҫ������Ϊ�ϴε�ֵ        
            {
                checkConnectionParametersValid();
            }
        }

        #endregion


        #region IDataConnectConnectionPlugin event
        public event ParameterValueChangedEventHandler ParameterValueChangedEvent;
        #endregion

        //���ڲ�������Ϣʱ������������
        const string sdbConnName = "sdb";
        const string sqlConnName = "sql";
        const string sitConnName = "sit";
        const string sqlPlusConnName = "sql+";
        const string oracleConnName = "ora";
        const string oracleSpatialConnName = "oracle spatial";

        /// <summary>
        /// �������Ƿ���Ч,����Ч��ʱ����ParameterValueChangedEvent��Ϣ,֪ͨMap3D���Ӱ�ť�ɼ���
        /// </summary>
        private void checkConnectionParametersValid()
        {
            try
            {
                //����ǻ�û�г�ʼ��,�ؼ���û�д���,ִ�е�ʱ���ǻ�����
                if (!bInitialize)
                {
                    return;
                }

                //DEBUG_TRACE("���뺯��checkConnectionParametersValid��������Ч�� ... ");

                string strDataSource = "";		//L"����Դ";
                string strServer = "";  //L"server";
                string strUser = "";	//L"user";
                string strPassword = "";	//L"password";
                string strConnType = "";    //L"type";
                string strDatabase = "";    //L"database";
                // added by zhouxu 2008-1-17
                string strIsImage = "false";   //true��ʾ��Ӱ��ģʽ�򿪣�Ĭ��Ϊ��Ӱ��ģʽ��

                ///
                ///���Ȳ�����λ
                ///
                m_connection.Clear();
                m_isParametersValid = false;

                ///
                ///Ȼ��ӽ�����ȡ��������Ӳ���ֵ
                ///
                //����Դ����
                if (0 == this.datasourceTypeComboBox.SelectedIndex)
                {   // "sdb";
                    strConnType = sdbConnName;
                    //this.imageCheckBox.Checked = false;
                    //this.imageCheckBox.Enabled = true;
                }
                else if (1 == this.datasourceTypeComboBox.SelectedIndex)
                {   // "sit"
                    strConnType = sitConnName;
                    //this.imageCheckBox.Checked = true;
                    //this.imageCheckBox.Enabled = false;
                }
                else if (2 == this.datasourceTypeComboBox.SelectedIndex)
                {   // "sql";
                    strConnType = sqlConnName;
                    //this.imageCheckBox.Checked = false;
                    //this.imageCheckBox.Enabled = true;
                }
                else if (3 == this.datasourceTypeComboBox.SelectedIndex)
                {   // "oracle";
                    strConnType = oracleConnName;
                    //this.imageCheckBox.Checked = false;
                    //this.imageCheckBox.Enabled = true;
                }
                else
                {
                    strConnType = "";
                }

                //�ļ�����Դ����
                if (0 == this.datasourceTypeComboBox.SelectedIndex ||
                    1 == this.datasourceTypeComboBox.SelectedIndex)
                {
                    strDatabase = fileTextBox.Text;
                    strDatabase.Trim();

                    if (bEncrypt)
                    {
                        strPassword = passwordTextBox.Text;
                    }
                }
                else
                {   //SQL��SQL+��Oracle����OracleSpatial����Դ����

                    //��������
                    strServer = instanceTextBox.Text;
                    strServer.Trim();

                    //���ݿ���
                    strDatabase = dbNameTextBox.Text;
                    strDatabase.Trim();

                    //�û���
                    strUser = userTextBox.Text;
                    strUser.Trim();

                    //����
                    strPassword = passwordTextBox.Text;
                }

                // �Ƿ�Ӱ��ģʽ�� added by zhouxu 2008-1-17
                if (this.imageCheckBox.Checked)
                {
                    strIsImage = "true";
                }

                ///
                ///���в�����Ч����֤
                ///
                if (0 == strConnType.Length)
                {
                    //DEBUG_TRACE("�������ͳ���Ϊ0������ParameterValueChangedEvent�¼�,������Ч ... ");

                    ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                    m_isParametersValid = false;
                    return;
                }
                else if (sdbConnName == strConnType)
                {
                    if (strDatabase.Length <= 0)
                    {
                        //DEBUG_TRACE("���ݿⳤ��Ϊ0������ParameterValueChangedEvent�¼�,������Ч ... ");

                        ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                        m_isParametersValid = false;
                        return;
                    }

                    if (bEncrypt)
                    {
                        if (strPassword.Length <= 0)
                        {
                            //DEBUG_TRACE("���볤��Ϊ0������ParameterValueChangedEvent�¼�,������Ч ... ");

                            ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                            m_isParametersValid = false;
                            return;
                        }
                    }

                    this.m_connection.Clear();
                    strDataSource = "type=" + strConnType + ";database=" + strDatabase;
                    if (bEncrypt)
                    {
                        strDataSource += ";password=" + strPassword;
                    }
                    strDataSource += ";IsImage=" + strIsImage;  // added by zhouxu 2008-1-17 
                    SetConnectionParameter("DataSource", strDataSource);
                    m_isParametersValid = true;

                    //DEBUG_TRACE("����ParameterValueChangedEvent�¼�,������Ч !!!. ");

                    ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                    return;
                }
                else if (sitConnName == strConnType)
                {
                    if (strDatabase.Length <= 0)
                    {
                        //DEBUG_TRACE("���ݿⳤ��Ϊ0������ParameterValueChangedEvent�¼�,������Ч ... ");

                        ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                        m_isParametersValid = false;
                        return;
                    }

                    this.m_connection.Clear();
                    strDataSource = "type=" + strConnType + ";database=" + strDatabase;

                    strDataSource += ";IsImage=" + strIsImage;
                    SetConnectionParameter("DataSource", strDataSource);
                    m_isParametersValid = true;

                    ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                    return;
                }
                else if (sqlConnName == strConnType || sqlPlusConnName == strConnType
                    || oracleConnName == strConnType || oracleSpatialConnName == strConnType)
                {
                    if (strServer.Length <= 0)
                    {
                        //DEBUG_TRACE("����������Ϊ0������ParameterValueChangedEvent�¼�,������Ч ... ");

                        ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                        m_isParametersValid = false;
                        return;
                    }

                    if (strDatabase.Length <= 0)
                    {
                        //DEBUG_TRACE("���ݿⳤ��Ϊ0������ParameterValueChangedEvent�¼�,������Ч ... ");

                        ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                        m_isParametersValid = false;
                        return;
                    }

                    if (strUser.Length <= 0)
                    {
                        //DEBUG_TRACE("�û�����Ϊ0������ParameterValueChangedEvent�¼�,������Ч ... ");

                        ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                        m_isParametersValid = false;
                        return;
                    }

                    if (strPassword.Length <= 0)
                    {
                        //DEBUG_TRACE("���볤��Ϊ0������ParameterValueChangedEvent�¼�,������Ч ... ");

                        ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                        m_isParametersValid = false;
                        return;
                    }

                    this.m_connection.Clear();
                    strDataSource = "type=" + strConnType + ";server=" + strServer + ";database=" + strDatabase +
                        ";user=" + strUser + ";password=" + strPassword;
                    strDataSource += ";IsImage=" + strIsImage;  // added by zhouxu 2008-1-17 
                    SetConnectionParameter("DataSource", strDataSource);
                    m_isParametersValid = true;

                    //DEBUG_TRACE("����ParameterValueChangedEvent�¼�,������Ч !!!. ");

                    ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                    return;
                }

                m_isParametersValid = false;
                ParameterValueChangedEvent(this, new ParameterValueChangedEventArgs("DataSource"));
                return;
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
            }
            finally
            {
            }
        }



        private bool bEncrypt = false;
        private string strSdbFilePath = "";
        private bool bInitialize = false;

        private void fileButton_Click(object sender, EventArgs e)
        {
            try
            {
                DialogResult responseDialogResult;
                openSDBDialog.InitialDirectory = Application.StartupPath;

                if (this.datasourceTypeComboBox.SelectedIndex == 0)
                    openSDBDialog.Filter = "SuperMap SDB Files(*.sdb)|*.sdb";
                else
                    openSDBDialog.Filter = "SuperMap SIT Files(*.SIT)|*.SIT";

                responseDialogResult = openSDBDialog.ShowDialog();

                if (DialogResult.Cancel != responseDialogResult)
                {
                    strSdbFilePath = openSDBDialog.FileName;
                    this.fileTextBox.Text = strSdbFilePath;
                }
            }
            catch (Exception ec)
            {
                MessageBox.Show(ec.Message);
            }
        }

        /// <summary>
        /// ��ز����ı��¼�
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void datasourceTypeChanged(object sender, EventArgs e)
        {
            //DEBUG_TRACE("���뺯��datasourceTypeChanged ... ");

            try
            {
                //��������Ϣ����
                SetConnectionParametersToDefaults();

                switch (this.datasourceTypeComboBox.SelectedIndex)
                {
                    case 0: //�ļ�
                        {
                            ///
                            ///����Դ��Ϣ
                            ///
                            //�����ļ�����Ϣ
                            this.severNameLabel.Text = strSeverNameLabel;// "�ļ���";
                            this.fileTextBox.Show();
                            this.fileButton.Show();
                            this.instanceTextBox.Hide();

                            //���ݿ�����
                            this.dbNameLabel.Enabled = false;
                            this.dbNameTextBox.Enabled = false;

                            //�û�����
                            this.userLabel.Enabled = false;
                            this.userTextBox.Enabled = false;

                            //����
                            this.passwordLabel.Enabled = bEncrypt;
                            this.passwordTextBox.Enabled = bEncrypt;

                            this.imageCheckBox.Checked = false;
                            this.imageCheckBox.Enabled = true;

                        }
                        break;
                    case 1: //SIT�ļ�
                        {
                            ///
                            ///����Դ��Ϣ
                            ///
                            //�����ļ�����Ϣ
                            this.severNameLabel.Text = strSeverNameLabel;// "�ļ���";
                            this.fileTextBox.Show();
                            this.fileButton.Show();
                            this.instanceTextBox.Hide();

                            //���ݿ�����
                            this.dbNameLabel.Enabled = false;
                            this.dbNameTextBox.Enabled = false;

                            //�û�����
                            this.userLabel.Enabled = false;
                            this.userTextBox.Enabled = false;

                            //����
                            this.passwordLabel.Enabled = false;
                            this.passwordTextBox.Enabled = false;

                            this.imageCheckBox.Checked = true;
                            this.imageCheckBox.Enabled = false;

                        }
                        break;
                    case 2: //SQL����Դ
                        {
                            ///
                            ///����Դ��Ϣ
                            ///
                            //���÷���������
                            this.severNameLabel.Text = strSeverNameLabelDb;// "����������";
                            this.fileTextBox.Hide();
                            this.fileButton.Hide();
                            this.instanceTextBox.Show();

                            //���ݿ�����
                            this.dbNameLabel.Enabled = true;
                            this.dbNameTextBox.Enabled = true;

                            //�û�����
                            this.userLabel.Enabled = true;
                            this.userTextBox.Enabled = true;

                            //����
                            this.passwordLabel.Enabled = true;
                            this.passwordTextBox.Enabled = true;

                            this.imageCheckBox.Checked = false;
                            this.imageCheckBox.Enabled = true;
                        }
                        break;
                    case 3:
                        {
                            ///
                            ///����Դ��Ϣ
                            ///
                            //����ʵ������
                            this.severNameLabel.Text = strSeverNameLabelIntance;// "ʵ������";
                            this.fileTextBox.Hide();
                            this.fileButton.Hide();
                            this.instanceTextBox.Show();

                            //���ݿ�����
                            this.dbNameLabel.Enabled = true;
                            this.dbNameTextBox.Enabled = true;

                            //�û�����
                            this.userLabel.Enabled = true;
                            this.userTextBox.Enabled = true;

                            //����
                            this.passwordLabel.Enabled = true;
                            this.passwordTextBox.Enabled = true;

                            this.imageCheckBox.Checked = false;
                            this.imageCheckBox.Enabled = true;
                        }
                        break;
                    default:
                        break;
                }

                checkConnectionParametersValid();
            }
            catch (Exception ec)
            {
                MessageBox.Show(ec.Message);
            }

        }

        private void transactionCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            checkConnectionParametersValid();
        }

        private void encryptCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (0 != this.datasourceTypeComboBox.SelectedIndex)
            {
                MessageBox.Show(strErrNoUseFunction);
                return;
            }

            checkConnectionParametersValid();
        }

        private void readOnlyRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            checkConnectionParametersValid();
        }

        private void filePathChanged(object sender, EventArgs e)
        {
            checkConnectionParametersValid();
        }

        private void instanceTextChanged(object sender, EventArgs e)
        {
            checkConnectionParametersValid();
        }

        private void dbNameTextChanged(object sender, EventArgs e)
        {
            checkConnectionParametersValid();
        }

        private void userTextChanged(object sender, EventArgs e)
        {
            checkConnectionParametersValid();
        }

        private void passwordTextChanged(object sender, EventArgs e)
        {
            checkConnectionParametersValid();
        }


        [Conditional("TRACE"), Conditional("DEBUG")]
        private void DEBUG_TRACE(string strMsg)
        {

            Trace.WriteLine(strMsg);
        }


        private void fileTextBox_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            if (Keys.Tab == e.KeyCode)
            {
                fileTextBox.SelectAll();
            }
        }

        private void instanceTextBox_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            if (Keys.Tab == e.KeyCode)
            {
                instanceTextBox.SelectAll();
            }
        }

        private void dbNameTextBox_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            if (Keys.Tab == e.KeyCode)
            {
                dbNameTextBox.SelectAll();
            }
        }

        private void userTextBox_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            if (Keys.Tab == e.KeyCode)
            {
                userTextBox.SelectAll();
            }
        }

        private void passwordTextBox_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            if (Keys.Tab == e.KeyCode)
            {
                passwordTextBox.SelectAll();
            }
        }

        private void fileButton_KeyDown(object sender, KeyEventArgs e)
        {
            if (Keys.Enter == e.KeyCode)
            {
                fileButton_Click(sender, e);
            }
        }

        private void lnkHomepage_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start(strlnkHomepage);
        }

        private void lnkHelp_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start("Help/SupermapProvider.chm");
        }

        private void SuperMapConnectionControl_Load(object sender, EventArgs e)
        {

        }

        private void SuperMapLogo_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start(strlnkHomepage);
        }

    }
}
/*!
   **************************************************************************************
    \file     UGLogFile.h
   **************************************************************************************
    \author   ���ܿ�
    \brief    ��־�ļ��࣬���Լ�¼��־��Ϣ                                           
    \attention   
   ----------------------------------------------------------------------------------<br>
    Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    All Rights Reserved.                                                             <br>
   ----------------------------------------------------------------------------------<br> 
   
   **************************************************************************************
    \version 2005-05-08  ���ܿ�    ��ʼ���汾.                                       <br>
	\version 2007-04-03  ��־��    ����10���깩ֱ��ʹ��,���ϴ������.				 <br>
	\remarks <em>����UGC����־�ʹ���������ϵ�˵��</em>
		��UGC�У��ʹ�����־�йص��������࣬һ����UGErrorObj��������Щ������SFC�е�soError��
	ֻ��������Ĵ�����Ϣ���Դ�Ŷ�����һ��Ϊ��Ž�Ϊ���صĴ�������Ϣ�����ο����߿��Դ�
	��������л��һЩ����Ϊʲô�������Ϣ���Ա������޸ĺ�ά����
	��һ����UGLogFile��������Ҫ�ǰѸ�����Ϣ������д�뵽һ��ָ�����ļ��У�������Ϣ��д��ʱ��
	�ǿ����������س̶ȵģ����ڷ�Ϊ5���̶ȣ��ֱ��ǣ�debug��info��warning��error��fatal��
	��־�ļ�ֻ�����û��趨��Ŵ򿪲�������д����Ϣ�����趨����־�ļ���¼�����̶ֳȵ���Ϣ��
	���磬����趨����־�ļ���warning�̶ȣ���ôinfo��debug�����Ϣ�Ͳ�������д�뵽��־�ļ���
	����error��fatal�����ϢҲ��д�룩��
		��ǰ������Ա�ڿ���ʱ�����Ҫ��¼һ��������Ϣ����Ҫ���������м�¼һ������Ҫ����־�ļ���д��һ����
	��ʱ���񣬴���Ҳ�����š��ں�����������󣬾����������µķ�ʽ������
	1��	��UGLogFile.h�ж���5�ס�10���꣬��������־�ļ��зֱ��¼5���̶ȵ���־��Ϣ��
	���ֻ��Ҫ������Щ��Ϳ����ˣ���Ҫ����ڲ���ʵ�֣�
	2��	��debug��warning�ĺ���ã���Ϣ�ǲ����¼����������еģ�error��fatal�ĺ���ã�
	��Ϣ���Զ����������м�¼һ�ݣ�
	3��	��debug��warning�ĺ���ã�����ֱ��д�ַ�����Ϣ��������Ӣ�ģ���id���Ը�0��-100�ȣ�
	��error��fatal�ĺ꣬���������ȷ���ַ�����Դid�ţ���Ϊ��Щid��Ҫ���ⲿ�û����Ҵ���ʹ��
	4��	10����Ķ������£�
	a)	UGDEBUG(id)
	b)	UGDEBUG2(id, strMsg)
	c)	UGINFO(id)
	d)	UGINFO2(id, strMsg)
	e)	UGWARNING(id)
	f)	UGWARNING2(id, strMsg)
	g)	UGERROR(id)
	h)	UGERROR2(id, strMsg)
	i)	UGFATAL(id)
	j)	UGFATAL2(id, strMsg)
   **************************************************************************************
*/

#if !defined(UGLOGFILE)
#define UGLOGFILE

#include "ugplatform.h"

//! \brief Ĭ�ϵ���־��Ϣ�ĸ�ʽ������
//! %DATETIME ����ʱ��
//! %TIMESPAN ����������־��¼֮���ʱ����(������������������־֮������ܼ�¼)
//! %LEVEL ��־����
//! %MSG ��־��Ϣ
//! %THREADID �߳�id
//! %CODEFILE �����ļ�
//! %CODELINE ������
//! %RESID    ��Դ�ַ���ID
#define DEF_LOG_FORMAT "%DATETIME [%TIMESPAN] (%LEVEL) |  %MSG "EOLSTRING"ThreadID:%THREADID "EOLSTRING"CodeFile:%CODEFILE "EOLSTRING"CodeLine:%CODELINE"
//! ����ʱ���ʽ,��ο�UGTime::Format�Ľ���
#define DEF_DATE_TIME_FORMAT "%Y-%m-%d %H:%M:%S"


#include "ugdefs.h"
#include "UGString.h"
#include "UGFileStream.h"
#include "UGFileStdio.h"
#include "UGThread.h"
#include "UGDict.h"
#include "UGErrorObj.h"
#include <queue>


#define UGDEBUG(id)				UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Debug, id, __FILE__, __LINE__)
#define UGDEBUG2(id, strMsg)	UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Debug, id, strMsg, __FILE__, __LINE__)
#define UGINFO(id)				UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Info, id, __FILE__, __LINE__)
#define UGINFO2(id, strMsg)		UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Info, id, strMsg, __FILE__, __LINE__)
#define UGWARNING(id)			UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Warning, id,  __FILE__, __LINE__)
#define UGWARNING2(id, strMsg)	UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Warning, id, strMsg, __FILE__, __LINE__)
#define UGERROR(id)				UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Error, id, __FILE__, __LINE__)
#define UGERROR2(id, strMsg)	UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Error, id, strMsg, __FILE__, __LINE__)
#define UGFATAL(id)				UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Fatal, id, __FILE__, __LINE__)
#define UGFATAL2(id, strMsg)	UGC::UGLogFile::GetInstance().RecordLog(UGC::UGLogFile::Fatal, id, strMsg, __FILE__, __LINE__)


namespace UGC {

class UGLogQueryDef;
struct UGLogItem;

//! ��־�ļ���ص�����
typedef  void (*LogCallBack)(const char* pchErrorInfo);

//! Open �ص�����
typedef  UGbool (*LogOpenCallBack)(void* pDataSource, const UGString& strTableName);
//!  Write �ص�����
typedef  void (*LogWriteCallBack)(void* pDataSource, const UGString& strTableName, const UGLogItem& logItem);
//!  Close �ص�����
typedef  void (*LogCloseCallBack)(void* pDataSource, const UGString& strTableName);


//! \brief ��־item��ÿ����־��Ϣ��������¼
struct UGLogItem
{
	//! \brief ����ʱ��
	UGTime m_time;
	//! \brief ʱ����,���뵥λ
	UGint m_nTimeSpan;
	//! \brief ��־����, ͬ UGLogFile::LogLevelType
	UGint m_eLevel;
	//! \brief ��־����
	UGString m_strMsg;
	//! \brief �߳�ID
	UGuint m_nThreadID;
	//! \brief ��־��������Դ�ַ���ID
	UGuint m_nResID;
	//! \brief �����ļ�
	UGString m_strCodeFile;
	//! \brief ������
	UGuint m_nCodeLine;

	UGLogItem(){m_nThreadID=m_nResID=m_nCodeLine=0;}
	//Item(const Item& item){*this = item;}
	//Item& operator=(const Item& item){}
};

typedef UGArray<UGLogItem> UGLogItems;

//! \brief һ��Ԥ��ȷ����С, ���ٶ�λ��һ������, Ч�ʷǳ���
//! \remarks �ڲ�����UGArrayʵ��, �Ժ���Կ�����Ϊ�������ļ�
template<typename T>
class BASE_API UGContainer
{
public:
	UGContainer()
	{
		m_bCycled = FALSE;
		m_nPos = 0;
		SetCapacity(16);
	}

	//! �õ�����������
	UGint GetCapacity() const
	{
		return m_items.GetSize();
	}

	void SetCapacity(UGint nCapacity)
	{
		m_items.SetSize(nCapacity);
	}

	UGint GetSize() const 
	{
		if(m_bCycled) 
		{
			return GetCapacity();
		}
		return m_nPos;
	}

	void Add(const T& value)
	{
		m_items[m_nPos++] = value;
		if(m_nPos >= GetCapacity()) 
		{
			m_bCycled = TRUE;
			m_nPos = 0;
		}
	}
	
	T& operator[](UGint nIndex) 
	{
		UGint c = GetCapacity();
		if (c > 0)
		{
			nIndex = (c+m_nPos-nIndex-1)%c;
			return m_items[nIndex];
		}
		m_items.SetSize(1);
		return m_items[0];
	}

	void Clear()
	{
		m_bCycled = FALSE;
		m_nPos = 0;
	}
	
private:
	//! �Ƿ���ѭ����
	UGbool m_bCycled;
	//! ��һ�����λ��
	UGint m_nPos;
	//! �洢������Ϣ
	UGArray<T> m_items;	
};

//! \brief ��־�ļ���
//! \remarks �߱�����:�ּ���д����־;��־�洢Ϊ�ı�,xml,���ݿ�;�ɲ�ѯ(��ѯ��������);
//!			 ֧�ֹ���;�̰߳�ȫ;���Զ�����־��Ϣ��ʽ;��־ʵʱд��;������:д��100������¼��ʱ����1��������(�ı���ʽ)
//!			 Openʱ,���趨ֻ�洢���ڴ���; ����ʱ�ݶ��ͼ��������������д��;
class BASE_API UGLogFile  
{
	friend class UGErrorObj;
public:
	//! \brief ��־����
	enum LogLevelType
	{
		Debug	=	100,
		Info	=	200,
		Warning	=	300,
		Error	=	400,
		Fatal	=	500
	};

	//! \brief ��־�洢��ʽ
	enum Mode
	{
		//! \brief ��ͨ���ı��ļ�
		Text	= 0, 
		//! \brief XML��ʽ�洢
		XML		= 1,
		//! \brief ���ݿ�
		Database = 2,
		//! \brief �ڴ�ģʽ
		Memory = 3
	};

	//! \brief ��־���ļ��洢, �涨���ļ���ʱ���;Ĭ��ΪNoTime
	enum TimeInterval
	{
		// by zengzm 2007-10-15 ����ﵽFileSizeLimit������ѡ����δ�������Ͳ�ҪOneFile��ö����
		// ���Ƿ��ļ��洢
		//OneFile = 0, 

		//! ������ʱ��������
		NoTime = 0,

		//! Сʱ
		Hour = 1,
		//! ��
		Day = 2, 
		//! ��
		Week = 3,
		//! ��
		Month = 4
	};

	//! \brief ����־�ļ��Ĵ�С�ﵽĳ���޶�ֵʱ����ͬ�Ĵ���ʽ
	//! \remarks ֻ��Text��XMLģʽ����־�����ã��Ժ�����Ҫ���Կ���Databaseģʽ;
	//! ֻ����FileSizeLimit����0ʱ��������
	enum SizeLimitMode
	{
		//! \brief �ع��������ļ�ͷ��ʼ��¼���Ḳ��ԭ���ļ�ͷ����Ϣ��������û�и��ǵ�����Ϣ����ɾ��
		//! \remarks �ع���XMLģʽ��������;ԭ����XMLģʽ��Ҫ������XML��ʽ,����Ƚ�����
		Rolling = 0,
		//! \brief ���´�, ԭ�����ļ������
		ReOpen = 1, 
		//! \brief ����һ���µ���־�ļ�, �ļ���������#1/2/3�ȷ�ʽ
		NewFile = 2
	};

public:
	~UGLogFile();
	
	//! \brief �ô˺����������־�ļ���Ψһʵ��
	//! \param bLogStarting �Ƿ����ڳ���Log����״̬��Ĭ��Ϊfalse��
	//! ����UGLogFileStartup�Ĺ��캯��������Ϊtrue��������ֹѭ�����죻
	//! ��AIX��,�������˴���,����ֳ������в�����������
	static UGLogFile& GetInstance(bool bLogStarting=false);

	//! ��Ҫֱ��ʹ�ã���ʹ��GetInstance���õ�Ψһʵ��
	UGLogFile();
private:
	UGLogFile(const UGLogFile&);
	UGLogFile& operator=(const UGLogFile&);
	

public:
	//! \brief ����־�ļ�����ָ���־�ļ��ĸ���Ĭ������, eModeֻ֧��Text��XML
	//! \param strFileName [in] ��־�ļ�ȫ·����
	//! \param bAppend [in] ���Ŀ����־�ļ��Ѿ����ڣ��Ƿ����ļ�β׷�����ݣ����Ǹ���ԭ�����ݡ�
	//! \param eMode [in] ��־�ļ���ģʽ����������֧��Text��XMLģʽ��
	//! \return �򿪳ɹ�������true��ʧ�ܷ���false��
	//! \attention �������Ѿ�����������UGbool Open(const UGString& strPath, const UGString& strPrefix="Log", TimeInterval eTimeInterval=Day, Mode eMode=Text);
	//!			   ��ȡ������ʱ����һ��ʱ�䣬6.0������ɾ��
	UGbool Open(const UGString& strFileName, UGbool bAppend=false, Mode eMode=Text);	

	//! \brief ���ݵ�ǰʱ������Ĭ���ļ�, Ĭ��Ϊ�ı���ʽ, ���趨eModeΪText,XML��Memoryģʽ
	//! \param eMode [in] ��־�ļ���ģʽ��������֧��Text��XML��Memoryģʽ��
	//! \return �򿪳ɹ�������true��ʧ�ܷ���false��
	UGbool Open(Mode eMode=Text);	

	//! \brief ����־���ݿ�
	//! \remark ��־���ݿ�����������ȴ�����,����SuperMap������Դ
	//! \param pDataSource [in] ����Դָ�룬��������Ч�Ϸ������Ѿ�Open��SuperMap����Դ��
	//! \param strTableName [in] �������ݼ������ݱ������ƣ�������Ϸ���������һ���µ����֡�
	//! \return �򿪳ɹ�������true��ʧ�ܷ���false��
	UGbool Open(void *pDataSource, const UGString& strTableName);	

	//! \brief ����־������һ������ֲ�ͬ���ļ������־��Ϣ
	//! \param strPath �����־�ļ���Ŀ¼
	//! \param strPrefix ��־�ļ���ǰ׺
	//! \param eTimeInterval ��־���ļ���ʱ���, ��Ĭ��ΪDay,��ÿ��0��ʱ�����һ���µ���־�ļ�
	//! \param eMode ��־�ļ��Ĵ洢��ʽ, ��������, ��֧�� Text��XML��ʽ
	//! \param bAppend [in] ���Ŀ����־�ļ��Ѿ����ڣ��Ƿ����ļ�β׷�����ݣ����Ǹ���ԭ�����ݡ�
	//! \remarks ��־�ļ������գ�"ǰ׺"+"_����id"+"_��ʼʱ���"�ķ�ʽ����
	//! \return �򿪳ɹ�����true,ʧ�ܷ���false
	UGbool Open(const UGString& strPath, const UGString& strPrefix="Log", 
			TimeInterval eTimeInterval=Day, Mode eMode=Text, UGbool bAppend=false);

	//! \brief �����ļ���С
	//! \param nFileSizeLimit ��־�ļ���С�޶�, ���������С�޶�, ����eSizeLimitMode������;
	//!							Ĭ��Ϊ-1, ���޶���С; ��λΪ �ֽ� 
	//! \param eSizeLimitMode ���nFileSizeLimit����0�Ĵ���ʽ
	//! \remarks Ŀǰֻ֧��Text��XMLģʽ
	void SetFileSizeLimit(UGint nFileSizeLimit, SizeLimitMode eSizeLimitMode=Rolling);
	//! \brief �õ��ļ�����
	UGint GetFileSizeLimit();
	//! \brief �õ��ļ�����
	SizeLimitMode GetSizeLimitMode();

	//! ���ݿ����������Դ �ͷ�֮ǰ, ��֪LogFileһ��
	void SetDataSourceNull(void *pDataSource);

	//! �ر��ļ�
	//! \param bDefaultSetting �Ƿ�Ѹ������ûָ�ΪĬ��ֵ, Ĭ��Ϊ�ָ�
	void Close(UGbool bDefaultSetting=true);									
	//! �ļ��Ƿ��
	UGbool IsOpen();									

	//! \brief �����Ƿ�洢����������У�������ʣ��������ļ���Ҳ���������ݿ�
	//! \param bSaveToPhysical�Ƿ񱣴浽���������, Ĭ��Ϊtrue; ���Ϊfalse,��ֻ��פ�����ڴ��е���־��Ϣ
	//! \remarks ���ϣ����־�ļ�������,����Openʱ,��Memoryģʽ; ��Memoryģʽ��,bSaveToPhysicalһ��Ϊfalse
	void SetSaveToPhysical(UGbool bSaveToPhysical);

	//! \brief ��־��Ϣ�Ƿ�洢�����������
	UGbool IsSaveToPhysical();

	//! \brief �����Ƿ�����ظ���־, ��������ѭ������ʱ,
	//!			������ͬ��־�����,�����Ч�ʵ�Ӱ��,�Լ������־�ɶ���
	//! \param bFilterRepeat �Ƿ�����ظ���־
	//! \remarks Ĭ��Ϊtrue, Ŀǰ������Ϊ: 
	//!			1)�����ǰ��־��Ϣ�����һ����־һģһ��,�Ƿ���˵�,�����¼
	//! 		2)�����������(��Ϊ100)��־��,���ĳ����־�ظ��������ɴ�(��Ϊ5),����˵�,�����¼
	void SetFilterRepeat(UGbool bFilterRepeat);

	//! \brief �Ƿ�����ظ���־
	UGbool IsFilterRepeat();

	
	//! ��־����
	LogLevelType GetLevel();
	void SetLevel(LogLevelType eLevel);

	
	//! \brief ��ѯ��־��Ϣ
	//! \remarks ��ѯ�Ľ�����µķ�����ǰ��,��queryResult[0]������д�����־,queryResult[size-1]������ϵ���־
	UGbool Query(const UGLogQueryDef& logQueryDef, UGLogItems& queryResult);

	//! \brief �������ɲ�ѯ��־��¼�ĸ���, Ĭ��Ϊ10240
	void SetQueryMaxNum(UGuint nQueryMaxNum);

	//! \brief �õ����ɲ�ѯ����־��¼����
	UGuint GetQueryMaxNum();

	//! \brief �õ�ָ��λ�õĿɲ�ѯ��Ϣ
	//! \remark �����ڲ�ʹ��, �ⲿһ����Query����
	//const UGLogItem& GetQueryItemAt(UGint nIndex);

	//! \brief ��տɲ�ѯ����־��Ϣ
	//! \remarks Ŀǰ��Ҫ���������ʹ��,�����ط�����ʹ��
	//void ClearQueryInfo();

	//! \brief ��ѯ����Ĵ洢
	//! \remarks Ŀǰֻ֧�ִ洢ΪText��XML��ʽ
	//!			 ���µ���־��Ϣ���ļ���ǰ��
	static UGbool SaveQueryResult(const UGLogItems& queryResult, const UGString& strFileName, Mode eMode);


	//! \brief ������־��Ϣ�ص�����
	static void SetCallBack(LogCallBack pCallBack);

	static void SetOpenCallBack(LogOpenCallBack pOpenCallBack);
	static void SetWriteCallBack(LogWriteCallBack pWriteCallBack);
	static void SetCloseCallBack(LogCloseCallBack pCloseCallBack);
	
	//! \brief ͨ��id�õ��ַ�����Ϣ������¼����־�ļ��С�
	//! \param eLevel ������Ϣ�Ĳ��[in]��
	//! \param nResID �ַ�����Դid[in]��
	//! \param strCodeFile ���ڴ����ļ���[in]��
	//! \param nLineNumber ���ڴ�����[in]��
	//! \attention ��Ҫֱ��ʹ��,�����UGDEBUG�Ⱥ��¼��־��Ϣ
	//! \return �ɹ�����true;ʧ�ܷ���false
	UGbool RecordLog(LogLevelType eLevel, UGint nResID, const UGString& strCodeFile, UGint nLineNumber);	

	//! \brief ���ַ�����Ϣ��¼����־�ļ��С�
	//! \param eLevel ������Ϣ�Ĳ��[in]��
	//! \param nResID �ַ�����Դid[in]��
	//! \param strMsg Ҫ��¼���ַ���[in]��
	//! \param strCodeFile ���ڴ����ļ���[in]��
	//! \param nLineNumber ���ڴ�����[in]��
	//! \attention ��Ҫֱ��ʹ��,�����UGDEBUG�Ⱥ��¼��־��Ϣ
	//! \return �ɹ�����true;ʧ�ܷ���false
	UGbool RecordLog(LogLevelType eLevel, UGint nResID, const UGString & strMsg, 
							const UGString& strCodeFile, UGint nLineNumber);
	
	
	//! �õ���������־��Ϣ�ĸ�ʽ��������Բο� DEF_LOG_FORMAT �Ķ���
	UGString GetLogFormat();
	void SetLogFormat(const UGString &strLogFormat);

	//! ����ʱ���ʽ,��ο�UGTime::Format
	UGString GetDateTimeFormat();
	void SetDateTimeFormat(const UGString &strDateTimeFormat);

	
	//! \brief ����Ϊ������¼����־��Ϣ, ʱ��,����,�̵߳�ͳͳ����¼
	//! \remarks ��Ҫ���ڲ����Ե�һЩ�������;
	void SetRecordOnlyLog();

	static UGString GetLevelAsString(LogLevelType eLevel);
	static LogLevelType GetLevelAsEnum(const UGString& strLogLevel);

	static Mode GetModeAsEnum(const UGString& strLogMode);
	static TimeInterval GetTimeIntervalAsEnum(const UGString& strTimeInterval);
	static SizeLimitMode GetSizeLimitModeAsEnum(const UGString& strSizeLimitMode);

private:
	const UGString &GetDirectory();					//��ȡ��־�ļ���·��
	void SetDirectory(const UGString &strDirectory);	//������־�ļ���·��
	
	UGString GetDefaultFileName();			//���ݵ�ǰʱ������Ĭ���ļ���
	
	// added by zengzm 2005.12.9 ����flush��������û��д���ļ�������д��
	//! \brief �����ݼ�ʱд�뵽�ļ���
	UGbool Flush();

	//! \brief �ָ���־�ļ��ĸ���Ĭ������
	//! \remarks ������־��ʽ����־���𣬻ص�����ָ�룬�Ƿ��¼����ʱ�䡢�߳�id��������Ϣ��
	void SetDefaultSetting();

	UGbool OpenText(const UGString& strFileName, UGbool bAppend);
	UGbool OpenXML(const UGString& strFileName, UGbool bAppend);

	//! ���� xml �ļ����׵� xslt�ļ�
	void CreateXslt(const UGString & strXsltName); 

	//! ���� xml �ļ����׵� xsd�ļ�
	void CreateXsd(const UGString & strXsdName); 

	void WriteText(const UGLogItem& logItem);
	void WriteXML(const UGLogItem& logItem);

	//! ��־Ϊ����ʱ����ļ��洢ʱ�Ĵ�����
	void DealTimeInterval();

	//! �ļ��ﵽԤ��SizeLimitʱ�Ĵ�����
	void DealFileSizeLimit();

	//! \brief �жϸ�����Ϣ�Ƿ������ظ���¼
	//! \param logItem Ҫ���жϵ���־��Ϣ
	//! \return ��������ظ���¼,����true;���򷵻�false
	UGbool IsFilterRepeat(const UGLogItem& logItem);
	
private:		
	UGString m_strFormat;			//��־��ʽ
	LogLevelType m_eLevel;			//��־�ļ�����
	Mode m_eMode;					//��־��¼��ģʽ���������ı���xml�����ݿ��
	UGString  m_strDirectory;		//��־�ļ���·��
	//! ��־���ļ�ȫ��. 
	//! \remarks ����Text��XMLģʽ,Ϊ��־�ļ���; ����Databaseģʽ,Ϊ���ݱ���; ����Memoryģʽ,Ϊ"Memory"
	UGString m_strFileName; 
	UGbool m_bIsOpen;				//�ļ��Ƿ��
	//! �ص���ָ��
	static LogCallBack ms_pCallBack;
	//! �����ݿ���д����־��Ϣ�Ļص�����ָ��
	static LogOpenCallBack ms_pOpenCallBack;
	static LogWriteCallBack ms_pWriteCallBack;
	static LogCloseCallBack ms_pCloseCallBack;

	UGFileStdio m_file;			//�ļ�ָ��, Text, XML �洢ʱʹ��

	UGbool m_bSaveToPhysical; // �Ƿ�洢�����������,Ĭ��Ϊtrue

	//! �Ƿ�����ظ���־, Ĭ��Ϊtrue
	UGbool m_bFilterRepeat;
	UGLogItem m_lastItem;
	
	//! SuperMap����Դָ��
	void * m_pDataSource;

	// ��m_strFileNameȡ��
	//! �洢��־�����ݱ�����,�����ݼ�����,Ĭ��ΪSmLog; 
	// UGString m_strTableName; 
	
	//! ��־��ʽ����
	UGString m_strLogFormat;

	//! ����ʱ�� ��ʽ����
	UGString m_strDateTimeFormat;

	//! ��־��Ϣ���ڴ��еĴ洢,�Ա��ѯʱʹ��
	UGContainer<UGLogItem> m_items;
//	UGLogItems 
//	//! ��ǰ��¼��λ��
//	UGuint m_nPos;
//	//! �Ƿ��Ѿ�ѭ����¼, ���ѭ��,���ѯʱҪ�� Pos����Ķ���������
//	UGbool m_bCycled;

	//! ������Ϣ���ڴ��еļ�¼, �Ա�������ʹ��
	UGContainer<UGErrorObj::ErrorInfo> m_errors;

	//! ���λ,��¼��ǰ��־��Ϣ,�Ƿ�������־�ļ����õĺ����з�����
	//! Ĭ��Ϊfalse, ������־�ļ�������,����Ϊtrue; ����ٽ�������־,�ͱ�Ҫ��¼,����ݹ���ѭ��
	//! Ŀǰ��Ҫ�ڴ洢�����ݿ���ʱʹ��,��Ϊ�洢Ϊ������ʽʱ,�����õ��಻����д��־
	UGbool m_bIntoLogFile;
	
	//! ����ʱ����ļ��洢,Ĭ��ΪNoTime
	TimeInterval m_eTimeInterval;
	//! ���ļ��洢��С�޶�, Ĭ��Ϊ-1,���޶���С
	UGint m_nSizeLimit;
	//! ���ļ��洢ģʽ,Ĭ��ΪRolling,�ع�
	SizeLimitMode m_eSizeLimitMode;

	//! �ļ���ǰ׺,Ĭ��ΪLog
	UGString m_strPrefix;
	//! ��¼������������־�ļ�ʱ��ʱ��
	UGTime m_time;
	//! ���ļ��洢ʱ���ļ����
	UGint m_nFileNum;

	//! �����ʱ���¼(��ȷ������), �������� %TIMESPAN ��
	UGint m_nLastMillisecond;

	//! �����������־��,��ͬ��־(ͨ��hashCodeʶ��)������;���������ظ���־����
	UGDict<UGint, UGint> m_infoCount; 

	//! ��¼�����������־��HashCode;��m_infoCount���ʹ��,���������ظ���־����
	//! \remarks ��ʱ��ֱ��ʹ��stl��queue,�Ժ���UGC�з�װһ����
	std::queue<UGint> m_hashCodes;

	//! ��֤���̰߳�ȫ
	UGMutex m_mutex;
};

//! ��־��ѯ����
class BASE_API UGLogQueryDef  
{
public:
	//! ��ѯ������
	enum Type	
	{
		//! ��־�����ѯ
		Level = 100,
		//! ����ʱ���ѯ
		DateTime = 200,
		//! ʱ������ѯ
		TimeSpan = 300,
		//! ��־������Ϣ��ѯ
		Description = 400,
		//! ��־��������Դ�ַ���ID��ѯ
		ResID = 500,
		//! ��־�������߳�ID��ѯ
		ThreadID = 600,
	};
	//! ��ѯ�߼����ż�¼, ֧�� > < = >= <= != ������ʽ
	UGString m_strOperator;
	//1 ��ѯ����
	Type m_eType;
	// ��ѯ�߼������ұߵ��ַ�����¼
	//UGString m_strRight;
	//! ��ѯ����־����,�� Level��ѯʱʹ��
	UGLogFile::LogLevelType m_eLevel; 
	//! ��ѯ������ʱ��,�� DateTime ��ѯʱʹ��
	UGTime m_time;
	//! ��ѯ��ʱ����,�� TimeSpan ��ѯʱʹ��; ע�ⵥλΪ����
	UGint m_nTimeSpan;
	//! ��ѯ��������Ϣ,�� Description ��ѯʱʹ��
	UGString m_strDescription;
	//! ��ѯ���߳�id��Ϣ,�� ThreadID ��ѯʱʹ��
	UGuint m_nThreadID;
	//! ��ѯ����Դ�ַ���id��Ϣ,�� ResID ��ѯʱʹ��
	UGuint m_nResID;
    
	UGLogQueryDef()
	{
		m_eType = ResID; // Ĭ��Ϊ ��ԴID��ѯ
		m_eLevel = UGLogFile::Error;
		m_nThreadID = m_nResID = m_nTimeSpan = 0;
	}
};

}
#endif // !defined(UGLOGFILE)

// InstallDlg.h : ͷ�ļ�
//

#pragma once
//#include "afxcmn.h"


// CInstallDlg �Ի���
class CInstallDlg : public CDialog
{
// ����
public:
	CInstallDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_INSTALL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

public:
	CComboBox m_ComboInstallPath;
	CString m_strInstallPath;
	void ShowInfo(CString info);
public:
	void Localize(void);
public:
	void InstallProvider(void);
	void UninstallProvider(void);

private:
	void RegisterJob(CString strFullFileName, int nOpCode);
};

#pragma once
#include "afxwin.h"


// CIdentifyCodeDlg �Ի���

class CIdentifyCodeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CIdentifyCodeDlg)

public:
	CIdentifyCodeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CIdentifyCodeDlg();

// �Ի�������
	enum { IDD = IDD_IDENTIFYCODEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit mCode;
	CImage mImage;
	virtual BOOL OnInitDialog();
	CStatic mCodePic;
	CString *pRetCString;
public:
	void SetImgStream(unsigned char *dst,unsigned int size);
	void SetRetCode(CString *str){pRetCString=str;};
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
	afx_msg void OnStnClickedCode();
};

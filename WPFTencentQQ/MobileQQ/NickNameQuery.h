#pragma once
#include"resource.h"
#include"../CCodecWarpper/ConfigData.h"
#include "afxwin.h"


// CNickNameQuery �Ի���

class CNickNameQuery : public CDialogEx
{
	DECLARE_DYNAMIC(CNickNameQuery)

public:
	CNickNameQuery(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNickNameQuery();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg LRESULT OnReceivedMsg(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()
public:
	CConfigData *pConfig;
	afx_msg void OnBnClickedButton1();
	// �ı������
	CEdit mEditPhoneNos;
};

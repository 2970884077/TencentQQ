#pragma once
#include"resource.h"
#include"../CCodecWarpper/ConfigData.h"
#include "mylistctrl.h"

// CCNearByDlg �Ի���

class CCNearByDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCNearByDlg)

public:
	CCNearByDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCNearByDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CConfigData *pConfig;
	MyListCtrl mList1;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};

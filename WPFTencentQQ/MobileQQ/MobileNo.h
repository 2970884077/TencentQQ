#pragma once
#include"resource.h"
#include"../CCodecWarpper/ConfigData.h"
#include "afxwin.h"
#include"SeqSerial.h"
#include"../CCodecWarpper/RequestBindMobile.h"

// CMobileNo �Ի���

class CMobileNo : public CDialogEx
{
	DECLARE_DYNAMIC(CMobileNo)

public:
	CMobileNo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMobileNo();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg LRESULT OnReceivedMsg(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
public:
	CConfigData *pConfig;
	CSeqSerial mSeqSerial;
	int m_Radio;
	BindMobile mBindMobile;
public:
	 afx_msg void OnBnClickedRadio1();
	 afx_msg void OnBnClickedRadio2();
	 afx_msg void OnBnClickedRadio4();
	 virtual BOOL OnInitDialog();
	 afx_msg void On32795();
	 afx_msg void On32796();
	 // �ı����������
	 CEdit ctrPhoneNos;
	 afx_msg void OnBnClickedButton5();
	 afx_msg void OnBnClickedButton6();
	 CEdit mOutPutEdit;
	 void OutputEdit(CString str);
	 CEdit mStartEdt;
	 CEdit mEndEdt;
};

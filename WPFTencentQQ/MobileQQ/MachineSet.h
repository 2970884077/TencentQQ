#pragma once
#include"resource.h"
#include"../CCodecWarpper/ConfigData.h"
#include"../UtilLib/SimpleIni.h"
#include"MyLog.h"
#include "afxwin.h"


// CMachineSet �Ի���

class CMachineSet : public CDialogEx
{
	DECLARE_DYNAMIC(CMachineSet)

public:
	CMachineSet(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMachineSet();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnCbnSelchangeCombo1();
	virtual BOOL OnInitDialog();
public:
	BOOL InitMachineSetting();
private:
	//ini������
	CSimpleIniA mSimpleIniA;
public:
	CConfigData *pConfig;
	CComboBox mSetsName;
	CEdit ctlDeviceName;
	CEdit ctlSon;
	CEdit ctlOstype;
	CEdit ctlOsVersion;
	CEdit ctlApn;
	CEdit ctlBrand;
	CEdit ctlMac;
	CEdit ctlAndroidId;
	CEdit ctlImei;
	CEdit ctlImsi;
	CEdit ctlBSSID;
	CEdit ctlSSID;
	CEdit ctlDeviceId;
	int m_radiobtngroup1;
	afx_msg void OnBnClickedRadio1();
	int m_radiobtngroup2;
	afx_msg void OnBnClickedRadio2();
};

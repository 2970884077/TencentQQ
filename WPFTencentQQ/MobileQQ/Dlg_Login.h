#pragma once
#include "afxwin.h"
#include"GlobeVar.h"
#include"../CCodecWarpper/ConfigData.h"
#include"../CCodecWarpper/CommonUnPack.h"
#include"../UtilLib/SimpleIni.h"
#include"SeqSerial.h"


// Dlg_Login �Ի���

class Dlg_Login : public CDialogEx
{
	DECLARE_DYNAMIC(Dlg_Login)

public:
	Dlg_Login(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dlg_Login();

// �Ի�������
	enum { IDD = IDD_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
public:
	//ini������
	CSimpleIniA mSimpleIniA;
	// �û��˻�
	CString m_Account;
	// �û�����
	CString m_Password;
	// ������ʾ��½������Ϣ
	CListBox m_List;
	CConfigData *pConfig;
	CCriticalSection m_ReceiveMsgLock;
	//���ݰ����
	CSeqSerial mSeqSerial;
private://iocp param
	int		m_iMaxNumberOfConnections;
	int		m_iMaxNrOfFreeBuff;
	int		m_iMaxNrOfFreeContext;
	int		m_iNrOfIOWorkers;
	int		m_iNrOfLogicalWorkers;
	int		m_iPortNr;
	BOOL	m_bReadInOrder;
	BOOL	m_iSendInOrder;
	int		m_iNrOfPendlingReads;
public:
	void SetIocpParam(int,int,int,int,int,int,BOOL,BOOL,int);
private:
	//�յ����ݰ��ļ�¼
	void RecvPacketRecords(CCommonUnPack*);
protected:
	afx_msg LRESULT OnReceivedMsg(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnClose();
};

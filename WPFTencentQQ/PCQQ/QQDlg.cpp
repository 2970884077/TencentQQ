
// QQDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "QQ.h"
#include "QQDlg.h"
#include "afxdialogex.h"
#include"Dlg_Login.h"
#include"UserMsg.h"
#include"..\Packet\CommReq.h"
#include"..\Packet\CommonUnPack.h"
#include"..\Packet\CommHead.h"
#include "../UtilLib/err_code.h"
#include"UserMsg.h"
#include"MyLog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// COffineQQDlg �Ի���


COffineQQDlg::COffineQQDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COffineQQDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COffineQQDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, mStatic1);
	DDX_Control(pDX, IDC_LIST1, mList1);
	DDX_Control(pDX, IDC_STATIC2, mStatic2);
	DDX_Control(pDX, IDC_STATIC3, mStatic3);
	DDX_Control(pDX, IDC_LIST2, mList2);
	DDX_Control(pDX, IDC_LIST3, mList3);
	DDX_Control(pDX, IDC_STATIC4, mStatic4);
	DDX_Control(pDX, IDC_STATIC5, mStatic5);
	DDX_Control(pDX, IDC_TREE1, mTreeCtrl);
}

BEGIN_MESSAGE_MAP(COffineQQDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32771, &COffineQQDlg::OnLogin)
	ON_MESSAGE(WM_RECEIVED_MSG, &COffineQQDlg::OnReceivedMsg)
	ON_MESSAGE(WM_TRANSMIT_MSG, &COffineQQDlg::OnTransmitMsg)
	ON_COMMAND(ID_32772, &COffineQQDlg::OnOffineLine)
	ON_COMMAND(ID_32779, &COffineQQDlg::On32779)
	ON_COMMAND(ID_32780, &COffineQQDlg::On32780)
	ON_COMMAND(ID_32781, &COffineQQDlg::On32781)
	ON_COMMAND(ID_32782, &COffineQQDlg::On32782)
	ON_COMMAND(ID_32784, &COffineQQDlg::On32784)
	ON_COMMAND(ID_32783, &COffineQQDlg::On32783)
	ON_MESSAGE(WM_LOGINSUCCESSED, &COffineQQDlg::OnLoginsuccessed)
	ON_WM_CLOSE()
	ON_MESSAGE(WM_TRAY_NOTIFICATION, &COffineQQDlg::OnTrayNotification)
	ON_COMMAND(ID_32793, &COffineQQDlg::On32793)
END_MESSAGE_MAP()


// COffineQQDlg ��Ϣ�������

BOOL COffineQQDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

		//���ñ��������ַ���
	_wsetlocale(LC_ALL,L"chs");

	//��װ�쳣��
	if(!this->SetDumpFunc())
	{
		//���öԻ�����־
		return FALSE;
	}
	StatusLogText("COffineQQDlg �쳣��������ϡ�����");
	if(!this->SetDlgUI())
	{
		//���öԻ�����־
		return FALSE;
	}
	StatusLogText("COffineQQDlg �Ի���������ϡ�����");
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void COffineQQDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void COffineQQDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR COffineQQDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//��������Dump�߳�
BOOL COffineQQDlg::SetDumpFunc(void)
{
	SetUnhandledExceptionFilter(GPTUnhandledExceptionFilter);

	g_DumpThread=CreateThread(NULL,0,ThreadProc,NULL,CREATE_SUSPENDED,NULL);
	if(g_DumpThread==NULL)
	{
		return FALSE;
	}
	return TRUE;
}

//�����������Ի����UI
BOOL COffineQQDlg::SetDlgUI(void)
{
	//��ʼ��MainFrame UI����
	int x=0,y=0,height=0,width=0;
	height=m_Ini.GetIntKey("configure.ini","MainFrame","height");
	width=m_Ini.GetIntKey("configure.ini","MainFrame","width");
	RECT rect={0};
	this->GetWindowRect(&rect);
	this->MoveWindow(rect.left,rect.top,width,height,TRUE);

	//�����б�
	x=m_Ini.GetIntKey("configure.ini","mStatic4","x");
	y=m_Ini.GetIntKey("configure.ini","mStatic4","y");
	height=m_Ini.GetIntKey("configure.ini","mStatic4","height");
	width=m_Ini.GetIntKey("configure.ini","mStatic4","width");
	mStatic4.MoveWindow(x,y,width,height);

	x=m_Ini.GetIntKey("configure.ini","mTreeCtrl","x");
	y=m_Ini.GetIntKey("configure.ini","mTreeCtrl","y");
	height=m_Ini.GetIntKey("configure.ini","mTreeCtrl","height");
	width=m_Ini.GetIntKey("configure.ini","mTreeCtrl","width");
	mTreeCtrl.MoveWindow(x,y,width,height);

	mTreeCtrl.SetItemHeight(26);
	mTreeCtrl.SetImageList();
	mTreeCtrl.SetStyle(TVS_HASBUTTONS,0);	
	
	//��Ϣ�б�
	x=m_Ini.GetIntKey("configure.ini","mStatic1","x");
	y=m_Ini.GetIntKey("configure.ini","mStatic1","y");
	height=m_Ini.GetIntKey("configure.ini","mStatic1","height");
	width=m_Ini.GetIntKey("configure.ini","mStatic1","width");
	mStatic1.MoveWindow(x,y,width,height);

	x=m_Ini.GetIntKey("configure.ini","mList1","x");
	y=m_Ini.GetIntKey("configure.ini","mList1","y");
	height=m_Ini.GetIntKey("configure.ini","mList1","height");
	width=m_Ini.GetIntKey("configure.ini","mList1","width");
	mList1.MoveWindow(x,y,width,height);

	//������Ϣ
	x=m_Ini.GetIntKey("configure.ini","mStatic2","x");
	y=m_Ini.GetIntKey("configure.ini","mStatic2","y");
	height=m_Ini.GetIntKey("configure.ini","mStatic2","height");
	width=m_Ini.GetIntKey("configure.ini","mStatic2","width");
	mStatic2.MoveWindow(x,y,width,height);

	x=m_Ini.GetIntKey("configure.ini","mList2","x");
	y=m_Ini.GetIntKey("configure.ini","mList2","y");
	height=m_Ini.GetIntKey("configure.ini","mList2","height");
	width=m_Ini.GetIntKey("configure.ini","mList2","width");
	mList2.MoveWindow(x,y,width,height);
	this->mList2.Clear();
	char  _column2[][20]={"���","���ͷ�","����ʱ��","��Ϣ����"};
	this->mList2.SetHeaders(_column2,sizeof(_column2)/sizeof(*_column2));

	//Ⱥ����Ϣ
	x=m_Ini.GetIntKey("configure.ini","mStatic3","x");
	y=m_Ini.GetIntKey("configure.ini","mStatic3","y");
	height=m_Ini.GetIntKey("configure.ini","mStatic3","height");
	width=m_Ini.GetIntKey("configure.ini","mStatic3","width");
	mStatic3.MoveWindow(x,y,width,height);

	x=m_Ini.GetIntKey("configure.ini","mList3","x");
	y=m_Ini.GetIntKey("configure.ini","mList3","y");
	height=m_Ini.GetIntKey("configure.ini","mList3","height");
	width=m_Ini.GetIntKey("configure.ini","mList3","width");
	mList3.MoveWindow(x,y,width,height);
	this->mList3.Clear();
	char  _column3[][20]={"���","Ⱥ��","���ͷ�","����ʱ��","��Ϣ����"};
	this->mList3.SetHeaders(_column3,sizeof(_column3)/sizeof(*_column3));

	//������Ϣ
	x=m_Ini.GetIntKey("configure.ini","mStatic5","x");
	y=m_Ini.GetIntKey("configure.ini","mStatic5","y");
	height=m_Ini.GetIntKey("configure.ini","mStatic5","height");
	width=m_Ini.GetIntKey("configure.ini","mStatic5","width");
	mStatic5.MoveWindow(x,y,width,height);

	//����״̬��
	this->m_Status.Create(WS_CHILD|WS_VISIBLE|CCS_BOTTOM,CRect(0,0,0,0), this, IDC_STATUSBARCTRL);
	this->m_Status.SetUI();

	//����Ĭ��״̬
	this->m_Send=0;
	this->m_Recv=0;
	this->m_Abandon=0;
	this->m_Status.Updata(m_Send,m_Recv,m_Abandon);
	this->m_Status.SetProcessBar(0);
	
	this->SetUinStatus(BeOffine); //����״̬
	return TRUE;
}

void COffineQQDlg::OnLogin()
{
	if(Config.mStatus!=BeOffine)
	{
		AfxMessageBox("����ע���ѵ�¼�˺�");
		return;
	}
	Dlg_Login login_dlg;
	login_dlg.pConfig=&Config;
	login_dlg.DoModal();
}

afx_msg LRESULT COffineQQDlg::OnReceivedMsg(WPARAM wParam, LPARAM lParam)
{
	switch(wParam)
	{
	case 1:
		{
			//��������
			break;
		}break;
	case 2:
		{
			//�ͻ��˶Ͽ�
			unsigned int* piID = reinterpret_cast<unsigned int*>(lParam);
			mList1.AddString("�ͻ��˶Ͽ��ɹ�");
			delete piID;
			return 0;
		}break;
	default:
		{
			Error_Check(ERR_COMMON);
			return 0;
		}break;
	}

	//��������ָ��+1
	AddRecv();

	ByteBuffer *pRecv=(ByteBuffer*)(lParam);
	CCommonUnPack *packet= new CCommonUnPack();
	packet->Wrapping(*pRecv);
	packet->pConfig=&Config;
	delete pRecv;
	pRecv=NULL;
	unsigned int ret=packet->UnPackData();

	//��¼�յ����ݰ�(����ǰ)
	RecvPacketRecords(packet);

	//�鿴���ݰ��Ƿ���Ҫ����
	if(ret==ERR_PACKET_ABANDON)
	{
		//��������ָ��+1
		AddAbandon();
		return 0;
	}
	Error_Check(ret);

	//��������
	switch(packet->GetPackType())
	{
		case TypeFFFF:
			{
				//��������
				Error_Check(packet->Analysis());
				mList1.AddString("�յ�0xFFFFδ֪��Ϣ");
			}break;
		case Type001D:
			{
				Error_Check(packet->Analysis());
				mList1.AddString("001D��Ϣ");
			}break;
		case Type01BB:
			{
				//��������
				Error_Check(packet->Analysis());
				mList1.AddString("01BB��Ϣ");
			}break;
		case Type0134:
			{
				//��������
				Error_Check(packet->Analysis(&mFolderList));
				mList1.AddString("0134��Ϣ");

				//����0002���ݰ�
				if(mFolderList.mList2.size()!=0)
				{
					for(int i=0;i<mFolderList.mList2.size();i++)
					{
						CCommReq *p=new CCommReq();
						p->pAttach=&mFolderList.mList2[i].dwClusterId;
						p->SetPacketType(Type0002);
						p->pConfig=&Config;
						p->PackData();
						DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
						delete p;p=NULL;
					}
				}

			}break;
		case Type0002:
			{
				//��������
				Error_Check(packet->Analysis());
				mList1.AddString("0002��Ϣ");
			}break;
		case Type00EC:
			{
				//��������
				Error_Check(packet->Analysis());
				mList1.AddString("00EC��Ϣ");

				//������2��00B9δ֪��Ϣ�����޷����쳣��
				//p=new CCommReq();
				//p->SetPacketType(CODE_00B901);
				//p->pConfig=&Config;
				//p->PackData();
				//DlgSend(ClientID,p->pack);
				//delete p;p=NULL;

				//p=new CCommReq();
				//p->SetPacketType(CODE_00B902);
				//p->pConfig=&Config;
				//p->PackData();
				//DlgSend(ClientID,p->pack);
				//delete p;p=NULL;

				//00D1��Ϣ���޷����쳣��
				CCommReq *p=new CCommReq();
				p->SetPacketType(Type00D1);
				p->pConfig=&Config;
				p->PackData();
				DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
				delete p;p=NULL;

				/****001Dϵ����Ϣ********/
				//p=new CCommReq();
				//p->SetPacketType(CODE_001D03);
				//p->pConfig=&Config;
				//p->PackData();
				//DlgSend(ClientID,p->pack);
				//delete p;p=NULL;

				p=new CCommReq();
				p->SetPacketType(Type001D);
				p->pConfig=&Config;
				p->PackData();
				DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
				delete p;p=NULL;

				p=new CCommReq();
				p->SetPacketType(Type001D);
				p->pConfig=&Config;
				p->PackData();
				DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
				delete p;p=NULL;

				p=new CCommReq();
				p->SetPacketType(Type001D);
				p->pConfig=&Config;
				p->PackData();
				DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
				delete p;p=NULL;

				//p=new CCommReq();
				//p->SetPacketType(CODE_001D07);
				//p->pConfig=&Config;
				//p->PackData();
				//DlgSend(ClientID,p->pack);
				//delete p;p=NULL;

				p=new CCommReq();
				p->SetPacketType(Type001D);
				p->pConfig=&Config;
				p->PackData();
				DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
				delete p;p=NULL;

				p=new CCommReq();
				p->SetPacketType(Type001D);
				p->pConfig=&Config;
				p->PackData();
				DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
				delete p;p=NULL;
				/****001Dϵ����Ϣ********/

				//0001���ѷ�����Ϣ
				p=new CCommReq();
				p->SetPacketType(Type0001);
				p->pConfig=&Config;
				p->PackData();
				DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
				delete p;p=NULL;

				//0195��Ϣ
				p=new CCommReq();
				p->SetPacketType(Type0195);
				p->pConfig=&Config;
				p->PackData();
				DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
				delete p;p=NULL;

			}break;
		case Type00B9:
			{
				//��������
				Error_Check(packet->Analysis());
				mList1.AddString("00B9��Ϣ");
			}break;
		case Type00D1:
			{
				//��������
				Error_Check(packet->Analysis());
				mList1.AddString("00D1��Ϣ");
			}break;
		case Type0001:
			{
				//��������
				Error_Check(packet->Analysis(&mFolderList));
				mList1.AddString("0001���ѷ�����Ϣ");

				//0027��Ϣ
				CCommReq *p=new CCommReq();
				p->SetPacketType(Type0027);
				p->pConfig=&Config;
				p->PackData();
				DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
				delete p;p=NULL;

				//019b��Ϣ
				p=new CCommReq();
				p->SetPacketType(Type019B);
				p->pConfig=&Config;
				p->PackData();
				DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
				delete p;p=NULL;

				//01A5��Ϣ
				p=new CCommReq();
				p->SetPacketType(Type01A5);
				p->pConfig=&Config;
				p->PackData();
				DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
				delete p;p=NULL;

				//0362δ֪��Ϣ
				//0371δ֪��Ϣ

				//01AE��Ϣ
				p=new CCommReq();
				p->SetPacketType(Type01AE);
				p->pConfig=&Config;
				p->PackData();
				DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
				delete p;p=NULL;

				//07FF��Ϣ
				p=new CCommReq();
				p->SetPacketType(Type07FF);
				p->pConfig=&Config;
				p->PackData();
				DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
				delete p;p=NULL;

				//00D4��Ϣ
				p=new CCommReq();
				p->SetPacketType(Type00D4);
				p->pConfig=&Config;
				p->PackData();
				DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
				delete p;p=NULL;

				p=new CCommReq();
				p->SetPacketType(Type00D4);
				p->pConfig=&Config;
				p->PackData();
				DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
				delete p;p=NULL;

				p=new CCommReq();
				p->SetPacketType(Type00D4);
				p->pConfig=&Config;
				p->PackData();
				DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
				delete p;p=NULL;

				//005Cȡ������
				p=new CCommReq();
				p->SetPacketType(Type005C);
				p->pConfig=&Config;
				p->PackData();
				DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
				delete p;p=NULL;

				//003E��ȡ��ע
				p=new CCommReq();
				p->SetPacketType(Type003E);
				p->pConfig=&Config;
				p->PackData();
				DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
				delete p;p=NULL;

				//GetCookie����
				//���������߳�
				if(!this->SetHeartPacket())
				{
					Error_Check(ERR_COMMON);
				}

			}break;
		case Type0058:
			{
				//��������
				Error_Check(packet->Analysis());
				mList1.AddString("0058��������");
			}break;
		case Type00CE:
			{
				//��������
				TextMsg msg;
				Error_Check(packet->Analysis(&msg));
				InsertRecvMsg(msg);
				mList1.AddString("00CE������Ϣ");
			}break;
		case Type0017:
			{
				//��������
				Error_Check(packet->Analysis());
				mList1.AddString("0017Ⱥ��Ϣ");
			}break;
		case Type0027:
			{
				//���������б�
				Error_Check(packet->Analysis(&mFolderList));
				//���������ݼ���
				InitFriendsList(mFolderList);
				mList1.AddString("0027��Ϣ");
			}break;
		case Type0195:
			{
				//��������
				Error_Check(packet->Analysis());
				mList1.AddString("0195��Ϣ");
			}break;
		case Type019B:
			{
				//��������
				Error_Check(packet->Analysis());
				mList1.AddString("019B��Ϣ");
			}break;
		case Type01A5:
			{
				//��������
				Error_Check(packet->Analysis());
				mList1.AddString("01A5��Ϣ");
			}break;
		case Type01AE:
			{
				//��������
				Error_Check(packet->Analysis());
				mList1.AddString("01AE��Ϣ");
			}break;
		case Type07FF:
			{
				Error_Check(packet->Analysis());
				mList1.AddString("07FF��Ϣ");
			}break;
		case Type00D4:
			{
				Error_Check(packet->Analysis());
				mList1.AddString("00D4��Ϣ");
			}break;
		case Type005C:
			{
				Error_Check(packet->Analysis());
				mList1.AddString("005C��Ϣ");
			}break;
		case Type003E:
			{
				Error_Check(packet->Analysis());
				mList1.AddString("003E��Ϣ");
			}break;
		case Type000D:
			{
				//��������
				Error_Check(packet->Analysis());
				mList1.AddString("000D��Ϣ");
			}break;
		case Type00CD:
			{
				Error_Check(packet->Analysis());
				mList1.AddString("00CD��Ϣ");
			}break;
		default:
			{
				Error_Check(packet->Analysis());
			}break;
	}
	delete packet;packet=NULL;
	return 0;
}

afx_msg LRESULT COffineQQDlg::OnTransmitMsg(WPARAM wParam, LPARAM lParam)
{
	ActionCommand *pAction=(ActionCommand*)wParam;
	switch(pAction->sCmd)
	{
	case ACTION_SEND_MSG:
		{
			CString str;
			str.Format("������Ϣ->%d",pAction->sSubCmd);
			mList1.AddString(str);

			//CCommReq* p=new CCommReq();
			//p->SetPacketType(CODE_00CD01);
			//p->pConfig=&Config;
			//p->PackData();
			//DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
			//delete p;p=NULL;
		}break;
	case ACTION_QUERY_USERDATA:
		{
			CString str;
			str.Format("��ѯ����->%d",pAction->sSubCmd);
			mList1.AddString(str);
		}break;
	default:
		{
			//AppendLog("COffineQQDlg::OnTransmitMsg error");
		}break;
	}

	return 0;
}

void COffineQQDlg::InitFriendsList(FolderList& mFriends)
{
	//�ȳ�ʼ�����ѷ���
	for (int i =0; i < mFriends.mList1.size(); i ++) 
	{
		CString strSet;
		strSet.Format("%s",mFriends.mList1[i].strClusterName.c_str());
		HTREEITEM Root=mTreeCtrl.InsertItem(strSet.GetBuffer(0),-1,-1);
		//���غ���
		for(int j=0;j<mFriends.mList1[i].Friends.size();j++)
		{
			CString strFriend;
			strFriend.Format("%d",mFriends.mList1[i].Friends[j].dwUin);
			mTreeCtrl.InsertItem(strFriend,Root,TVI_LAST);
		}

	//		//���ڵ�
	//HTREEITEM Root=mTreeCtrl.InsertItem(TEXT("gym��Ϸ����"),0,0,TVI_ROOT,TVI_LAST);

	////mTreeCtrl.SetItemImage(Root,0,1);

	////��������Ϸ
	//HTREEITEM GameItem1=mTreeCtrl.InsertItem(TEXT("������"),7,6,Root,TVI_LAST);
	//
	//	HTREEITEM Room_Item1_1=mTreeCtrl.InsertItem(TEXT("��ͨվ��"),8,6,GameItem1,TVI_LAST);
	//		HTREEITEM Room_Item1_1_1=mTreeCtrl.InsertItem(TEXT("������"),9,6,Room_Item1_1,TVI_LAST);
	//		HTREEITEM Room_Item1_1_2=mTreeCtrl.InsertItem(TEXT("�߼���"),9,6,Room_Item1_1,TVI_LAST);
	//		HTREEITEM Room_Item1_1_3=mTreeCtrl.InsertItem(TEXT("VIP��"),9,6,Room_Item1_1,TVI_LAST);
	//
	//
	//	HTREEITEM Room_Item1_2=mTreeCtrl.InsertItem(TEXT("����վ��"),8,6,GameItem1,TVI_LAST);
	//		HTREEITEM Room_Item1_2_1=mTreeCtrl.InsertItem(TEXT("û�к��ʵķ���"),9,6,Room_Item1_2,TVI_LAST);

	//	HTREEITEM Room_Item1_3=mTreeCtrl.InsertItem(TEXT("����վ��"),8,6,GameItem1,TVI_LAST);
	//		HTREEITEM Room_Item1_3_1=mTreeCtrl.InsertItem(TEXT("û�к��ʵķ���"),9,6,Room_Item1_3,TVI_LAST);


	////����������Ϸ
	//HTREEITEM GameItem2=mTreeCtrl.InsertItem(TEXT("��������"),7,6,Root,TVI_LAST);

	//	HTREEITEM Room_Item2_1=mTreeCtrl.InsertItem(TEXT("û�к��ʵ�վ��"),8,6,GameItem2,TVI_LAST);

	////�����ƾ���Ϸ
	//HTREEITEM GameItem3=mTreeCtrl.InsertItem(TEXT("�����ƾ�"),7,6,Root,TVI_LAST);

	//	HTREEITEM Room_Item3_1=mTreeCtrl.InsertItem(TEXT("û�к��ʵ�վ��"),8,6,GameItem3,TVI_LAST);

	////չ�����нڵ�
	////ExpandAllItem(&m_TreeCtrl,m_TreeCtrl.GetRootItem());

	}
}

void COffineQQDlg::RecvPacketRecords(CCommonUnPack* p)
{
	CString type;
	switch(p->GetPackType())
	{
		case TypeFFFF:
			{
				type.Format("0x%04x ����������δ֪��Ϣ",static_cast<CCommHeadResp*>(p->pHead)->Hda.code);
			}break;
		default:
			{
				type.Format("0x%04x��Ϣ",p->GetPackType());
			}break;
	}
	DataLogBytes(type,(unsigned char*)p->pack.contents(),p->pack.size());
}

void COffineQQDlg::InsertRecvMsg(TextMsg msg)
{
	int num=mList2.GetItemCount();
	CString size;
	size.Format("%d",num+1);
	mList2.InsertItem(num,size);
	CString Uin;
	Uin.Format("%d",msg.Uin);
	mList2.SetItemText(num,1,Uin);
	CString time;
	time.Format("%d",msg.Time);
	mList2.SetItemText(num,2,time);
	CString strContent;
	strContent.Format("%s",msg.MsgContent.c_str());
	mList2.SetItemText(num,3,strContent);
}

void COffineQQDlg::InitSendPacket()
{
	//���õ�ǰ��Ϣ֪ͨ����
	ChangeNotifyWnd(m_hWnd,WM_RECEIVED_MSG);
	//��ʼ��������һϵ��������Ϣ
	unsigned short mType=0;
	CCommReq *p=new CCommReq();
	mType=1;
	p->pAttach=&mType;
	p->SetPacketType(Type001D);		//0x12
	p->pConfig=&Config;
	p->PackData();
	DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
	delete p;p=NULL;
	
	p=new CCommReq();
	mType=2;
	p->pAttach=&mType;
	p->SetPacketType(Type001D);		//0x26
	p->pConfig=&Config;
	p->PackData();
	DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
	delete p;p=NULL;

	//����01BB��Ϣ
	p=new CCommReq();
	mType=1;
	p->pAttach=&mType;
	p->SetPacketType(Type01BB);
	p->pConfig=&Config;
	p->PackData();
	DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
	delete p;p=NULL;

	p=new CCommReq();
	mType=2;
	p->pAttach=&mType;
	p->SetPacketType(Type01BB);
	p->pConfig=&Config;
	p->PackData();
	DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
	delete p;p=NULL;
	
	//����0134��Ϣ
	p=new CCommReq();
	p->SetPacketType(Type0134);
	p->pConfig=&Config;
	p->PackData();
	DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
	delete p;p=NULL;

	/******�����ݰ���������**********/
	p=new CCommReq();
	p->SetPacketType(Type00EC);
	p->pConfig=&Config;
	p->PackData();
	DlgSend(p->pConfig->m_iCurrentClientID,p->pack);
	delete p;p=NULL;
	/******�����ݰ���������**********/

	//������Ϣ�Ѳ�������


	//019B��Ϣ��01 00 00 00 00 01 00 00��
	//01A5��Ϣ(01 00 00 00 18 01 00 00 )
	//0362δ֪��Ϣ
	//0126(�����ϵ�б�)
	//003C���ݰ�����Ϊ������ĳ����Ϣ֮������
	//0067����Ϊ���ظ���ǩ��
	//005C����Ϊ������ĳ�˿�ͨ��ҵ����VIP�ȵ�
	//0002���ܷ�����Ⱥ�����Ϣ(������������)
	//0027�����б�
}

BOOL COffineQQDlg::SetHeartPacket()
{
	LARGE_INTEGER li;
	li.QuadPart = 0;
	gHeartThread[0]=CreateWaitableTimer(NULL, FALSE, NULL);
	SetWaitableTimer(gHeartThread[0], &li, 60*1000, NULL, NULL, FALSE);

	gHeartThread[1]=CreateEvent(NULL, TRUE, FALSE, NULL); //��ʼ��ΪFALSE���˹������¼������ڽ����߳�

	//�����ֹ���̵߳�����
	HANDLE Thread=CreateThread(NULL,0,HeartThreadProc,this,0,NULL);
	if(Thread==NULL)
	{
		return FALSE;
	}
	return TRUE;
}

DWORD _stdcall COffineQQDlg::HeartThreadProc( LPVOID lpParam )
{
	COffineQQDlg *pThis=static_cast<COffineQQDlg*>(lpParam);

	CCommReq p;
	p.SetPacketType(Type0058);
	p.pConfig=&pThis->Config;
	p.PackData();
	bool isLiving=true;
	while(isLiving)
	{
		DWORD dw=WaitForMultipleObjects(2,pThis->gHeartThread,FALSE,INFINITE);
		switch(dw)
		{
			case WAIT_FAILED:
				break;
			case WAIT_TIMEOUT:
				break;
			case WAIT_OBJECT_0 + 0:
				{
					pThis->DlgSend(p.pConfig->m_iCurrentClientID,p.pack);
					pThis->mList1.AddString("�����������ݰ�");
				}break;
			case WAIT_OBJECT_0 + 1:
				{
					isLiving=false;
				}
				break;
		}
	}
	CloseHandle(pThis->gHeartThread[0]);
	CloseHandle(pThis->gHeartThread[1]);
	return 1;
}

/*����״̬*/
void COffineQQDlg::SetUinStatus(UinStatus status)
{
	CMenu *pMenu=GetMenu();
	pMenu->GetSubMenu(0)->CheckMenuItem(3,MF_BYPOSITION|MF_UNCHECKED);
	pMenu->GetSubMenu(0)->CheckMenuItem(4,MF_BYPOSITION|MF_UNCHECKED);
	pMenu->GetSubMenu(0)->CheckMenuItem(5,MF_BYPOSITION|MF_UNCHECKED);
	pMenu->GetSubMenu(0)->CheckMenuItem(6,MF_BYPOSITION|MF_UNCHECKED);
	pMenu->GetSubMenu(0)->CheckMenuItem(7,MF_BYPOSITION|MF_UNCHECKED);
	pMenu->GetSubMenu(0)->CheckMenuItem(8,MF_BYPOSITION|MF_UNCHECKED);
	switch(status)
	{
	case BeOnLine:
		{
			pMenu->GetSubMenu(0)->CheckMenuItem(3,MF_BYPOSITION|MF_CHECKED);
		}break;
	case BeCallMe:
		{
			pMenu->GetSubMenu(0)->CheckMenuItem(4,MF_BYPOSITION|MF_CHECKED);
		}break;
	case BeLeave:
		{
			pMenu->GetSubMenu(0)->CheckMenuItem(5,MF_BYPOSITION|MF_CHECKED);
		}break;
	case BeBusy:
		{
			pMenu->GetSubMenu(0)->CheckMenuItem(6,MF_BYPOSITION|MF_CHECKED);
		}break;
	case BeNoTrouble:
		{
			pMenu->GetSubMenu(0)->CheckMenuItem(7,MF_BYPOSITION|MF_CHECKED);
		}break;
	case BeInvisible:
		{
			pMenu->GetSubMenu(0)->CheckMenuItem(8,MF_BYPOSITION|MF_CHECKED);
		}break;
	default:
		{
		}break;
	}
	Config.mStatus=status;	
	UpdateUinStatus();
}

void COffineQQDlg::UpdateUinStatus()
{
	CString strStatus;
	switch(Config.mStatus)
	{
	case BeOffine:
		{
			strStatus=BeOffineTip;
		}break;
	case BeOnLine:
		{
			strStatus=BeOnLineTip;
		}break;
	case BeCallMe:
		{
			strStatus=BeCallMeTip;
		}break;
	case BeBusy:
		{
			strStatus=BeBusyTip;
		}break;
	case BeLeave:
		{
			strStatus=BeLeaveTip;
		}break;
	case BeInvisible:
		{
			strStatus=BeInvisibleTip;
		}break;
	case BeNoTrouble:
		{
			strStatus=BeNoTroubleTip;
		}break;
	case BeOther:
		{
			strStatus=BeOtherTip;
		}break;
	default:
		{
			return;
		}break;
	}
	this->m_Status.UpdataUinStatus(Config.qq_id,CString(&Config.UserName[1]),strStatus);
}

/*��������*/
void COffineQQDlg::On32779()
{
	if(Config.mStatus==BeOffine)
	{
		AfxMessageBox("���ȵ�¼�˺�");
		return;
	}
	SetUinStatus(BeOnLine);
	CCommReq p;
	p.SetPacketType(Type000D);
	p.pConfig=&Config;
	p.PackData();
	DlgSend(p.pConfig->m_iCurrentClientID,p.pack);
}

/*Q�Ұ�*/
void COffineQQDlg::On32780()
{
	if(Config.mStatus==BeOffine)
	{
		AfxMessageBox("���ȵ�¼�˺�");
		return;
	}
	// TODO: �ڴ���������������
	SetUinStatus(BeCallMe);
	
	CCommReq p;
	p.SetPacketType(Type000D);
	p.pConfig=&Config;
	p.PackData();
	DlgSend(p.pConfig->m_iCurrentClientID,p.pack);
}

/*�뿪*/
void COffineQQDlg::On32781()
{
	if(Config.mStatus==BeOffine)
	{
		AfxMessageBox("���ȵ�¼�˺�");
		return;
	}
	// TODO: �ڴ���������������
	SetUinStatus(BeLeave);
	
	CCommReq p;
	p.SetPacketType(Type000D);
	p.pConfig=&Config;
	p.PackData();
	DlgSend(p.pConfig->m_iCurrentClientID,p.pack);
}

/*æµ*/
void COffineQQDlg::On32782()
{
	if(Config.mStatus==BeOffine)
	{
		AfxMessageBox("���ȵ�¼�˺�");
		return;
	}
	// TODO: �ڴ���������������
	SetUinStatus(BeBusy);
	
	CCommReq p;
	p.SetPacketType(Type000D);
	p.pConfig=&Config;
	p.PackData();
	DlgSend(p.pConfig->m_iCurrentClientID,p.pack);
}

/*�������*/
void COffineQQDlg::On32783()
{
	if(Config.mStatus==BeOffine)
	{
		AfxMessageBox("���ȵ�¼�˺�");
		return;
	}
	// TODO: �ڴ���������������
	SetUinStatus(BeNoTrouble);
	
	CCommReq p;
	p.SetPacketType(Type000D);
	p.pConfig=&Config;
	p.PackData();
	DlgSend(p.pConfig->m_iCurrentClientID,p.pack);
}

/*����*/
void COffineQQDlg::On32784()
{
	if(Config.mStatus==BeOffine)
	{
		AfxMessageBox("���ȵ�¼�˺�");
		return;
	}
	// TODO: �ڴ���������������
	SetUinStatus(BeInvisible);
	
	CCommReq p;
	p.SetPacketType(Type000D);
	p.pConfig=&Config;
	p.PackData();
	DlgSend(p.pConfig->m_iCurrentClientID,p.pack);
}

/*ע��*/
void COffineQQDlg::OnOffineLine()
{
	if(Config.mStatus==BeOffine)
	{
		AfxMessageBox("���ȵ�¼�˺�");
		return;
	}
	
	// TODO: �ڴ���������������
	CCommReq p;
	p.SetPacketType(Type0062);
	p.pConfig=&Config;
	p.PackData();

	//�����Ĵ�
	for(int i=0;i<4;i++)
	{
		DlgSend(p.pConfig->m_iCurrentClientID,p.pack);
	}
	//���������߳̽����¼�����
	SetEvent(gHeartThread[1]);
	//����IOCP
	EndTheSystem();
	Config.restart();
	this->m_Send=0;
	this->m_Recv=0;
	this->m_Abandon=0;
	this->m_Status.Updata(m_Send,m_Recv,m_Abandon);
	this->m_Status.SetProcessBar(0);
	SetUinStatus(BeOffine);
	//��������б�
	this->mList1.ResetContent();   //�����Ϣ�б�
	this->mTreeCtrl.DeleteAllItems();  //��������б�
	mFolderList.Clear();
	mList2.Clear();//���������Ϣ�б�
}

/*��½�ɹ�*/
afx_msg LRESULT COffineQQDlg::OnLoginsuccessed(WPARAM wParam, LPARAM lParam)
{
	//���ε�½�ɹ�
	AfxMessageBox("��½�ɹ�");
	//��ʾ�û��˺���Ϣ�Լ�״̬
	SetUinStatus(BeCallMe);
	InitSendPacket();
	return 0;
}

//�رճ���
void COffineQQDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	if(Config.mStatus!=BeOffine)
	{
		//����
		if(IDYES==MessageBox("ȷ���رճ��򣿵��ת����������","�ر�",MB_YESNO))
		{
			OnOffineLine();
			CDialogEx::OnClose();
		}else
		{
			TrayMessage(m_hWnd,NIM_ADD,NULL,"���̳���");
			TrayMessage(m_hWnd,NIM_MODIFY,m_hIcon,"���̳���");
			ShowWindow(SW_HIDE);
		}
	}else
	{
		CDialogEx::OnClose();
	}
}

//��������
BOOL COffineQQDlg::TrayMessage(HWND hWnd,DWORD dwMessage,HICON hIcon,PSTR pszTip)
{
	BOOL bReturn;
	NOTIFYICONDATA NofityData;
	NofityData.cbSize=sizeof(NOTIFYICONDATA);
	NofityData.hWnd=hWnd;
	NofityData.uID=IDR_MAINFRAME;
	NofityData.uFlags=NIF_MESSAGE|NIF_ICON|NIF_TIP;
	NofityData.uCallbackMessage=WM_TRAY_NOTIFICATION;
	NofityData.hIcon=hIcon;
	lstrcpyn(NofityData.szTip,pszTip,sizeof(NofityData.szTip));
	bReturn=Shell_NotifyIcon(dwMessage,&NofityData);
	return bReturn;
}

//������Ϣ����
afx_msg LRESULT COffineQQDlg::OnTrayNotification(WPARAM wParam, LPARAM lParam)
{
	switch(lParam)
	{
	case WM_RBUTTONUP:
		{
			LPPOINT lpoint=new tagPOINT; 
			::GetCursorPos(lpoint);//�õ����λ�� 
			CMenu temp,*ptr=NULL;
            temp.LoadMenu(IDR_MENU3);
            ptr = temp.GetSubMenu(0);
			if(ptr==NULL) return 0;
			SetForegroundWindow();
			UINT uFlags = TPM_RIGHTBUTTON;
            if (GetSystemMetrics(SM_MENUDROPALIGNMENT) != 0)
            {
                uFlags |= TPM_RIGHTALIGN;
            }
            else
            {
                uFlags |= TPM_LEFTALIGN;
            }
			ptr->TrackPopupMenuEx( uFlags, lpoint->x, lpoint->y, this, NULL);
			temp.DestroyMenu();
			delete lpoint;
		}break;
	case WM_LBUTTONDBLCLK:
		{
			ShowWindow(SW_SHOW);
			TrayMessage(m_hWnd,NIM_DELETE,NULL,"");
		}break;
	}

	return 0;
}

//���̹رճ���
void COffineQQDlg::On32793()
{
	// TODO: �ڴ���������������
	if(Config.mStatus!=BeOffine)
	{
		//����
		if(IDYES==MessageBox("ȷ��ע���˺Ų��رճ���","�ر�",MB_YESNO))
		{
			OnOffineLine();
			Sleep(3000);
			//ͣ�����뷢����Ϣ����
			DestroyWindow();
		}
	}
}

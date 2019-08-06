// IdentifyCodeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "QQ.h"
#include "IdentifyCodeDlg.h"
#include "afxdialogex.h"
#include "UserMsg.h"


// CIdentifyCodeDlg �Ի���

IMPLEMENT_DYNAMIC(CIdentifyCodeDlg, CDialogEx)

CIdentifyCodeDlg::CIdentifyCodeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CIdentifyCodeDlg::IDD, pParent)
{

}

CIdentifyCodeDlg::~CIdentifyCodeDlg()
{
}

void CIdentifyCodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, mCode);
	DDX_Control(pDX, IDC_CODE, mCodePic);
}


BEGIN_MESSAGE_MAP(CIdentifyCodeDlg, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &CIdentifyCodeDlg::OnBnClickedOk)
	ON_STN_CLICKED(IDC_CODE, &CIdentifyCodeDlg::OnStnClickedCode)
END_MESSAGE_MAP()


// CIdentifyCodeDlg ��Ϣ�������


BOOL CIdentifyCodeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	mCode.SetLimitText(4);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CIdentifyCodeDlg::SetImgStream(unsigned char *dst,unsigned int size)
{
	COleStreamFile osf;
    osf.CreateMemoryStream(NULL);
    osf.Write(dst, size);
    osf.SeekToBegin();
	mImage.Load(osf.GetStream());

	//mImage.Load("D:\\����\\TencentQQ\\Debug\\png.png");
}

void CIdentifyCodeDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()

	CRect rect;
	mCodePic.GetClientRect(&rect);
	mImage.Draw(mCodePic.GetDC()->GetSafeHdc(), rect.left,rect.top);

}


void CIdentifyCodeDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	mCode.GetWindowTextA(*pRetCString);
	if(pRetCString->Trim().GetLength()==0)
	{
		AfxMessageBox("��������֤��");
	}else
		CDialogEx::OnOK();
}

//������֤��
void CIdentifyCodeDlg::OnStnClickedCode()
{
	//�����֤��ͼƬ��������֤��ͼƬ���ݲ�֧��
}

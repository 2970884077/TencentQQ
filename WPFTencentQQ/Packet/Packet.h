#pragma once

#ifdef _DEBUG
#pragma comment(lib,"../LibD/UtilLib.lib")
#pragma comment(lib,"../LibD/CipherLib.lib")
#else
#pragma comment(lib,"../Lib/UtilLib.lib")
#pragma comment(lib,"../Lib/CipherLib.lib")
#endif

#ifdef _DEBUG
#pragma comment(lib,"Debug\\libprotobufd.lib")
#pragma comment(lib,"Debug\\libprotobuf-lited.lib")
#pragma comment(lib,"Debug\\libprotocd.lib")
#else
#pragma comment(lib,"Release\\libprotobuf.lib")
#pragma comment(lib,"Release\\libprotobuf-lite.lib")
#pragma comment(lib,"Release\\libprotoc.lib")
#endif


//���ݰ�����
//enum PacketType
//{
//	//���������ص�δ֪���ݰ�
//	CODE_FFFF10,
//	/*********��½ϵ�����ݰ�**********/
//	CODE_082501,    /*Type0825*/
//	CODE_082510,
//	CODE_082801,	/*Type0836*/
//	CODE_082810,
//	CODE_083601,	/*Type0828*/
//	CODE_083610,
//	CODE_010401,
//	CODE_010410,
//	CODE_00BA01,
//	CODE_00BA10,
//	/*********��½ϵ�����ݰ�**********/
//	CODE_001D01,	/*Type001D���ݰ�*/
//	CODE_001D10,	
//	CODE_001D02,
//
//	CODE_01BB01,    /*Type01BB���ݰ�*/
//	CODE_01BB10,
//	CODE_01BB02,
//
//	CODE_013401,	/*�����Լ�����*/
//	CODE_013410,
//
//	CODE_000201,	/*Type0002��Ϣ*/
//	CODE_000210,
//	CODE_000202,
//
//	CODE_00EC01,    /*Type00EC����Ϣ����QQ����*/
//	CODE_00EC10,
//
//	CODE_00B901,
//	CODE_00B910,
//	CODE_00B902,
//
//	CODE_00D101,    /*Type00D1��ȡQQ������Ϣ*/
//	CODE_00D110,
//
//	CODE_001D03,
//	CODE_001D04,
//	CODE_001D05,
//	CODE_001D06,
//	CODE_001D07,
//	CODE_001D08,
//	CODE_001D09,
//
//	CODE_000101,   /*Type0001���ѷ�����Ϣ*/
//	CODE_000110,
//
//	CODE_005801,   /*Type0058�������ݰ�*/
//	CODE_005810,
//
//	CODE_00CE10,   /*Type00CE�յ�������Ϣ*/
//	CODE_001710,   /*Type00CE�յ�Ⱥ��Ϣ*/
//
//	CODE_006201,   /*Type0062�������ݰ�,�޷������ݰ�*/
//
//	CODE_002701,
//	CODE_002710,
//
//	CODE_019501,
//	CODE_019510,
//
//	CODE_019B01,
//	CODE_019B10,
//
//	CODE_01A501,
//	CODE_01A510,
//
//	CODE_01AE01,
//	CODE_01AE10,
//
//	CODE_07FF01,
//	CODE_07FF10,
//
//	CODE_00D401,
//	CODE_00D410,
//	CODE_00D402,
//	CODE_00D403,
//
//	CODE_005C01,		//��ѯ����
//	CODE_005C10,
//
//	CODE_003C01,		//��ѯ����
//	CODE_003C10,
//
//	CODE_003E01,
//	CODE_003E10,
//
//	CODE_000D01,	/*Type000D�ñ�״̬*/
//	CODE_000D10,
//
//	CODE_008110,	/*����״̬�ı�֪ͨ��Ϣ*/
//
//	CODE_00CD01,
//	CODE_00CD10,
//};

//���ݰ�����ֵ(wCsCmdNo)
#define Type0825	0x0825
#define Type0836	0x0836
#define Type0104	0x0104
#define Type00BA	0x00BA
#define Type0828	0x0828
#define Type001D	0x001D
#define Type01BB	0x01BB
#define Type0002	0x0002
#define Type0134	0x0134
#define Type00EC	0x00EC
#define Type00B9	0x00B9
#define Type0058	0x0058
#define Type00D1	0x00D1
#define Type0001	0x0001
#define Type00CE	0x00CE
#define Type0017	0x0017
#define Type0062	0x0062
#define Type0027	0x0027
#define Type0195	0x0195
#define Type019B	0x019B
#define Type01A5	0x01A5
#define Type01AE	0x01AE
#define Type07FF	0x07FF
#define Type00D4	0x00D4
#define Type005C	0x005C
#define Type003E	0x003E
#define Type000D	0x000D
#define Type00CD	0x00CD


#define TypeFFFF 0xFFFF		//δ֪��Ϣ

#define StartMark	0x2
#define EndMark		0x3


//�˺�״̬����
enum UinStatus
{
	BeOffine,  //����
	BeOnLine,  //����
	BeCallMe,  //Q�Ұ�
	BeLeave,   //�뿪
	BeBusy,    //æµ
	BeNoTrouble, //�������
	BeInvisible, //����
	BeOther
};

//����״̬��ʾ��
#define BeOffineTip		"����"
#define BeOnLineTip		"��������"
#define BeCallMeTip		"Q�Ұ�"
#define	BeLeaveTip		"�뿪"
#define	BeBusyTip		"æµ"
#define	BeNoTroubleTip	"�������"
#define	BeInvisibleTip	"����"
#define	BeOtherTip		"����"


//�˺�״ֵ̬
#define BeOffineVaule	0xFA
#define BeOnLineValue	0x0A
#define BeCallMeValue	0x3C
#define	BeLeaveValue	0x1E
#define	BeBusyValue		0x32
#define	BeNoTroubleValue	0x46
#define	BeInvisibleValue	0x28
#define	BeOtherValue

//LoginVerifyCodeö��ֵ
#define RESULT_NORMAL		0xEE00		//��������ֵ

#define RESULT_ABNORMAL     0xEE01		//δ֪�Ĳ���������ֵ
#define PWD_ERROR			0xEE02		//�������
#define NEED_LOGINVERIFY	0xEE03
#define NEED_LOGINVERIFYAGAIN	0xEE04	//0836��֤��Ҫ���·���
#define NEED_CHECKCODE		0xEE05		//��Ҫ������֤��
#define NEED_DEVICE_UNLOCKED	0xEE06	//�豸��
#define ID_ALREADY_RECOVERY		0xEE07	//�û��˺��ѱ�����
#define NEED_REINPUTPWD			0xEE08	//��Ҫ������������
#define LOGIN_FAILED			0xEE09	//��Ҫ������������
#define ID_PWD_ERROR			0xEE0A	//�˺Ż����������

#define RESULT_UNKNOW		0xEEEE		//����δ֪����Ҫ��һ������
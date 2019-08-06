#pragma once
#pragma pack(1)
//#ifdef _USRDLL
//#define DIPPER_EXPORTS 1
//#else
//#undef  DIPPER_EXPORTS
//#endif
//
//#ifdef DIPPER_EXPORTS
//#define DIPPEREXPORTS_CONFIG_API __declspec(dllexport)
//#else
//#define DIPPEREXPORTS_CONFIG_API __declspec(dllimport)
//#endif


#include"..\CipherLib\TeaCrypt.h"
#include"..\CipherLib\Ecdh.h"
#include"Packet.h"
#include"../UtilLib/ByteBuffer.h"

#define SIZE_ACCOUNT	0x20
#define SIZE_PWD		0x11	//��֤��0��β����
#define SIZE_URL		0xFF
#define SIZE_IP			0x20
#define SIZE_TOKEN		0x38
#define SIZE_VERIFY		0x78
#define SIZE_NAME		0x37	//QQ�ǳƲ�����24����ĸ����12������
#define SIZE_CODE		0x4		//��֤�볤��


enum NetType
{
	NET_TCP=0,
	NET_UDP=1
};


class CConfigData
{
private:
	CConfigData(void);
	~CConfigData(void);
	static CConfigData *m_pInstance;
public:
	static CConfigData * GetInstance()
	{
		if (m_pInstance == NULL)  //�ж��Ƿ��һ�ε���  
			m_pInstance = new CConfigData();
		return m_pInstance;
	}

public:
	void restart();
private:
	void Init()
	{
		qq_id=0;
		memset(qq_pwd,0,sizeof(qq_pwd));
		memset(pwd_key,0,sizeof(pwd_key));
		mCodePngData.clear();
		memset(IndetifyCode,0,sizeof(IndetifyCode));
		isNeedCode=false;
		memset(host,0,sizeof(host));
		ServerIp=0;
		port=0;
		memset(key0825,0,sizeof(key0825));
		memset(key0836,0,sizeof(key0836));
		memset(key0104,0,sizeof(key0104));
		memset(key00BA,0,sizeof(key00BA));
		memset(token25ret,0,sizeof(token25ret));
		memset(token36ret,0,sizeof(token36ret));
		memset(verify36ret,0,sizeof(verify36ret));
		memset(key0836ret1,0,sizeof(key0836ret1));
		memset(key0836ret2,0,sizeof(key0836ret2));
		memset(data0036ret28,0,sizeof(data0036ret28));
		memset(tokenBAret,0,sizeof(tokenBAret));
		ClientIp=0;
		ServerTime=0;
		memset(UserName,0,sizeof(UserName));
		isTurnIp=false;
		net_type=NET_UDP;
		LoginVerifyCode=RESULT_NORMAL;
		memset(stKey,0,sizeof(stKey));
		memset(ecdh_key,0,sizeof(ecdh_key));
		memset(vague_key,0,sizeof(vague_key));
		memset(login_verify,0,sizeof(login_verify));
		memset(_random_10,0,sizeof(_random_10));
		memset(_random_38,0,sizeof(_random_38));
		memset(SessionKey,0,sizeof(SessionKey));
		memset(ClientKey,0,sizeof(ClientKey));
		mStatus=BeOffine;
		m_iCurrentClientID=0;
	};
public:
	unsigned int qq_id;
	unsigned char qq_pwd[SIZE_PWD];
	unsigned char pwd_key[TEA_KEY_LEN];
	ByteBuffer mCodePngData;
	unsigned char IndetifyCode[SIZE_CODE];				//��֤������
	bool	isNeedCode;
	char host[SIZE_URL];                //hostname��ַ
	unsigned int ServerIp;              //ip���ε�ַ
	unsigned int port;
	unsigned char key0825[TEA_KEY_LEN];
	unsigned char key0836[TEA_KEY_LEN];
	unsigned char key0104[TEA_KEY_LEN];
	unsigned char key00BA[TEA_KEY_LEN];
	//��������
	unsigned char token25ret[SIZE_TOKEN];             //0825���ݰ�����token
	unsigned char token36ret[SIZE_TOKEN];			//0836���ݰ�����token
	unsigned char verify36ret[SIZE_VERIFY];             //0836���ݰ�����0x78��֤����
	unsigned char key0836ret1[TEA_KEY_LEN];
	unsigned char key0836ret2[TEA_KEY_LEN];
	unsigned char data0036ret28[0x28];
	unsigned char tokenBAret[SIZE_TOKEN];
	unsigned int ClientIp;
	unsigned int ServerTime;
	unsigned char UserName[SIZE_NAME];         //��һ�ֽڴ洢����
	bool isTurnIp;
	NetType net_type;
	unsigned int LoginVerifyCode;
public:
	unsigned char stKey[ptkey_len];      //0x19�ֽ�����
	unsigned char ecdh_key[key_len];           //���ܺͽ��ܾ�ʹ��ǰʮ���ֽ����ݣ�0836���ݰ���
public:
	unsigned char vague_key[TEA_KEY_LEN];
	unsigned char login_verify[TEA_KEY_LEN];
	unsigned char _random_10[0x10];            //MD5
	unsigned char _random_38[0x10];            //MD5
public:                        //��½�ɹ�֮���key
	unsigned char SessionKey[TEA_KEY_LEN];
	unsigned char ClientKey[TEA_KEY_LEN*2];
public:
	UinStatus mStatus;        //��½�˺�״̬��Ϣ
	int m_iCurrentClientID;		//�ͻ���socket
public:
	void SetID(unsigned int id){ qq_id = id; };
	void SetPassword(unsigned char *password, unsigned int len)
	{
		memcpy(qq_pwd, password, len);
	}
	void SetServer(unsigned int ip, unsigned int p,unsigned int m)
	{ 
		ServerIp = ip;
		port = p;
		if (m == 0)
			net_type = NET_TCP;
		else if (m==1)
			net_type = NET_UDP;
	};
};

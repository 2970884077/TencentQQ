#pragma once
//#pragma pack(1)
#ifdef _USRDLL
#define DIPPER_EXPORTS 1
#else
#undef  DIPPER_EXPORTS
#endif

#ifdef DIPPER_EXPORTS
#define DIPPEREXPORTS_CONFIG_API __declspec(dllexport)
#else
#define DIPPEREXPORTS_CONFIG_API __declspec(dllimport)
#endif


#include"..\CipherLib\TeaCrypt.h"
#include"..\CipherLib\Ecdh.h"
#include"../UtilLib/ByteBuffer.h"
#include"Packet.h"
#include<map>
#include<vector>
#include"RequestBindMobile.h"
#include"SvcRespRegister.h"
#include"RequestVerifyBindingSmscode.h"
#include"AddressBookItem.h"
#include"RequestCancelBindMobile.h"
#include"Hardware.h"
#include"VerifyCodeInfo.h"

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
	NET_TCP,
	NET_UDP
};


class DIPPEREXPORTS_CONFIG_API CConfigData
{
public:
	CConfigData(void);
	~CConfigData(void);
public:
	void restart();
private:
	void clear()
	{
		qq_id=0;
		memset(qq_pwd,0,sizeof(qq_pwd));
		strServiceCmd.clear();
		memset(KeyAuth,0,sizeof(KeyAuth));
		mCodePngData.isNeedCode=false;
		memset(host,0,sizeof(host));
		ServerIp=0;
		port=0;
		isSidFill=false;
		unknow1.clear();
		ClientIp=0;
		ClientTime=0;
		ServerTime=0;
		memset(ksid,0,sizeof(ksid));
		memset(no_pic_sig,0,sizeof(no_pic_sig));
		memset(encrypt_a1,0,sizeof(encrypt_a1));
		memset(tgt,0,sizeof(tgt));
		memset(st,0,sizeof(st));
		memset(st_key,0,sizeof(st_key));
		memset(stwx_web,0,sizeof(stwx_web));
		app_pri=0xFFFFFFFF;
		validList.clear();
		memset(UserName,0,sizeof(UserName));
		net_type=NET_TCP;
		memset(stKey,0,sizeof(stKey));
		memset(skey,0,sizeof(skey));
		memset(paytoken,0,sizeof(paytoken));
		memset(super_key,0,sizeof(super_key));
		memset(openid,0,sizeof(openid));
		memset(sid,0,sizeof(sid));
		memset(d2_key,0,sizeof(d2_key));
		memset(aq_sig,0,sizeof(aq_sig));
		memset(ecdh_key,0,sizeof(ecdh_key));
		mStatus=BeOffine;
		m_iCurrentClientID=0;
		mRegisterCmd=CmdOnLine;//Ĭ��Ϊ���߲���
		mListCAddressBookItem.clear();
	};
public:
	CHardware mHardware; 
	NetType net_type;
	unsigned int qq_id;
	unsigned char qq_pwd[SIZE_PWD];
	std::string	strServiceCmd;
	unsigned char KeyAuth[TEA_KEY_LEN];//��KeyAuth
	VerifyCodeInfo mCodePngData;			//��֤��
	char host[SIZE_URL];                //hostname��ַ
	unsigned int ServerIp;              //ip���ε�ַ
	unsigned int port;
	bool	isSidFill;		//�Ƿ�ʹ��sid���ܷ������ݰ�
public:
	StatSvcRegisterCMD	mRegisterCmd;		//���ߣ���������״̬ע���ʶ
public:
	//��������
	std::string	 unknow1;
	unsigned int ClientIp;
	unsigned int ClientTime;
	unsigned int ServerTime;
	unsigned char ksid[TEA_KEY_LEN];
	unsigned char no_pic_sig[0x30];
	unsigned char encrypt_a1[0x80];
	unsigned char tgt[0x48];
	unsigned char tgt_key[TEA_KEY_LEN];
	unsigned char st[0x60];
	unsigned char st_key[TEA_KEY_LEN];
	unsigned char stwx_web[0x28];
	unsigned int  app_pri;
	std::map<short,__int64> validList;
	unsigned char skey[0xa];
	unsigned char paytoken[0x2c];
	unsigned char super_key[0x78];
	unsigned char openid[0x2e];
	unsigned char sid[0x10];		//SessionKey
	unsigned char d2_key[0x40];
	unsigned char aq_sig[0x18];
	unsigned char UserName[SIZE_NAME];         //��һ�ֽڴ洢����
public://���������ݴ�
	CRequestBindMobile mRequestBindMobile;
	CRequestCancelBindMobile mRequestCancelBindMobile;
	CRequestVerifyBindingSmscode mRequestVerifyBindingSmscode;
	std::vector<CAddressBookItem> mListCAddressBookItem;
public://���������ݴ�
	CSvcRespRegister mSvcRespRegister;
public:
	unsigned char stKey[ptkey_len];      //0x19�ֽ�����
	unsigned char ecdh_key[key_len];           //���ܺͽ��ܾ�ʹ��ǰʮ���ֽ����ݣ�0836���ݰ���
public:
	UinStatus mStatus;        //��½�˺�״̬��Ϣ
	int m_iCurrentClientID;		//�ͻ���socket
};

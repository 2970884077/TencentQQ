#pragma once
#include"TXCommPack.h"
#include"ConfigData.h"

//ԭ�ͣ�oicq.wlogin_sdk.request/m.class(k.class)
class CLoginPack
{
private:
	CLoginPack(void);
public:
	CLoginPack(unsigned int seq,CConfigData *p){mSeq=seq;pConfig=p;};
	virtual ~CLoginPack(void);
public:
	ByteBuffer Encode();
private:
	void EncodeHead(CTXCommPack&);
	void EncodeBody(CTXCommPack&);//�������֤�룺oicq.wlogin_sdk.request/o.class��
private:
	CTXCommPack	mPack;
	CConfigData *pConfig;
	unsigned int mSeq;
public:
	static unsigned short wCmd;
};


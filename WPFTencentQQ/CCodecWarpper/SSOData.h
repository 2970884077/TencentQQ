#pragma once
#include"SSOReqHead.h"
#include"SSOHead.h"
class CSSOData
{
public:
	CSSOData(void);		//ռ��0x148�ֽ�
	virtual ~CSSOData(void);
private:
	CSSOHead	mSSOHead;
	CSSOReqHead	mSSOReqHead;
public:
	void init(int,char const *,char,int,int,int,char const *,char const *,char const *,char const *,std::string&,
		char const *,char const *,int,char const *,int,int,int);
	void serialize(std::string&);
	/*
	*���ݰ�
	*���ݰ�����
	*1
	*/
	void deSerialize(ByteBuffer&,bool);
};


#pragma once
#include"../JceProtocol/JceStruct.h"
#include"../JceProtocol/JCEChar.h"
#include"../JceProtocol/JCELong.h"
#include"../JceProtocol/JCEInt.h"
#include"../JceProtocol/JCEString.h"

//ԭ��com.tencent.msf.service.protocol.push.SvcReqRegister
class CSvcReqRegister:public JCE::CJceStruct
{
public:
	CSvcReqRegister(void);
	virtual ~CSvcReqRegister(void);
public:
	JCE::JCEChar bIsOnline;
	JCE::JCEChar bIsShowOnline;
	JCE::JCEChar bKikPC;		//�Ƿ�ǿ֧��PC���ֻ�ͬʱ���ߣ�1����PC����
	JCE::JCEChar bKikWeak;
	JCE::JCEChar bOnlinePush;
	JCE::JCEChar bOpenPush;
	JCE::JCEChar bRegType;
	JCE::JCEChar bSlientPush;
	JCE::JCEChar cConnType;
	JCE::JCEChar cNetType;
	JCE::JCELong iLargeSeq;
	JCE::JCEInt	iLocaleID;		//2052
	JCE::JCELong iOSVersion;
	JCE::JCEInt	iStatus;		//11
	JCE::JCELong lBid;
	JCE::JCELong lUin;
	JCE::JCEString	sBuildVer;
	JCE::JCEString	sOther;
	JCE::JCEString	strDevName;
	JCE::JCEString	strDevType;
	JCE::JCEString	strOSVer;
	JCE::JCELong timeStamp;
	JCE::JCEByteArray	vecDevParam;
	JCE::JCEByteArray	vecGuid;
public:
	void readFrom(CJceInputStream& paramd);
	void writeTo(CJceOutputStream& paramd);
};


#pragma once
#include"../JceProtocol/JceStruct.h"
#include"../JceProtocol/JCEInt.h"
#include"../JceProtocol/JCEString.h"

//ԭ��SecurityAccountServer/RespondHeader
class CRespondHeader:public JCE::CJceStruct
{
public:
	CRespondHeader(void);
	virtual ~CRespondHeader(void);
public:
	JCE::JCEString account;
	JCE::JCEInt cmd;
	JCE::JCEString ksid;
	JCE::JCEInt requestID;
	JCE::JCEInt result;		//value=(0:bindOK=true,hadBind=false)(107:bindOK=false,hadBind=true)(105:bind_state=false)(106:uin="")(104:�����벻��ȷ)
	//217�ֻ����벻��ȷ��219����216����Ƶ��̫�ߣ����Ժ����ԡ�224����������Ӫ����δ֧�ֿ�ͨ����223��ʧ�ܣ����Ժ����ԡ�
	//����������ʧ�ܣ����Ժ����ԡ���com.tencent.mobileqq.phonecontact/ContactBindObserver���壩
	JCE::JCEInt svrSeqNo;
	JCE::JCEString tips;
	JCE::JCEInt ver;
public:
	void readFrom(CJceInputStream& paramd);
	void writeTo(CJceOutputStream& paramd);
};


#pragma once
#include"../JceProtocol/JceStruct.h"
#include"../JceProtocol/JCEString.h"

//ԭ��SecurityAccountServer/RequestQueryQQBindingStat
class CRequestQueryQQBindingStat:public JCE::CJceStruct
{
public:
	CRequestQueryQQBindingStat(void);
	~CRequestQueryQQBindingStat(void);
public:
	JCE::JCEString MobileUniqueNo;
public:
	void readFrom(CJceInputStream& paramd);
	void writeTo(CJceOutputStream& paramd);
};


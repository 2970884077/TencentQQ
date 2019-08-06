#pragma once
#include"../JceProtocol/JceStruct.h"
#include"../JceProtocol/JCELong.h"
#include"../JceProtocol/JCEByteArray.h"
#include"../JceProtocol/JCEString.h"
#include"../JceProtocol/JCEListArray.h"

//ԭ��SecurityAccountServer/RequestUploadAddressBookV2
class CRequestUploadAddressBookV2:public JCE::CJceStruct
{
public:
	CRequestUploadAddressBookV2(void);
	~CRequestUploadAddressBookV2(void);
public:
	JCE::JCELong nextFlag;
	JCE::JCEString MobileUniqueNo;
	JCE::JCEByteArray sessionSid;
	JCE::JCEListArray AddressBookList;
public:
	void readFrom(CJceInputStream& paramd);
	void writeTo(CJceOutputStream& paramd);
};


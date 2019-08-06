#pragma once

#include"Packet.h"
#include "IPackData.h"
#include "LoginHead.h"
#include"TXCommPack.h"

//��½���ݰ�����
#define MAX_PACKET_SIZE 2049


class CLoginReq:
	public CIPackData
{
public:
	CLoginReq(void);
	~CLoginReq(void);
private:
	unsigned int PackHead(CTXCommPack*);
	unsigned int PackBody(CTXCommPack*);
public:
	unsigned int PackData();
};


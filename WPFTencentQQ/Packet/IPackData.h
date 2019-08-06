#pragma once
#include"../UtilLib/ByteBuffer.h"
#include"Packet.h"
#include"TXCommPack.h"
#include"..\Packet\ConfigData.h"

class CIPackData
{
public:
	CIPackData(void)
	{
	};
	virtual ~CIPackData(void)
	{
	};
private:
	//���ڷ�װ���ݰ�ͷ
	virtual unsigned int PackHead(CTXCommPack *)=0;
	//���ڷ�װ������
	virtual unsigned int PackBody(CTXCommPack *)=0;
	//���ڶ����ݼ���ǰ�����
	virtual void GarbagePadding(const ByteBuffer&){};
public:
	//���ڷ�װ�������ݰ�
	virtual unsigned int PackData()=0;
	//�����������ݰ�����
	void SetPacketType(unsigned short type){_packet_type=type;};
	unsigned short GetPackType(){return _packet_type;};
public:
	ByteBuffer pack;
	CConfigData *pConfig;     //���ݰ�����
private:
	unsigned short _packet_type;
};


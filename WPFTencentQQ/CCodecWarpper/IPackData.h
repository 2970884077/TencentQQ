#pragma once
#include"../UtilLib/ByteBuffer.h"
#include"Packet.h"
#include"TXCommPack.h"
#include"../CCodecWarpper/ConfigData.h"

class CIPackData
{
public:
	CIPackData(void)
	{
		pack.clear();
		_packet_type=TYPE_UnDefine;
		mSeq=0;
	};
	virtual ~CIPackData(void)
	{
	};
private:
	//���ڷ�װ���ݰ�ͷ
	virtual unsigned int PackHead(CTXCommPack *,void *data=0)=0;
	//���ڷ�װ������
	virtual unsigned int PackBody(CTXCommPack *,void *data=0)=0;
	//���ڶ����ݼ���ǰ�����
	virtual void GarbagePadding(const ByteBuffer&){};
public:
	//���ڷ�װ�������ݰ�
	virtual unsigned int PackData(void *data=0)=0;
	//�����������ݰ�����
	void SetPacketType(unsigned short type){_packet_type=type;};
	unsigned short GetPackType(){return _packet_type;};
	void SetSeq(unsigned int seq){mSeq=seq;};
	unsigned int GetSeq(){return mSeq;};
public:
	ByteBuffer pack;
	CConfigData *pConfig;     //���ݰ�����
private:
	unsigned short _packet_type;
	unsigned int mSeq;
};


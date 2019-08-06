#pragma once
#include"Packet.h"
#include"../UtilLib/ByteBuffer.h"
#include"ICHeadData.h"

class CIUnPackData
{
public:

	CIUnPackData(void)
	{
	}

	virtual ~CIUnPackData(void)
	{
	}
private:
	//���ڽ�����ݰ�ͷ
	virtual unsigned int UnPackHead()=0;
	//���ڽ��������
	virtual unsigned int UnPackBody()=0;
public:
	//���ڰ�������
	void Wrapping(const ByteBuffer& b){pack=b;pack.rpos(0);};
	//���ڼ����յ����ݰ�(����ǰ���)
	virtual	unsigned int _check_packet()=0;
	//���ڽ�����ݰ�
	virtual unsigned int UnPackData()=0;
	//���ڷ������ܵ����ݰ������ܺ�ķ�����
	virtual unsigned int Analysis(void *pModel=NULL)=0;
	//�����������ݰ�����
	void SetPacketType(const unsigned short type){ _packet_type = type; };
	unsigned short GetPackType(){return _packet_type;};
public:
	ICHeadData *pHead;
	ByteBuffer pack;
	unsigned short _packet_type;
};


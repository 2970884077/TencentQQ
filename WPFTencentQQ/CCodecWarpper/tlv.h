#pragma once
#include"../UtilLib/ByteBuffer.h"

typedef struct
{
	unsigned short wLen;	//0x14���ܳ��ȣ�
	ByteBuffer sBuf;
}tlv_t104;

typedef struct
{
	unsigned short wLen;//�ܳ���
	unsigned short wLen2;
	ByteBuffer   sBuf;	//δ֪����
	unsigned short wLen3;
	ByteBuffer  sPicBuf;	//��֤��ͼƬ����
}tlv_t105;
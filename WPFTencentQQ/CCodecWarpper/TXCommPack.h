#pragma once
#include"../UtilLib/ByteBuffer.h"

#define BUFFER_SIZE	0x200
//#pragma pack(1)
class CTXCommPack
{
public:
	CTXCommPack(void);
	CTXCommPack(size_t);
	virtual ~CTXCommPack(void);
public:
	void AddByte(const char);
	void AddWord(const short);
	void AddDWord(const int);
	void AddByteBuffer(ByteBuffer&);
	void AddBuf(const char *,const int);
	void AddBufLenWord();		//����ǰ��2�ֽڳ��ȣ�����������
	void AddLenDWord();		//����ǰ��4�ֽڳ��ȣ���������
	void AddBufLenDWord();		//����ǰ��4�ֽڳ��ȣ�����������
	void AddFieldCode(short);
	void GetBufferOut();
public:
	ByteBuffer buffer;
};

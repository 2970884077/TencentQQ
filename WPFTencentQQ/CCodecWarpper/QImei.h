#pragma once
#include"../JceProtocol/JceInputStream.h"
#include"../JceProtocol/JceOutputStream.h"
#include"../JceProtocol/JCEChar.h"
#include"../JceProtocol/JCEShort.h"
#include"../JceProtocol/JCEInt.h"
#include"../JceProtocol/JCELong.h"
#include"../JceProtocol/JCEString.h"
#include"../JceProtocol/JCEByteArray.h"
#include"../JceProtocol/JceStruct.h"

//ԭ��com.tencent.beacon.c.a.c
class QImei:public JCE::CJceStruct
{
public:
	QImei(void);
	virtual ~QImei(void);
private:
	JCE::JCEChar	a;
	JCE::JCEInt		b;
	JCE::JCEByteArray	c;		//����Lcom/tencent/beacon/b/a;->b([BIILjava/lang/String;)[B
	JCE::JCEString		d;
	JCE::JCEChar		e;		//-1��ʾ�޼��ܣ�1����DES���ܣ�3����AES����
	JCE::JCEChar		f;		//-1������ѹ����1 zipѹ����2����gzipѹ��
	JCE::JCELong		g;
	JCE::JCEString		h;
	JCE::JCEString		i;		//DES����AES��Կ����ΪAES��Կʱ���������ַ���0����0x30����16�ֽ�
public:
	void readFrom(CJceInputStream& paramd);
	void writeTo(CJceOutputStream& paramd);
public:
	JCE::JCEString	Geti(){return i;};
	JCE::JCEByteArray	Getc(){return c;};
};


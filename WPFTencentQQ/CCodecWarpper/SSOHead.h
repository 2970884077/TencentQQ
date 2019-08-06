#pragma once
#include<string>
#include"../UtilLib/ByteBuffer.h"
class CSSOHead
{
public:
	CSSOHead(void);
	virtual ~CSSOHead(void);
public:
	void init(char,std::string&);
	void serialize(std::string&,int);
	/*
	*���ݰ����ݣ�ƫ��4�ֽڣ�
	*���ݰ�����-4
	*λ�ô洢�ռ䣨���ݳ�ʼ��Ϊ0��,Ӧ��Ϊ���ʣ�����ݳ���
	*/
	void deSerialize(ByteBuffer&,int&);
	void serialize_ver8(std::string&);
	void serialize_ver9(std::string&,int);
public:
	std::string readString(ByteBuffer &mBuffer);
public:
	int	m_Version;
	int m_Flag;
	std::string	strQQ;
	char	a;
	char	b;
};


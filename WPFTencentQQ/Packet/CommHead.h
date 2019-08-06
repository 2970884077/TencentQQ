#include"Packet.h"
#include"ICHeadData.h"

struct CCommHeadReq_Type
{
	unsigned short version;       //δ֪������ΪӦ������汾
	unsigned short code;          //CODE_0825,CODE_0836,CODE_0828����ֵ
	unsigned short serial;          //�����
	unsigned int   qq_id;          //QQ����
	unsigned char fix[3];          //3�ֽ��������
	unsigned int unknown1;
	unsigned int unknown2;
};

struct CCommHeadResp_Type
{
	unsigned short version;       //δ֪������ΪӦ������汾
	unsigned short code;          //CODE_0825,CODE_0836,CODE_0828����ֵ
	unsigned short serial;          //�����
	unsigned int   qq_id;          //QQ����
	unsigned char fix[3];          //3�ֽ��������
};


class CCommHeadReq :
	public ICHeadData
{
public:
	CCommHeadReq(void)
	{
	};
	virtual ~CCommHeadReq(void)
	{
	};
public:
	CCommHeadReq_Type Hda;
};

class CCommHeadResp :
	public ICHeadData
{
public:
	CCommHeadResp(void)
	{
	};
	virtual ~CCommHeadResp(void)
	{
	};
public:
	CCommHeadResp_Type Hda;
public:                               //����ͷ���������岿������ƫ���Լ�����
	unsigned int _head_offset;           //���ݰ�ͷ��ƫ��
	unsigned int _head_len;              //���ݰ�ͷ����С
	unsigned int _body_offset;           //���ݰ�������ƫ��
	unsigned int _body_len;              //���ݰ��������С
};
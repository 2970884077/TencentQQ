#pragma once

enum RESULT
{
	RESULT_SUCCESS=0xFF00,
	ERR_COMMON,						//һ���Դ���

	ERR_NORESPOND,					//Զ�̷�����û�з�Ӧ
	ERR_NETINIT,					//�����ʼ��ʧ��
	ERR_GETHOSTBYNAME,				//dnsת������
	ERR_LOGIN_FAILED,				//��½ʧ��
	ERR_LOGIN_PASSWORD,				//�������
	ERR_LOGIN_CHECK,				//��֤��
	ERR_SEND_FAILED,				//���ݷ���ʧ��
	ERR_CONNECT_FAILED,				//tcp���ӷ�����ʧ��
	ERR_NOENOUGHBUF,				//malloc����ʧ��
	ERR_CHECK_PACKET,				//���ݰ�������
	ERR_ANALYSIS_PACKET,			//���ݰ���������
	ERR_OPEN_REG,					//ע������ʧ��
	ERR_ADJUSTPRIVILEGES_FAILED,	//Ȩ������ʧ��
	ERR_PROCESS_FAILED,				//���غ�����ȡʧ��
	ERR_ENCRYPT_FAILED,				//���ݼ���ʧ��
	ERR_CREATEGUID_FAILED,			//CoCreateGuid����guidʧ��
	ERR_GENERATE_COMPUTERID_FAILED,	//computer id����ʧ��
	ERR_INSTRUCT_INVALID,
	ERR_ECDH_ERROR,					//ECDHʧ��
	ERR_GETSID_FAILED,				//��ȡsid����
	ERR_IOCP,						//iocp��ش���
	ERR_PACKET_ABANDON,				//�������ݰ�

};

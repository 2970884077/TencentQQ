#pragma once

#define WM_RECEIVED_MSG		WM_USER+100		//netlibģ�鷢����Ϣ
#define WM_TRANSMIT_MSG		WM_USER+101

#define WM_LOGINSUCCESSED	WM_USER+104
#define WM_TRAY_NOTIFICATION	WM_USER+105


//sCmd�����
enum
{
	ACTION_SEND_MSG,
	ACTION_QUERY_USERDATA,
};	

//ͳһ��Ϣ������(wParam)
struct ActionCommand
{
	unsigned short	sCmd;		//��Ϣ����
	unsigned short	sSubCmd;	//�б�λ��
};

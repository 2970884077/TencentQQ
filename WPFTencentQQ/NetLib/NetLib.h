#pragma once
#include<WinSock2.h>
#include"../UtilLib/ByteBuffer.h"


//�����ɱ�������C#������ʹ�������ݺ��˳�����ʱ���Լ���ն�ջ�����Ա���ʹ��__stdcall��ʽ
typedef  void(__stdcall *MainCallBack)(unsigned int,unsigned int,unsigned char*,unsigned int);


bool __stdcall	StartTheSystem(
	int		m_iPortNr,
	int		m_iMaxNumberOfConnections,
	int		m_iNrOfIOWorkers,
	int		m_iNrOfLogicalWorkers,
	int		m_iMaxNrOfFreeBuff,
	int		m_iMaxNrOfFreeContext,
	bool	m_iSendInOrder,
	bool	m_bReadInOrder,
	int		m_iNrOfPendlingReads);

bool __stdcall	EndTheSystem();

bool __stdcall	OnConnectA(MainCallBack _render, const CString mIp, const unsigned int mPort, const unsigned int _inet);

void __stdcall OnDisconnect(unsigned int);

void __stdcall SendPacket(unsigned int, char *msg,unsigned int size);

void __stdcall ChangeNotifyWnd(const HWND mHnd, unsigned int);


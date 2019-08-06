#pragma once
#include<map>

typedef void (*FPSeqMessageCallBack)(LPVOID lParam1, LPVOID lParam2);

//ԭ��com.tencent.mobileqq.msf.core/MsfCore.seqFactory
class CSeqSerial
{
public:

	CSeqSerial(void)
	{
		if(SeqSerial==0)
		{
			SeqSerial=rand() % 40001 + 60000;
		}
	}
	virtual ~CSeqSerial(void)
	{
	}
public:
	unsigned int GetNexSeq(FPSeqMessageCallBack mFunc=NULL);
	void SeqRun(unsigned int mSeq,LPVOID lParam1, LPVOID lParam2);
public:
	static unsigned int SeqSerial;
	static std::map<unsigned int,FPSeqMessageCallBack>  funcs_of_maps;
public://�ص������б�
	static void default_func(LPVOID lParam1, LPVOID lParam2);//Ĭ�ϻص�
	static void initial_RequestQueryQQBindingStat(LPVOID lParam1, LPVOID lParam2);
	static void CMobileNo_RequestQueryQQBindingStat(LPVOID lParam1, LPVOID lParam2);
	static void CMobileNo_RequestBindMobile(LPVOID lParam1, LPVOID lParam2);
};


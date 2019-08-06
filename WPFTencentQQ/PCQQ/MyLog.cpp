#include"MyLog.h"

//��־����
LOG gStatusLog;			//������־
LOG gDataLog;			//������־

void StatusLogText(const char *text)
{
#ifdef MYLOGOUT
	gStatusLog.StatusOut(text);
#endif
}

void DataLogText(const char *text)
{
#ifdef MYLOGOUT
	gDataLog.StatusOut(text);
#endif
}

void DataLogBytes(const char *tip,const unsigned char *bytes,const unsigned int n)
{
#ifdef MYLOGOUT
	gDataLog.DataOut(tip,bytes,n);
#endif
}
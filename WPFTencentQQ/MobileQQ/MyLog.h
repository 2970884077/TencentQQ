#include"../UtilLib/LOG.h"
#define MYLOGOUT			//�Ƿ��ӡ��־



extern LOG gStatusLog;			//������־
extern LOG gDataLog;			//������־

void StatusLogText(const char*);
void DataLogText(const char*);
void DataLogBytes(const char*,const unsigned char*,const unsigned int);


//�����ɱ�������C#������ʹ�������ݺ��˳�����ʱ���Լ���ն�ջ�����Ա���ʹ��__stdcall��ʽ
typedef  void(__stdcall *MainCallBack)(unsigned char*, unsigned int);

//��������
void __stdcall PackPacket(unsigned char *argu, unsigned int _len, unsigned char **msg, unsigned int *size);
bool __stdcall unPackPacket(unsigned char *data, unsigned int size, unsigned char **notifymsg, unsigned int *notifysize);


void __stdcall _InitId(unsigned int);
void __stdcall _InitPassword(unsigned char *password, unsigned int size);
void __stdcall _InitServer(unsigned int,unsigned int,unsigned int);

void __stdcall _Init0825();
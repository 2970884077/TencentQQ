//�˴����ڶ���ȫ�ֵĺ궨��
#pragma once
#include"stdafx.h"
#include"..\UtilLib\HelpFunc.h"
#include"..\NetLib\NetLib.h"
#include"..\SkinUI\SkinUI.h"

#ifdef _DEBUG
#pragma comment(lib,"../LibD/NetLib.lib")
#pragma comment(lib,"../LibD/UtilLib.lib")
#pragma comment(lib,"../LibD/CCodecWarpper.lib")
#pragma comment(lib,"../LibD/CipherLib.lib")
#pragma comment(lib,"../LibD/SkinUI.lib")
#else
#pragma comment(lib,"../Lib/NetLib.lib")
#pragma comment(lib,"../Lib/UtilLib.lib")
#pragma comment(lib,"../Lib/CCodecWarpper.lib")
#pragma comment(lib,"../Lib/CipherLib.lib")
#pragma comment(lib,"../Lib/SkinUI.lib")
#endif


#include "../CCodecWarpper/RespondQueryQQBindingStat.h"

#include"../UtilLib/err_code.h"//(Ӧ�÷�����������)

namespace GlobeVar
{
	extern CRespondQueryQQBindingStat mRespondQueryQQBindingStat;
	void Error_Check(unsigned int mode);
};


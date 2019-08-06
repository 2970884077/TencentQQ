#pragma once
#pragma pack(1)
#include<array>
class Protocol
{
private:
	Protocol();
	virtual ~Protocol();
	static Protocol *m_pInstance;
public:
	static Protocol * GetInstance()
	{
		if (m_pInstance == NULL)  //�ж��Ƿ��һ�ε���
		{
			m_pInstance = new Protocol();
			m_pInstance->LoadProtocol_3727("");
		}
		return m_pInstance;
	}
public:
	bool LoadProtocol_360D(std::string strFile);
	bool LoadProtocol_371B(std::string strFile);
	bool LoadProtocol_3727(std::string strFile);
public:
	unsigned short wSSOVersion;
	unsigned short wClientVersion;
	unsigned short wMainVersion;	//cMainVer cSubVer
	unsigned int	dwPubNo;
	unsigned short wDHVersion;
	unsigned int	dwQDVersion;
	unsigned short wQdCsSubNo;
	unsigned char	cQdCsSubNo;
	unsigned char	cQdSubFixed;
	unsigned char	cOsType;
	unsigned char	bIsWOW64;
	unsigned int	dwDrvVersionInfoHight;
	unsigned int	dwDrvVersionInfoLow;
	std::array<BYTE, 0x10> DEFAULT_QQEXE_MD5;//QQ.exe�ļ�MD5
	std::array<BYTE, 8> bufVersion_TSSafeEdit;//�ļ��汾��2015 5.6.1��
	std::array<BYTE, 8> bufVersion_QScanEngine;//�ļ��汾��2.4.0.0��
	std::array<BYTE, 0x31> ECDH_PUBLIC_KEY;
	std::array<BYTE, 0x19> ST_KEY;
	std::array<BYTE, 0x10> ECDH_KEY;
	std::array<BYTE, 0x10> QD_KEY;
	std::string STR_COMPUTER_ID;
	std::array<BYTE, 0x10> DEFAULT_GUID;//SSOCommon��CComputerIDGenerator::GenerateEx
	std::array<BYTE, 0x10> DEFAULT_GUID2;//���ΪGUID2,�㷨δ֪
	std::array<BYTE, 0x10> DEFAULT_VAGUE;
	std::array<BYTE, 0x10> COMPUTER_GENERATEG_ID;//AddComputerIdGenerateG�㷨����(SSOCommon��CComputerIDGenerator::Generate)
	std::array<BYTE, 0x10> DEFAULT_SID;//GetSSOConfigSid��������
	std::array<BYTE, 0x4> DEFAULT_LAN_IP;
};


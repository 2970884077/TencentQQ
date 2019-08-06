#pragma once

#define StartMark	0x2
#define EndMark		0x3

//���ݰ����Ͷ���
#define		TYPE_UnDefine				0xDDFF
#define		TYPE_HULUE					0xDD00
#define		TYPE_MSF					0xDD01
#define		STR_MSF						"MSF"
#define		PhSigLcId_Check				0xDD02
#define		STR_PhSigLcId_Check			"PhSigLcId.Check"
#define		ConfigService_ClientReq		0xDD03
#define		SRT_ConfigService_ClientReq	"ConfigService.ClientReq"
#define		HeartBeat_Alive				0xDD04
#define		STR_HeartBeat_Alive			"HeartBeat.Alive"			//�ݲ�������
#define		CliLogSvc_UploadReq			0xDD05
#define		STR_CliLogSvc_UploadReq		"CliLogSvc.UploadReq"
#define		wtlogin_login				0xDD06
#define		STR_wtlogin_login			"wtlogin.login"
#define		wtlogin_trans_emp			0xDD07
#define		STR_wtlogin_trans_emp		"wtlogin.trans_emp"
#define		GrayUinPro_Check			0xDD08
#define		STR_GrayUinPro_Check		"GrayUinPro.Check"
#define		friendlist_GetTroopListReqV2	0xDD09
#define		STR_friendlist_GetTroopListReqV2	"friendlist.GetTroopListReqV2"
#define		StatSvc_register			0xDD0A
#define		STR_StatSvc_register		"StatSvc.register"
#define		OidbSvc_0x7a2_0			0xDD0B
#define		STR_OidbSvc_0x7a2_0			"OidbSvc.0x7a2_0"
#define		account_RequestBindMobile	0xDD0C
#define		STR_account_RequestBindMobile	"account.RequestBindMobile"
#define		account_RequestUploadAddressBookV2	0xDD0D
#define		STR_account_RequestUploadAddressBookV2	"account.RequestUploadAddressBookV2"
#define		account_RequestQueryQQBindingStat	0xDD0E
#define		STR_account_RequestQueryQQBindingStat	"account.RequestQueryQQBindingStat"
#define		account_RequestVerifyBindingSmscode	0xDD0F
#define		STR_account_RequestVerifyBindingSmscode	"account.RequestVerifyBindingSmscode"
#define		account_RequestQueryQQMobileContactsV3	0xDD10
#define		STR_account_RequestQueryQQMobileContactsV3	"account.RequestQueryQQMobileContactsV3"
#define		account_RequestCancelBindMobile			0xDD11
#define		STR_account_RequestCancelBindMobile		"account.RequestCancelBindMobile"
#define		account_RequestUploadAddressBook		0xDD12
#define		STR_account_RequestUploadAddressBook	"account.RequestUploadAddressBook"
#define		account_RequestUpdateAddressBook		0xDD13
#define		STR_account_RequestUpdateAddressBook	"account.RequestUpdateAddressBook"
#define		SummaryCard_ReqSearch					0xDD14
#define		STR_SummaryCard_ReqSearch				"SummaryCard.ReqSearch"
#define		EncounterSvc_ReqGetEncounter			0xDD15
#define		STR_EncounterSvc_ReqGetEncounter		"EncounterSvc.ReqGetEncounter"


//mqq.app.AppRuntime.Status
//�˺�״̬����
enum UinStatus
{
	BeOnLine,  //����
	BeOffine,  //����
	BeAway,   //�뿪
	BeInvisible, //����
	BeReceiveofflinemsg,
	BeOther
};

//StatSvc_register����
enum StatSvcRegisterCMD
{
	CmdOnLine,
	CmdOffLine,
	CmdHeartBeat
};

//����״̬��ʾ��
#define BeOffineTip		"����"
#define BeOnLineTip		"����"
#define	BeAwayTip		"�뿪"
#define	BeInvisibleTip	"����"
#define	BeOtherTip		"����"


//�˺�״ֵ̬
#define BeOffineVaule	0xFA
#define BeOnLineValue	0x0A
#define BeCallMeValue	0x3C
#define	BeLeaveValue	0x1E
#define	BeBusyValue		0x32
#define	BeNoTroubleValue	0x46
#define	BeInvisibleValue	0x28
#define	BeOtherValue
#pragma once
//ԭ��com.tencent.beacon.upload.h
class BeaconUploadResp
{
public:
	BeaconUploadResp(void);
	virtual ~BeaconUploadResp(void);
public:
	void encode();
	void decode(char*,int);
};


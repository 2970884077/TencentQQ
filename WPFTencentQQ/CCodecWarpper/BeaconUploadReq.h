#pragma once
//ԭ��com.tencent.beacon.e.d
class BeaconUploadReq
{
public:
	BeaconUploadReq(void);
	virtual ~BeaconUploadReq(void);
public:
	void encode();
	void decode(char*,int);
};


#include "StdAfx.h"
#include <openssl\e_os2.h>

#include <openssl\opensslconf.h>	/* for OPENSSL_NO_ECDH */
#include <openssl\crypto.h>
#include <openssl\bio.h>
#include <openssl\bn.h>
#include <openssl\objects.h>
#include <openssl\rand.h>
#include <openssl\sha.h>
#include <openssl\err.h>
#include <openssl\ecdsa.h>
#include <openssl\ec.h>
#include <openssl\ecdh.h>

#ifdef _DEBUG
#pragma comment(lib,"ssleay32MDd.lib")
#pragma comment(lib,"libeay32MDd.lib")
#else
#pragma comment(lib,"ssleay32MD.lib")
#pragma comment(lib,"libeay32MD.lib")
#endif

#include "Ecdh.h"


CEcdh::CEcdh(void)
{
	this->nid=0;
}


CEcdh::~CEcdh(void)
{
}

void CEcdh::ecdh_init()
{
	EC_builtin_curve *curves;
	int crv_len;

	/* ��ȡʵ�ֵ���Բ���߸��� */
	crv_len = EC_get_builtin_curves(NULL, 0);
	curves = (EC_builtin_curve *)malloc(sizeof(EC_builtin_curve) * crv_len);
	/* ��ȡ��Բ�����б� */
	EC_get_builtin_curves(curves, crv_len);

	/* ѡȡһ����Բ���� */
	//*nid=curves[4].nid;
	this->nid=0x2C7;    //��ֵΪ��ѶQQѡȡ����Բ����������ssoplatform.dll���ҵ���Ӧ�Ĵ���
	free(curves);
}



bool CEcdh::ecdh_generate_publicKey(BYTE *ECDH_PUBLIC_KEY, unsigned int len)
{

	EC_KEY *ec_key = EC_KEY_new_by_curve_name(nid);
	const EC_GROUP *ec_group = EC_KEY_get0_group(ec_key);
	EC_POINT *ec_point = EC_POINT_new(ec_group);

	if (EC_KEY_generate_key(ec_key) == 1)
	{

		const EC_POINT *publicKey=EC_KEY_get0_public_key(ec_key);

		EC_POINT_point2oct(ec_group,publicKey,POINT_CONVERSION_COMPRESSED,stKey,sizeof(stKey),NULL); //stKeyΪ0x19����

		if (EC_POINT_oct2point(ec_group, ec_point, ECDH_PUBLIC_KEY, len, NULL) == 1)
		{

			ECDH_compute_key(key,sizeof(key) , ec_point, ec_key, NULL); //keyΪ0x18�ֽ���Կ��ֻȡ0x10�ֽ�
			
			EC_KEY_free(ec_key);
			EC_POINT_free(ec_point);
			return TRUE;
		}
	}
	EC_KEY_free(ec_key);
	EC_POINT_free(ec_point);
	return FALSE;
}
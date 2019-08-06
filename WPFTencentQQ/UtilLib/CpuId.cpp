#include "StdAfx.h"
#include "CpuId.h"


CCpuId::CCpuId(void)
{
	veax=0;
	vebx=0;
	vecx=0;
	vedx=0;
}


CCpuId::~CCpuId(void)
{
}

void CCpuId::cpuid(unsigned int veax1)
{        
	unsigned int m_veax=0,m_vebx=0,m_vecx=0,m_vedx=0;
	_asm{
		pushad
		mov eax,veax1                 
		cpuid 
		mov m_veax,eax                 
		mov m_vebx,ebx                 
		mov m_vecx,ecx                 
		mov m_vedx,edx  
		popad
	}
	veax=m_veax;
	vebx=m_vebx;
	vecx=m_vecx;
	vedx=m_vedx;
}
void CCpuId::LeftMove(unsigned int var)
{  
	//printf("%c",var);  
	for(int i=0;i<3;i++)  
	{  
		var=(var>>8);
		//printf("%c",var);  
	}
}

void CCpuId::LM(unsigned int var)
{  
	//printf("%d",var);  
	for(int i=0;i<3;i++)  
	{  
		var=(var>>8);
		//printf("%d",var);  
	}
}

void CCpuId::getCpuName(unsigned char *dst,unsigned int dstlen)
{  
	//dstlen��=0x30�ռ�
	for(int j=0;j<3;j++)  
	{  
		cpuid(0x80000002+j);  
		memcpy(dst+j*0x10,&veax,sizeof(veax));
		memcpy(dst+j*0x10+0x4,&vebx,sizeof(vebx));
		memcpy(dst+j*0x10+0x8,&vecx,sizeof(vecx));
		memcpy(dst+j*0x10+0xc,&vedx,sizeof(vedx));
	}
}
void CCpuId::getCpuBrand()
{   
	for(int j=0;j<2;j++)  
	{  
		cpuid(0x80000003+j); 
	}  
}

void  CCpuId::getCpuFeature()
{
	//��������̫�࣬�޷�һһ��д����Ҫ��ʱ����д��������һ���ġ�  
}

void CCpuId::getCpuSeris()
{
	cpuid(1);
	LM(veax);
	cpuid(3);
	LM(vecx);
	LM(vedx);
	//printf("\n";
}

bool CCpuId::isSupport()
{
	unsigned int retv=0;
	_asm
 {
	 pushad
     pushfd
     pop eax                    //eax = eflags
     mov ebx, eax           // ��EFLAGS�Ĵ���ֵ���浽EAX��EBX�Ĵ���
     xor eax, 00200000h  // toggle bit 21, eflags.[ID]
     push eax
     popfd                      // ��תEAX�Ĵ���ֵ��Bit 21λ��д��EFLAGS�Ĵ���;
     pushfd
     pop eax
     cmp eax, ebx           // ���¶�ȡEFLAGS�Ĵ���ֵ��EAX,�Ƚ�EAX��EBX�Ĵ���ֵ;
     jz NO_CPUID
     mov retv, 1                   //֧��
	 popad
	 jmp end

NO_CPUID:
     mov retv,0
	 popad
end:
 }
 if(retv)
	 return true;
 else
	return false;
}
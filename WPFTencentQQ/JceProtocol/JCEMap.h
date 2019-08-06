#pragma once
#include "jceiobject.h"
#include"JCEString.h"
#include<map>

//����֧��keyΪJCEString��map
namespace JCE
{
	class JCEMap :
		public IObject
	{
	public:

		JCEMap(void)
		{
		}

		virtual ~JCEMap(void)
		{
			std::map<JCE::IObject*,JCE::IObject*>::iterator iter = _value.begin();
			while(iter != _value.end()) //#1 
			{
			  //ע��Ҫ���ͷ��ڴ棬��ɾ��mapԪ�أ�˳���ܵߵ���
			   //�ͷ��ڴ�
			 delete iter->second;
			 iter->second = NULL;
			 //ɾ��mapԪ��
			 _value.erase(iter++); //#1
			}
		}
	public:
		std::map<JCE::IObject*,JCE::IObject*> _value;
	public:
		unsigned int type(){return JCETypeJCEMap;};
	};
}


#include"stdafx.h"
#include"FolderList.h"
#include"..\UtilLib\HelpFunc.h"

bool FolderList::IsExistCluster(const unsigned short mIndex,unsigned int&mPos)
{
	for(unsigned int i=0;i<mList1.size();i++)
	{
		if(mList1[i].wClusterIndex==mIndex)
		{
			mPos=i;
			return true;
		}
	}
	return false;
}

bool FolderList::IsExistFriend(const unsigned int mUin,FriendPos &mPos)
{
	for(int i=0;i<mList1.size();i++)
	{
		for(int j=0;j<mList1[i].Friends.size();j++)
		{
			if(mList1[i].Friends[j].dwUin==mUin)
			{
				//�ҵ�
				mPos.mClusterIndex=i;
				mPos.mFriendIndex=j;
				return true;
			}
		}
	}
	return false;
}

void FolderList::InsertFolder(const PacketRet0134& mPacketRet)
{
	//���ж��Ƿ��иú���
	if(mPacketRet.wFriendNum==0||(mPacketRet.wFriendNum!=mPacketRet.FriendsFolderList.size())) return;

	for(unsigned int i=0;i<mPacketRet.FriendsFolderList.size();i++)
	{
		if(mPacketRet.FriendsFolderList[i].arrFolderIDList==0x0)
		{
			//ȺID
			GroupFolder mValue;	
			mValue.dwClusterId=mPacketRet.FriendsFolderList[i].dwUin;
			mList2.push_back(mValue); //ֱ�Ӳ�����
			continue;
		}
		ClusterFolder mValue;
		mValue.wClusterIndex=mPacketRet.FriendsFolderList[i].arrFolderIndex;
		unsigned int mPos=0;
		if(IsExistCluster(mValue.wClusterIndex,mPos))
		{
			//����
			Friend mFriend={0};
			mFriend.dwUin=mPacketRet.FriendsFolderList[i].dwUin;
			mList1[mPos].Friends.push_back(mFriend);
		}else
		{
			//������
			Friend mFriend={0};
			mFriend.dwUin=mPacketRet.FriendsFolderList[i].dwUin;
			mValue.Friends.push_back(mFriend);
			mList1.push_back(mValue);
		}
	}
}

void FolderList::InsertCluster(const PacketRet0001& mPacketRet)
{
	for(int i=0;i<mPacketRet.cFolderNum;i++)
	{
		unsigned short wClusterIndex=mPacketRet.FriendsFolderList[i].cFolderSvrIndex;
		unsigned int mPos=0;
		if(IsExistCluster(wClusterIndex,mPos))
		{
			//���ڸ÷���
			unsigned char *strFolderName=NULL;
			int len=Utf8ToMultiByte(mPacketRet.FriendsFolderList[i].strFolderName.c_str(),mPacketRet.FriendsFolderList[i].strFolderName.size(),&strFolderName);
			if(len==0)
			{
				//AppendLog("����������ת��ʧ��");
				continue;
			}
			mList1[mPos].strClusterName.append((char*)strFolderName,len);
			free(strFolderName);
			strFolderName=NULL;
		}else
		{
			//�����ڸ÷���,����÷���
			ClusterFolder mFolder={0};
			mFolder.wClusterIndex=wClusterIndex;
			//����ת��
			unsigned char *strClusterName=NULL;
			int len=Utf8ToMultiByte(mPacketRet.FriendsFolderList[i].strFolderName.c_str(),mPacketRet.FriendsFolderList[i].strFolderName.size(),&strClusterName);
			if(len==0)
			{
				//AppendLog("����������ת��ʧ��");
				continue;
			}
			mFolder.strClusterName.append((char*)strClusterName,len);		//ת������
			free(strClusterName);
			strClusterName=NULL;
			mFolder.Friends.clear();
			this->mList1.push_back(mFolder);
		}
	}
	//Ĭ���ҵĺ��ѷ���
	unsigned short wClusterIndex=0;
	unsigned int mPos=0;
	if(IsExistCluster(wClusterIndex,mPos))
	{
		//���ڸ÷���
		if(mList1[mPos].strClusterName.size()==0)
			mList1[mPos].strClusterName="�ҵĺ���";
	}
}

void FolderList::InitFriendsStatus(const PacketRet0027& mPacketRet)
{
	for(int i=0;i<mPacketRet.FriendsList.size();i++)
	{
		FriendPos mPos={0};
		if(IsExistFriend(mPacketRet.FriendsList[i].dwUin,mPos))
		{
			//������ֵ
			mList1[mPos.mClusterIndex].Friends[mPos.mFriendIndex].wStatus=mPacketRet.FriendsList[i].wStatus;
		}else
		{
			//�����������
			Friend mFriend={0};
			mFriend.dwUin=mPacketRet.FriendsList[i].dwUin;
			mFriend.wStatus=mPacketRet.FriendsList[i].wStatus;
			mList1[0].Friends.push_back(mFriend);
		}
	}
}
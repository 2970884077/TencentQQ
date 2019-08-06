#pragma once
#ifdef _USRDLL
#define DIPPER_EXPORTS 1
#else
#undef  DIPPER_EXPORTS
#endif

#ifdef DIPPER_EXPORTS
#define DIPPEREXPORTS_FolderList_API __declspec(dllexport)
#else
#define DIPPEREXPORTS_FolderList_API __declspec(dllimport)
#endif


#include"PacketRet.h"


struct Friend
{
	//�ο�PacketRet0027_Friend�ֶ�
	unsigned int	dwUin;
	unsigned short	wStatus;
};

//��������λ�ýṹ��
struct FriendPos
{
	unsigned int	mClusterIndex;	//std::vector<FriendFolder> mList;Ŀ¼���
	unsigned int	mFriendIndex;	//std::vector<Friend> Friends;�����б����
};

struct ClusterFolder
{
	unsigned short	wClusterIndex;
	std::string		strClusterName;		//������
	std::vector<Friend> Friends;		//�����б�
};

struct GroupFolder
{
	unsigned int dwClusterId;
	unsigned int dwExternalClusterId;
	std::string				strFolderName;		//Ⱥ��
	std::vector<Friend> mMembers;		//��Ա�б�
};

#define	FriendsFolderIterator	std::vector<FriendFolder>::iterator

class DIPPEREXPORTS_FolderList_API FolderList
{
public:
	FolderList(){Clear();};
	~FolderList(){Clear();};
public:
	void InsertFolder(const PacketRet0134&);	//����Ŀ¼���������Ⱥ��
	void InsertCluster(const PacketRet0001&);	//���������Ϣ
	void InitFriendsStatus(const PacketRet0027&);
	void Clear(){mList1.clear();mList2.clear();};
private:
	bool IsExistCluster(const unsigned short,unsigned int&);
	bool IsExistFriend(const unsigned int,FriendPos&);
public:
	std::vector<ClusterFolder> mList1;
	std::vector<GroupFolder> mList2;
};
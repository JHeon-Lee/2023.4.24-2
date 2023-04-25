#pragma once

enum ITEM_TYPE
{
	ITEM_ARMOR = 0,
	ITEM_WEAPON,
	ITEM_RING1,
	ITEM_RING2,
	ITEM_HP,
	ITEM_MP,
	ITEM_TYPE_NUM
};

struct tagItem
{
	string strName; // �̸�
	ITEM_TYPE eType; // ����
	string strDesc; // ����
	int nAttribute; // �Ӽ�(����, ���ݷ�, ȸ���� ��)
	int nPrice; // ����
};

class cStock
{
protected:
	vector<tagItem> m_vecItem[ITEM_TYPE_NUM];
	vector<tagItem>::iterator m_vecIter;

public:
	cStock();
	~cStock();

	void AddItem(tagItem newItem); // ������ �߰�
	tagItem PickItem(ITEM_TYPE itemType, int index); // ������ ������(���� �� ���� ��ȯ)
	vector<tagItem>& GetItemList(ITEM_TYPE itemType); // ������ ��� ��ȯ(�䱸 ����)
	void ShowItem(ITEM_TYPE itemType); // ������ ��� ȭ�鿡 ���
};


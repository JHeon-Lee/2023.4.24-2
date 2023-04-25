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
	string strName; // 이름
	ITEM_TYPE eType; // 종류
	string strDesc; // 설명
	int nAttribute; // 속성(방어력, 공격력, 회복량 등)
	int nPrice; // 가격
};

class cStock
{
protected:
	vector<tagItem> m_vecItem[ITEM_TYPE_NUM];
	vector<tagItem>::iterator m_vecIter;

public:
	cStock();
	~cStock();

	void AddItem(tagItem newItem); // 아이템 추가
	tagItem PickItem(ITEM_TYPE itemType, int index); // 아이템 꺼내기(삭제 및 정보 반환)
	vector<tagItem>& GetItemList(ITEM_TYPE itemType); // 아이템 목록 반환(요구 종류)
	void ShowItem(ITEM_TYPE itemType); // 아이템 목록 화면에 출력
};


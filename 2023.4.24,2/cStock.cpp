#include "pch.h"
#include "cStock.h"

cStock::cStock()
{
}

cStock::~cStock()
{
}

void cStock::AddItem(tagItem newItem)
{
	m_vecItem[newItem.eType].push_back(newItem); // 아이템 종류에 맞는 목록에 아이템을 추가한다
}

tagItem cStock::PickItem(ITEM_TYPE itemType, int index)
{
	tagItem findItem;

	// 해당 아이템 타입의 배열에서 선택 인덱스 위치의 아이템을 찾는다
	m_vecIter = m_vecItem[itemType].begin() + index;

	// 찾은 아이템 정보를 반환하기 위해서 담아놓는다.
	findItem = { m_vecIter->strName, m_vecIter->eType, m_vecIter->strDesc, m_vecIter->nAttribute, m_vecIter->nPrice };

	// 찾은 아이템은 삭제한다.
	m_vecItem[itemType].erase(m_vecIter);

	return findItem;
}

vector<tagItem>& cStock::GetItemList(ITEM_TYPE itemType)
{
	return m_vecItem[itemType];
}

void cStock::ShowItem(ITEM_TYPE itemType)
{
	int nNum = 1;

	for (m_vecIter = m_vecItem[itemType].begin(); m_vecIter != m_vecItem[itemType].end(); m_vecIter++)
	{
		cout << "======================" << endl;
		cout << nNum << "." << m_vecIter->strName;
		cout << "아이템 종류 : " << m_vecIter->eType << endl;
		cout << "아이템 설명 : " << m_vecIter->strDesc << endl;
		cout << "아이템 속성 : " << m_vecIter->nAttribute << endl;
		cout << "아이템 가격 : " << m_vecIter->nPrice << endl;
		cout << "======================" << endl;

		nNum++;
	}
}

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
	m_vecItem[newItem.eType].push_back(newItem); // ������ ������ �´� ��Ͽ� �������� �߰��Ѵ�
}

tagItem cStock::PickItem(ITEM_TYPE itemType, int index)
{
	tagItem findItem;

	// �ش� ������ Ÿ���� �迭���� ���� �ε��� ��ġ�� �������� ã�´�
	m_vecIter = m_vecItem[itemType].begin() + index;

	// ã�� ������ ������ ��ȯ�ϱ� ���ؼ� ��Ƴ��´�.
	findItem = { m_vecIter->strName, m_vecIter->eType, m_vecIter->strDesc, m_vecIter->nAttribute, m_vecIter->nPrice };

	// ã�� �������� �����Ѵ�.
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
		cout << "������ ���� : " << m_vecIter->eType << endl;
		cout << "������ ���� : " << m_vecIter->strDesc << endl;
		cout << "������ �Ӽ� : " << m_vecIter->nAttribute << endl;
		cout << "������ ���� : " << m_vecIter->nPrice << endl;
		cout << "======================" << endl;

		nNum++;
	}
}

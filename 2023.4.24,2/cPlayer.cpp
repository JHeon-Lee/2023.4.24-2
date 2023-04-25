#include "pch.h"
#include "cPlayer.h"

cPlayer::cPlayer(string name)
{
	m_strName = name;

	m_wearArmor.eType = ITEM_ARMOR;
	m_wearArmor.strName = "����";

	m_wearWeapon.eType = ITEM_WEAPON;
	m_wearWeapon.strName = "����";
	
	m_wearRing1.eType = ITEM_RING1;
	m_wearRing1.strName = "����";
	
	m_wearRing2.eType = ITEM_RING2;
	m_wearRing2.strName = "����";
}

cPlayer::~cPlayer()
{
}

void cPlayer::ShowAllItem()
{
	system("cls");

	cout << "======================================" << endl;
	cout << "���� �� : " << m_wearArmor.strName << endl;
	cout << "���� ���� : " << m_wearWeapon.strName << endl;
	cout << "���� ����1 : " << m_wearRing1.strName << endl;
	cout << "���� ����2 : " << m_wearRing2.strName << endl;
	cout << "======================================" << endl;

	m_myInven.ShowItem(ITEM_ARMOR);
	m_myInven.ShowItem(ITEM_WEAPON);
	m_myInven.ShowItem(ITEM_RING1);
	m_myInven.ShowItem(ITEM_RING2);

	system("pause");
}

#include "pch.h"
#include "cPlayer.h"

cPlayer::cPlayer(string name)
{
	m_strName = name;

	m_wearArmor.eType = ITEM_ARMOR;
	m_wearArmor.strName = "없음";

	m_wearWeapon.eType = ITEM_WEAPON;
	m_wearWeapon.strName = "없음";
	
	m_wearRing1.eType = ITEM_RING1;
	m_wearRing1.strName = "없음";
	
	m_wearRing2.eType = ITEM_RING2;
	m_wearRing2.strName = "없음";
}

cPlayer::~cPlayer()
{
}

void cPlayer::ShowAllItem()
{
	system("cls");

	cout << "======================================" << endl;
	cout << "착용 방어구 : " << m_wearArmor.strName << endl;
	cout << "착용 무기 : " << m_wearWeapon.strName << endl;
	cout << "착용 반지1 : " << m_wearRing1.strName << endl;
	cout << "착용 반지2 : " << m_wearRing2.strName << endl;
	cout << "======================================" << endl;

	m_myInven.ShowItem(ITEM_ARMOR);
	m_myInven.ShowItem(ITEM_WEAPON);
	m_myInven.ShowItem(ITEM_RING1);
	m_myInven.ShowItem(ITEM_RING2);

	system("pause");
}

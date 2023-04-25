#pragma once
#include "cInventory.h"

class cPlayer
{
private:
	string m_strName;

	cInventory m_myInven; // 인벤토리

	// 착용중인 아이템 목록
	tagItem m_wearArmor;
	tagItem m_wearWeapon;
	tagItem m_wearRing1;
	tagItem m_wearRing2;

	// 아이템 장착/해체는 플레이어 클래스에서 내부적으로 작동(인벤토리에서 아이템을 꺼내고 넣고)
	// void SetWearArmor();

public:
	cPlayer(string name);
	~cPlayer();

	string GetName() { return m_strName; }
	void ShowAllItem();

	// 인벤토리 클래스 반환
	cInventory& GetInventory() { return m_myInven; } // 인벤토리 클래스의 주솟값으로 반환하면 클래스에 직접 접근 가능

	// 장착중인 아이템 정보 반환
	tagItem GetWearArmor() { return m_wearArmor; }
};


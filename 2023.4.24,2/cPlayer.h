#pragma once
#include "cInventory.h"

class cPlayer
{
private:
	string m_strName;

	cInventory m_myInven; // �κ��丮

	// �������� ������ ���
	tagItem m_wearArmor;
	tagItem m_wearWeapon;
	tagItem m_wearRing1;
	tagItem m_wearRing2;

	// ������ ����/��ü�� �÷��̾� Ŭ�������� ���������� �۵�(�κ��丮���� �������� ������ �ְ�)
	// void SetWearArmor();

public:
	cPlayer(string name);
	~cPlayer();

	string GetName() { return m_strName; }
	void ShowAllItem();

	// �κ��丮 Ŭ���� ��ȯ
	cInventory& GetInventory() { return m_myInven; } // �κ��丮 Ŭ������ �ּڰ����� ��ȯ�ϸ� Ŭ������ ���� ���� ����

	// �������� ������ ���� ��ȯ
	tagItem GetWearArmor() { return m_wearArmor; }
};


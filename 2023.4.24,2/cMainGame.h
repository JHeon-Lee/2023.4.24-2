#pragma once
#include "cPlayer.h"
#include "cTown.h"
#include "cShop.h"

class cMainGame
{
private:
	cPlayer* m_pPlayer;
	LOCATION m_eCurrLoc; // ���� ĳ������ ��ġ ����

	cTown* m_pTown;
	cShop* m_pShop;

public:
	cMainGame();
	~cMainGame();

	void MainPlay();
};


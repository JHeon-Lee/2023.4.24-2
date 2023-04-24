#pragma once
#include "cPlayer.h"
#include "cTown.h"
#include "cShop.h"

class cMainGame
{
private:
	cPlayer* m_pPlayer;
	LOCATION m_eCurrLoc; // 현재 캐릭터의 위치 정보

	cTown* m_pTown;
	cShop* m_pShop;

public:
	cMainGame();
	~cMainGame();

	void MainPlay();
};


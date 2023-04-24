#pragma once
#include "cStock.h"
class cShop : public cStock
{
public:
	cShop();
	~cShop();

	void MainPlay(LOCATION& m_eCurrLoc);
};


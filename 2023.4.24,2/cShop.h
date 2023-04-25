#pragma once
#include "cStock.h"
#include "cInventory.h"

class cShop : public cStock
{
public:
	cShop();
	~cShop();

	void SetStock();
	void MainPlay(LOCATION& m_eCurrLoc, cInventory& inven);
};


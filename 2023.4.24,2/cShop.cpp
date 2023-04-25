#include "pch.h"
#include "cShop.h"

cShop::cShop()
{
}

cShop::~cShop()
{
}

void cShop::SetStock()
{
	tagItem item;

	item.eType = ITEM_ARMOR;
	item.strName = "반장의 찢어진 난닝구";
	item.nPrice = 100;
	item.nAttribute = 1;
	item.strDesc = "20년의 덕력과 함께한 늘어난 난닝구, 방어력 1상승";
	AddItem(item);

	item.eType = ITEM_ARMOR;
	item.strName = "전설의 가죽잠바";
	item.nPrice = 25000;
	item.nAttribute = 50;
	item.strDesc = "유명한 락커가 입었던 가죽 잠바, 방어령 50상승";
	AddItem(item);

	item.eType = ITEM_WEAPON;
	item.strName = "미미짱의 뿅망치";
	item.nPrice = 1000;
	item.nAttribute = -100;
	item.strDesc = "동네 여섯살짜리 꼬마(미미짱)에게 빼앗은 뿅망치, 공격력 100감소";
	AddItem(item);

	item.eType = ITEM_WEAPON;
	item.strName = "훈육 회초리";
	item.nPrice = 30000;
	item.nAttribute = 100;
	item.strDesc = "미미짱의 종아리를 때리며 성장한 회초리, 공격력 100증가";
	AddItem(item);

	item.eType = ITEM_RING1;
	item.strName = "봉춤녀의 반지";
	item.nPrice = 5000;
	item.nAttribute = 10;
	item.strDesc = "나이트에서 눈맞은 봉춤녀의 반지, 최대 HP 10증가";
	AddItem(item);

	item.eType = ITEM_RING1;
	item.strName = "골룸의 절대 반지";
	item.nPrice = 20000;
	item.nAttribute = 100;
	item.strDesc = "콜룸! 콜룸!, 최대 HP 100증가";
	AddItem(item);

	item.eType = ITEM_RING2;
	item.strName = "마녀의 마력 반지";
	item.nPrice = 1000;
	item.nAttribute = 20;
	item.strDesc = "사악한 마녀의 반지, 최대 MP 20증가";
	AddItem(item);

	item.eType = ITEM_RING2;
	item.strName = "잃어버린 결혼 반지";
	item.nPrice = 5000;
	item.nAttribute = 50;
	item.strDesc = "마법사 커플의 잃어버린 결혼 반지, 최대 MP 50증가";
	AddItem(item);

	item.eType = ITEM_HP;
	item.strName = "발효된 우유";
	item.nPrice = 10;
	item.nAttribute = -10;
	item.strDesc = "127일된 신맛 우유, 체력 10감소";
	for (int i = 0; i < 100; i++)
		AddItem(item);

	item.eType = ITEM_MP;
	item.strName = "멀쩡한 바나나 우유";
	item.nPrice = 20;
	item.nAttribute = 50;
	item.strDesc = "맛있는 바나나 우유, 마나 50증가";
	for (int i = 0; i < 100; i++)
		AddItem(item);
}

void cShop::MainPlay(LOCATION& m_eCurrLoc, cInventory& inven)
{
	int nSelect;
	cout << "==========================================" << endl;
	cout << "= 상점 = 1. 마을로 돌아가기 2. 구매 3. 판매" << endl;
	cout << "==========================================" << endl;
	cout << " : ";
	cin >> nSelect;

	switch (nSelect)
	{
		case 1:
		{
			m_eCurrLoc = LOCATION_TOWN;
		}
		break;
		case 2:
		{
			cout << "=============================================" << endl;
			cout << "= 구매 = 1. 방어구 2. 무기 3. 반지1 4. 반지2 =" << endl;
			cout << "=============================================" << endl;
			cout << " : ";
			cin >> nSelect;

			ITEM_TYPE eType = (ITEM_TYPE)(nSelect - 1);
			this->ShowItem(eType);

			cout << "구매 번호(0. 취소) : ";
			cin >> nSelect;

			if (nSelect > 1 && nSelect <= this->GetItemList(eType).size())
			{
				tagItem buyItem = this->PickItem(eType, nSelect - 1); // 상점에서 아이템 꺼내기
				inven.AddItem(buyItem); // 인벤토리에 아이템 넣기

				cout << endl << " >>>>>>>>>>>>>>>>.[" << buyItem.strName << "]를(을) 구매 하였습니다." << endl << endl;
				system("pause");
			}
		}
		break;
		case 3:
		{
			cout << "=============================================" << endl;
			cout << "= 판매 = 1. 방어구 2. 무기 3. 반지1 4. 반지2 =" << endl;
			cout << "=============================================" << endl;
			cout << " : ";
			cin >> nSelect;

			ITEM_TYPE eType = (ITEM_TYPE)(nSelect - 1);
			inven.ShowItem(eType);

			cout << "판매 번호(0. 취소) : ";
			cin >> nSelect;

			if (nSelect > 1 && nSelect <= inven.GetItemList(eType).size())
			{
				tagItem sellItem = inven.PickItem(eType, nSelect - 1);
				this->AddItem(sellItem);

				cout << endl << " >>>>>>>>>>>>>>>>.[" << sellItem.strName << "]를(을) 판매 하였습니다." << endl << endl;
				system("pause");
			}
		}
		break;
		default:
		{

		}
		break;
	}
}

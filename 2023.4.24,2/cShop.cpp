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
	item.strName = "������ ������ ���ױ�";
	item.nPrice = 100;
	item.nAttribute = 1;
	item.strDesc = "20���� ���°� �Բ��� �þ ���ױ�, ���� 1���";
	AddItem(item);

	item.eType = ITEM_ARMOR;
	item.strName = "������ �������";
	item.nPrice = 25000;
	item.nAttribute = 50;
	item.strDesc = "������ ��Ŀ�� �Ծ��� ���� ���, ���� 50���";
	AddItem(item);

	item.eType = ITEM_WEAPON;
	item.strName = "�̹�¯�� �и�ġ";
	item.nPrice = 1000;
	item.nAttribute = -100;
	item.strDesc = "���� ������¥�� ����(�̹�¯)���� ������ �и�ġ, ���ݷ� 100����";
	AddItem(item);

	item.eType = ITEM_WEAPON;
	item.strName = "���� ȸ�ʸ�";
	item.nPrice = 30000;
	item.nAttribute = 100;
	item.strDesc = "�̹�¯�� ���Ƹ��� ������ ������ ȸ�ʸ�, ���ݷ� 100����";
	AddItem(item);

	item.eType = ITEM_RING1;
	item.strName = "������� ����";
	item.nPrice = 5000;
	item.nAttribute = 10;
	item.strDesc = "����Ʈ���� ������ ������� ����, �ִ� HP 10����";
	AddItem(item);

	item.eType = ITEM_RING1;
	item.strName = "����� ���� ����";
	item.nPrice = 20000;
	item.nAttribute = 100;
	item.strDesc = "�ݷ�! �ݷ�!, �ִ� HP 100����";
	AddItem(item);

	item.eType = ITEM_RING2;
	item.strName = "������ ���� ����";
	item.nPrice = 1000;
	item.nAttribute = 20;
	item.strDesc = "����� ������ ����, �ִ� MP 20����";
	AddItem(item);

	item.eType = ITEM_RING2;
	item.strName = "�Ҿ���� ��ȥ ����";
	item.nPrice = 5000;
	item.nAttribute = 50;
	item.strDesc = "������ Ŀ���� �Ҿ���� ��ȥ ����, �ִ� MP 50����";
	AddItem(item);

	item.eType = ITEM_HP;
	item.strName = "��ȿ�� ����";
	item.nPrice = 10;
	item.nAttribute = -10;
	item.strDesc = "127�ϵ� �Ÿ� ����, ü�� 10����";
	for (int i = 0; i < 100; i++)
		AddItem(item);

	item.eType = ITEM_MP;
	item.strName = "������ �ٳ��� ����";
	item.nPrice = 20;
	item.nAttribute = 50;
	item.strDesc = "���ִ� �ٳ��� ����, ���� 50����";
	for (int i = 0; i < 100; i++)
		AddItem(item);
}

void cShop::MainPlay(LOCATION& m_eCurrLoc, cInventory& inven)
{
	int nSelect;
	cout << "==========================================" << endl;
	cout << "= ���� = 1. ������ ���ư��� 2. ���� 3. �Ǹ�" << endl;
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
			cout << "= ���� = 1. �� 2. ���� 3. ����1 4. ����2 =" << endl;
			cout << "=============================================" << endl;
			cout << " : ";
			cin >> nSelect;

			ITEM_TYPE eType = (ITEM_TYPE)(nSelect - 1);
			this->ShowItem(eType);

			cout << "���� ��ȣ(0. ���) : ";
			cin >> nSelect;

			if (nSelect > 1 && nSelect <= this->GetItemList(eType).size())
			{
				tagItem buyItem = this->PickItem(eType, nSelect - 1); // �������� ������ ������
				inven.AddItem(buyItem); // �κ��丮�� ������ �ֱ�

				cout << endl << " >>>>>>>>>>>>>>>>.[" << buyItem.strName << "]��(��) ���� �Ͽ����ϴ�." << endl << endl;
				system("pause");
			}
		}
		break;
		case 3:
		{
			cout << "=============================================" << endl;
			cout << "= �Ǹ� = 1. �� 2. ���� 3. ����1 4. ����2 =" << endl;
			cout << "=============================================" << endl;
			cout << " : ";
			cin >> nSelect;

			ITEM_TYPE eType = (ITEM_TYPE)(nSelect - 1);
			inven.ShowItem(eType);

			cout << "�Ǹ� ��ȣ(0. ���) : ";
			cin >> nSelect;

			if (nSelect > 1 && nSelect <= inven.GetItemList(eType).size())
			{
				tagItem sellItem = inven.PickItem(eType, nSelect - 1);
				this->AddItem(sellItem);

				cout << endl << " >>>>>>>>>>>>>>>>.[" << sellItem.strName << "]��(��) �Ǹ� �Ͽ����ϴ�." << endl << endl;
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

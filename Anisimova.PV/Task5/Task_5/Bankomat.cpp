#include <iostream>
#include <cmath>
#include <algorithm>
#include "pch.h"
#include<clocale>
#include <string>
#include "Bankomat.h"
using namespace std;

Bankomat::Bankomat()
{
	ifstream is;
	is.open("E:/github/IiP_381808-1/Anisimova.PV/Task5/Bank.txt");
	is >> *PrCn;
	is.close();
	
}
void Bankomat::FindByNumberCard(int _NumberCard)
{
	NumberCard1 = _NumberCard;	
	PrCn->FindClientInTheDatabase(NumberCard1, Name1, Surname1, Patronymic1, Sum1, PIN1, IsBlock1);
}
int Bankomat::CheckPIN(int _PIN)
{
	if (PIN1 == _PIN)
	{
		return 0;
	}
	else {		
		cout << "Wrong pin code " << endl;
		int pin;
		cin >> pin;
        if (PIN1 == pin)
     	{
		return 0;
	    }
		else {
			cout << "Wrong pin code " << endl;
			int pin;
			cin >> pin;
			if (PIN1 == pin)
			{
				return 0;
			}
			else
			{	IsBlock1 = 0;
				cout << "Your card is blocked" << endl;
				return 0;
			}
		}		
    }
}
void Bankomat::ShowSum()
{
	cout << Sum1 << endl;
}
int Bankomat::GetSum(int sum)
{
	if (Sum1 - sum < 0)
		return 1;
	if (sum > (money[1] * 100 + money[2] * 200 + money[3] * 500 + money[4] * 1000 + money[5] * 2000 + money[6] * 5000) || (sum > 200000))
	{
		cout << "Limit is exceeded" << endl;
		return 1;
	}
	Sum1 -= sum;

	if (sum >= 5000)
	{
		sum -= 5000;
		money[6]--;
	}
	else
	{
		if (sum >= 2000)
		{
			sum -= 2000;
			money[5]--;
		}
		else
		{
			if (sum >= 1000)
			{
				sum -= 1000;
				money[4]--;
			}
			else
			{
				if (sum >= 500)
				{
					sum -= 500;
					money[3]--;
				}
				else
				{
					if (sum >= 200)
					{
						sum -= 200;
						money[2]--;
					}
					else
					{
						if (sum >= 100)
						{
							sum -= 100;
							money[1]--;
						}
					}
				}
			}
		}
	}

	PrCn->ChangeClientInfo(Sum1, NumberCard1);
	ofstream os;
	os.open("E:/github/IiP_381808-1/Anisimova.PV/Task5/Bank.txt");
	os << PrCn;
	os.close();
}

int Bankomat::BringInSum(int sum)
{
	if (sum > 200000)
	{
		cout << "Limit is exceeded" << endl;
		return 1;
	}
	Sum1 += sum;

	if (sum >= 5000)
	{
		sum -= 5000;
		money[6]++;
	}
	else
	{
		if (sum >= 2000)
		{
			sum -= 2000;
			money[5]++;
		}
		else
		{
			if (sum >= 1000)
			{
				sum -= 1000;
				money[4]++;
			}
			else
			{
				if (sum >= 500)
				{
					sum -= 500;
					money[3]++;
				}
				else
				{
					if (sum >= 200)
					{
						sum -= 200;
						money[2]++;
					}
					else
					{
						if (sum >= 100)
						{
							sum -= 100;
							money[1]++;
						}
					}
				}
			}
		}
	}

	PrCn->ChangeClientInfo(Sum1, NumberCard1);
	ofstream os;
	os.open("E:/github/IiP_381808-1/Anisimova.PV/Task5/Bank.txt");
	os << PrCn;
	os.close();
}

int Bankomat::CheckCardBlock()
{
	return IsBlock1;
}
void Bankomat::CrdRtn()
{
	NumberCard1 =Sum1 =PIN1 =IsBlock1 =WrongPIN1 = 0;
	Name1=Surname1=Patronymic1 = "";
}







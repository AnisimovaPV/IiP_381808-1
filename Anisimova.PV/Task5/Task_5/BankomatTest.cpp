#include "pch.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <clocale>
#include<fstream>
#include<string>
#include "Bankomat.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	
		int NumberCard, PIN, Sum;
		Bankomat B;
		cout << "Enter the number of card and pin code" << endl;
	
		cin >> NumberCard>>PIN;
		B.FindByNumberCard(NumberCard);

		while (B.CheckPIN(PIN) != 0)
		{
			cin >> PIN;
		}
		
		if (B.CheckCardBlock() == 1) return 0;
		
		bool flag =true;
		while (flag)
		{	//Menu
		cout << "Menu:" << '\n' <<
			"1. Show money on the card" << '\n' <<
			"2. Deposit money on the card" << '\n' <<
			"3. Get money from the card" << '\n' <<
			"0. Exit " << '\n';	
			int var;
			cin >> var;
			switch (var)
			{
			case 1:
			{
				B.ShowSum();
				break;
			}
			case 2:
			{
				do 
				{
					bool fl = true;
					while (fl)
					{
						cout << "Enter the amount  " << endl;
						cin >> Sum;
						if (Sum % 100 != 0)
						{
							cout << "Incorrect the amount entered " << endl;

						}
						else fl = false;
					}
				} 
				while (B.BringInSum(Sum) == 1) ;
				break;
			}
			case 3:
			{
				do
				{
					bool fl = true;
					while (fl)
					{
						cout << "Enter the amount  " << endl;
						cin >> Sum;
						if (Sum % 100 != 0)
						{
							cout << "Incorrect the amount entered " << endl;
						}
						else fl = false;
					}
				} while (B.GetSum(Sum) == 1);
				break;
			}
			case 0:
			{
				flag = false;
				B.CrdRtn();
				break;
			}
			}
		}
		return 0;
}
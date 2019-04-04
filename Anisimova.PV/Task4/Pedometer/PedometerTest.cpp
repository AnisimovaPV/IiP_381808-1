#include "pch.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <clocale>
#include<fstream>
#include<string>
#include "Pedometer.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int d1,m1,y1,H1,Min1;

	//Starting date and time 
	cout << "Vvedite nachal'nuyu daty " << endl;
	cin >> d1 >> m1 >> y1>>H1>> Min1;
	
	int d, m, y, h1, min1, h2, min2, step;
	cout << "How many counting do you want to add?" << endl;
	int size;
	cin >> size;
	Pedometer P(size, d1, m1, y1, H1, Min1);

	for (int i = 0; i < size; i++)
	{
		cin >> d >> m >> y >> h1 >> min1 >> h2 >> min2 >> step;
		P.AddPodschet(d, m, y, h1, min1, h2, min2, step);
	}
	//Menu
	for (;;) 
	{
	    cout << "Menu:" << '\n' <<
		"1. The starting date and time count" << '\n' <<
		"2. Add count" << '\n' <<
		"3. Information on counting by date and time" << '\n' <<
		"4. Аverage number of steps in the selected month" << '\n' <<
		"5. Аverage number of steps for all observation" << '\n' <<
		"6. Maximum number of steps in the selected month " << '\n' <<
		"7. Maximum number of steps for all observation " << '\n' <<
		"0. Exit " << '\n';
	
		bool flag = false;
		int var;
		cin >> var;

		switch (var)
		{
		case 1:
		{  
		cout << P.GetD()  << "." << P.GetM()    << "." << P.GetY()  <<" "<<
			    P.GetH1() << ":" << P.GetMin1() << endl;
		break;
		}
		case 2:
		{
			cin >> d >> m >> y >> h1 >> min1 >> h2 >> min2 >> step;
			P.AddPodschet(d, m, y, h1, min1, h2, min2, step);
			break;
		}
		case 3:
		{
			cin >> d >> m >> y >> h1 >> min1 >> h2 >> min2;
			cout << P.GetInfPodschet(d, m, y, h1, min1, h2, min2) << endl;
			break;
		}
		case 4:
		{
			cin >> m;
			cout << P.AverStepsMonth(m) << endl;
			break;
		}
		case 5:
		{
			cout << P.AverStepsAll() << endl;
			break;
		}
		case 6:
		{
			cin >> m;
			cout << P.MaxStepsMonth(m) << endl;
			break;
		}
		case 7:
		{
			cout << P.MaxStepsAll()<<endl;
			break;
		}
		case 0:
		{ 
			flag = true;
			break;
		}
		}
		if (flag==true) break;
	}
	//zapis' v fail
	ofstream os("Pedometer.txt");
	os << P;
	os.close();

	//chtenie  faila
	ifstream is("Pedometer.txt");
	is >> P;
	is.close();
	return 0;
}

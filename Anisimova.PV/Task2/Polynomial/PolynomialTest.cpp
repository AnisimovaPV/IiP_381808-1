#include "pch.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <clocale>
#include<fstream>
#include<string>
#include "Polynomial.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n;

	//������� �������� � ��������� �� [0,12]
	 do
   	{
	 cout << "������� ������� �������� P � ��������� [0,12] " << '\n';
     cin >> n;
	 } 
	 while (n<0 || n>12);
	
	
	 Polynomial P(n);
	cout << "������� ������������ ������� ��������: " << '\n';
	cin >> P;

	cout << "������� P:  " <<  P << '\n';

	cout << "������� �������� =  "  << P.Setn() << '\n';

	cout << "������� ����� ��������, ����������� �������� ����� ������" << '\n';
	int i;
	cin >> i;
	cout << "����������� = " << P.SetCoeff(i - 1) << '\n';

	cout << "������� �������� � = " << '\n';
	int x;
	cin >> x;
	cout << "�������� �������� ��� �������� � = " << P.Ans(x) << '\n';

	cout << "����������� ��������= :" << P.Deriv() << '\n';




	//zapis' v fail
	ofstream os("Polynomial.txt");
	os << P;
	os.close();

	//chtenie  faila
	ifstream is("Polynomial.txt");
	is >>P;
	cout << "������ �� ����� : " << P <<endl;	
	
	return 0;
}
#include"pch.h"
#include <cmath>
#include <clocale>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "ProcCenter.h"
using namespace std;

void ProcCenter::FindClientInTheDatabase(int  _NumberCard, string &_Name, string &_Surname, string &_Patronymic, int &_Sum, int &_PIN, bool &_IsBlock)
{
	for (int i = 0; i < CntCl; i++)
	{
		if (NumberCard[i] == _NumberCard)
		{
			_Name = Name[i] ;
			_Surname=Surname[i]  ;
			_Patronymic=Patronymic[i] ;
			_Sum=Sum[i];
			_PIN=PIN[i];
			_IsBlock=IsBlock[i];
		}
	}
}
void ProcCenter::ChangeClientInfo(int _Sum,int _NumberCard)
{
	for (int i = 0; i < CntCl; i++)
	{
		if (NumberCard[i] == _NumberCard)
			Sum[i] = _Sum;
	}
}
ostream& operator<<(ostream& stream, const ProcCenter &a)
{
  stream.clear();
  stream << a.CntCl << " ";

  for (int i = 0; i < a.CntCl; i++)
  {
	stream << a.NumberCard[i] << " " << a.Surname[i] << " " << a.Name[i] << " " << a.Patronymic[i]
		   << " " << a.Sum[i] << " " << a.PIN[i] << " " << a.IsBlock[i] << " " ;
  }
return stream;
}

istream & operator>>(istream & stream, ProcCenter &a)
{
	stream >> a.CntCl;
	int Count = a.CntCl;

	delete[] a.NumberCard;
	delete[] a.Surname;
	delete[] a.Name;
	delete[] a.Patronymic;
	delete[] a.Sum;
	delete[] a.PIN;
	delete[] a.IsBlock;

	a.NumberCard = new int[Count];
	a.Surname = new string[Count];
	a.Name = new string[Count];
	a.Patronymic = new string[Count];
	a.Sum = new int[Count];
	a.PIN = new int[Count];
	a.IsBlock = new bool[Count];

	for (int i = 0; i < a.CntCl; i++)
	{
		stream>> a.NumberCard[i] >> a.Surname[i] >> a.Name[i] >> a.Patronymic[i]
			>> a.Sum[i] >> a.PIN[i] >> a.IsBlock[i] ;
	}
	return stream;
}
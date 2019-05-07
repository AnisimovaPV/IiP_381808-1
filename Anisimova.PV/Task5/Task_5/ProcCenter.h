#pragma once
#include <iostream>
#include <fstream>
#include "pch.h"
#include <clocale>
using namespace std;

class ProcCenter
{
	int    *NumberCard;
	string *Name;
	string *Surname;
	string *Patronymic;
	int    *Sum;
	int    *PIN;
	bool   *IsBlock;
	int    *WrongPIN;

	int CntCl; //Count client

public:
	void FindClientInTheDatabase(int _NumberCard, string &_Name, string &_Surname, string &_Patronymic,int &_Sum,int &_PIN,	bool &_IsBlock);
	void ChangeClientInfo(int _Sum, int _NumberCard);  //changes client information

	friend ostream & operator << (ostream & stream, const ProcCenter &a);
	friend istream & operator >> (istream & stream, ProcCenter &a);
};
ostream& operator << (ostream & stream, const ProcCenter &a); //Peregryzka vyvoda
istream& operator >> (istream & stream, ProcCenter &a);       //Peregryzka vvoda
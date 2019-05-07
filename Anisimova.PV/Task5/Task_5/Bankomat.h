#pragma once
#include <iostream>
#include <fstream>
#include "pch.h"
#include <clocale>
#include"ProcCenter.h"

using namespace std;

class Bankomat
{	
	ProcCenter *PrCn=new ProcCenter();
	const int MaxMoney = 2000;                                     //maximum amount of one denomination bills
	int money[6] = {1600,1600,1600,1600,1600,1600};                //denomination of a bill
	const int MaxGetGive = 40;                                     //maximum number of bills to get/to give
	//Information about Client
	int  NumberCard1;
	string Name1;
	string Surname1;
	string Patronymic1;
	int Sum1;
	int PIN1;      //pin code
	bool IsBlock1; //card status 
	int WrongPIN1; 

public:
	// Konstryktory--------------------------
	Bankomat();       // default	

	void FindByNumberCard(int _NumberCard);  //Find client by number card
	int CheckPIN(int _PIN);                  //pincode correctness
	void ShowSum();                          //show money on the card
	int GetSum(int _sum);                  //get money from the card
	int BringInSum(int _sum);              //deposit money on the card
	int CheckCardBlock();                    //card status 
	void CrdRtn();                           //Return card
};
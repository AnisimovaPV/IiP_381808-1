#pragma once
#include <iostream>
#include <fstream>
#include "pch.h"
#include <clocale>
using namespace std;

class Pedometer
{  //Starting date
	int d1;
	int m1;
	int y1;
	int H1;
	int Min1;
	
	int *d;
	int *m;
	int *y;
	int *h1;
	int *min1;
	int *h2;
	int *min2;
	int *steps;

	int size;                 //current memory size
	int buf;                  //allocated memory size
	const int bufDelta = 10;  //memory size if size>=buf

public:
	// Konstryktory--------------------------
	Pedometer();                                                                // default
	Pedometer(int _size, int _d1, int _m1, int _y1, int _H1, int _Min1);        // initsializator1
	Pedometer(const Pedometer &);                                               // ñopy	
	//Destryktor---------------------------
	~Pedometer();

	//Vozvrat starting date and time
	int GetD();
	int GetM();
	int GetY();
	int GetH1();
	int GetMin1();
	
	void AddPodschet(int _d, int _m, int _y, int _h1, int _min1, int _h2, int _min2, int _steps);    // add podschet
	int GetInfPodschet(int _d, int _m, int _y, int _h1, int _min1, int _h2, int _min2);              // information about podschet
	double AverStepsMonth(int _m);                                                                   // average steps month
	double AverStepsAll();                                                                           // averege steps all
	int	MaxStepsMonth(int _m) ;
	int MaxStepsAll();	

	friend ostream & operator << (ostream & stream, const Pedometer &a);
	friend istream & operator >> (istream & stream, Pedometer &a);
};
ostream& operator << (ostream & stream, const Pedometer &a); //Peregryzka vyvoda
istream& operator >> (istream & stream, Pedometer &a);       //Peregryzka vvoda
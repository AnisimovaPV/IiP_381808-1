#include <iostream>
#include <cmath>
#include <algorithm>
#include "pch.h"
#include<clocale>
#include "Pedometer.h"
using namespace std;

//Konstryktor
Pedometer::Pedometer()
{	
	d= NULL;
	m= NULL;
	y= NULL; 
	h1= NULL;
	h2= NULL;
	min1= NULL; 
	min2= NULL;
	steps= NULL;
	size = d1 = m1 = y1 = H1 = Min1 = 0;
}
Pedometer::Pedometer(int _size,int _d1,int _m1, int _y1,int _H1,int _Min1)
{   d1 = _d1;
	m1 = _m1;
	y1 = _y1;
    H1=_H1;
	Min1=_Min1;
	
	d = new int[buf];
	m = new int[buf];
	y = new int[buf];
	h1 = new int[buf];
	h2 = new int[buf];
	min1 = new int[buf];
	min2 = new int[buf];
	steps= new int[buf];   
	size = 0;

}
Pedometer::Pedometer(const Pedometer& p)
{
	size = p.size;
	d = new int[buf];
	m = new int[buf];
	y = new int[buf];
	h1 = new int[buf];
	h2 = new int[buf];
	min1 = new int[buf];
	min2 = new int[buf];
	steps = new int[buf];

	for (int i = 0; i < size; i++)
	{
		d[i] = p.d[i];
		m[i] = p.m[i];
		y[i] = p.y[i];
		h1[i] = p.h1[i];
		min1[i] = p.min1[i];
		h2[i] = p.h2[i];
		min2[i] = p.min2[i];
		steps[i] = p.steps[i];
	}
}
//Destryktor
Pedometer::~Pedometer()
{
    delete[] d;	
	delete[] m;
	delete[] y;
	delete[] h1;
	delete[] min1;
	delete[] h2;
	delete[] min2;
	delete[] steps;
    d = m = y = h1 = h2 = min1 = min2 = steps = NULL;
	d1 = m1 = y1 = H1 = Min1  = size = 0;

}
//Vozvrat starting date and time
int Pedometer::GetD()
{
	return d1;
}
int Pedometer::GetM()
{
	return m1;
}
int Pedometer::GetY()
{
	return y1;
}
int Pedometer::GetH1()
{
	return H1;
}
int Pedometer::GetMin1()
{
	return Min1;
}

void Pedometer::AddPodschet(int _d, int _m, int _y, int _h1, int _min1, int _h2, int _min2, int _steps)
{
	for (int i = size; i < size+1; i++)
	{
		d[i] = _d;
		m[i] = _m;
		y[i] = _y;
		h1[i] = _h1;
		min1[i] = _min1;
		h2[i] = _h2;
		min2[i] = _min2;
		steps[i] = _steps;
	}
	size++;

}

int Pedometer::GetInfPodschet(int _d, int _m, int _y, int _h1, int _min1, int _h2, int _min2)
{
	for (int i = 0; i < size; i++)
		if ( _d == d[i] && _m == m[i] &&_y == y[i] && 
			_h1 == h1[i] && _min1 == min1[i] && _h2 == h2[i] && _min2 == min2[i])
		{
			return steps[i];
		}
}

double Pedometer::AverStepsMonth(int _m)
{
	int stp = 0;
	int n = 0;
	for (int i = 0; i < size; i++)
	{
		if (_m == m[i])
		{
			stp += steps[i];
			n++;
		}
	}
	double aver = stp / n;
	return aver;
}

double	Pedometer::AverStepsAll()
{
	int stp = 0;
	for (int i = 0; i < size; i++) 
	{
		stp += steps[i];
	}

	double aver = stp / size;
	return aver;
}

int	Pedometer::MaxStepsMonth(int _m) 
{
	int stp = 0;
	for (int i = 0; i < size; i++)
	{
		if (_m == m[i])
		{
			if (steps[i] >= stp)
				stp = steps[i];
		}
	}
	return stp;
}

int Pedometer::MaxStepsAll() 
{
	int stp = 0;
	for (int i = 0; i < size; i++)
	{
		if (steps[i] >= stp)
			stp = steps[i];
	}
	return stp;
}

//vvod
ostream & operator << (ostream & stream, const Pedometer &p)
{
	stream << "Size= " << p.size << endl;
	stream <<"Starting date " <<p.d1 << "." << p.m1 << "." << p.y1 <<" "<< p.H1 << ":" <<p.Min1<<endl;
	stream << "Information: " << endl;

	for (int i = 0; i < p.size; i++)
	{
	  stream << p.d[i]    << "."  << p.m[i]     << "."  << p.y[i]  << "  "<<
		       	p.h1[i]   << ":"  << p.min1[i]  << "  " << p.h2[i] << ":" <<
			    p.min2[i] << "  " << p.steps[i] << "  " << endl;
	}	
	return stream;
}

istream & operator >> (istream & stream, Pedometer &p)
{
	int size1,D1,M1,Y1;
	stream >> size1;
	stream >> D1 >> M1 >> Y1;
	p.size = size1;
	p.d1 = D1;
	p.m1 = M1;
	p.y1 = Y1;

	for (int i = 0; i < p.size; i++)
	{
		stream >>p.d[i]    >> p.m[i]    >> p.y[i]  >>
			     p.h1[i]   >> p.min1[i] >> p.h2[i] >> p.min2[i] >> p.steps[i] ;
	}	
	return stream;
}


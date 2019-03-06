#pragma once
#include <iostream>
#include <fstream>
#include <clocale>
using namespace std;

class Polynomial
{
public:
	int n;            //������� ��������
	int *coefficient; //��������� �� ������ ������������� ������� �������� 

	// ������������--------------------------
	Polynomial();                   //�� ���������
	Polynomial(int);                //��������������
	Polynomial(const Polynomial &); //�����������
	//����������---------------------------
	~Polynomial();

	// Metody -----------------------------
	int Setn();                              //������/������ ������� ��������
	int SetCoeff(int);                       //������ �������� ������������ �� ��� ������
	int Ans(int x);                          //�������� �������� � �������� ����� �
	Polynomial Deriv();                      //����������� ��������
	Polynomial operator=(const Polynomial&); //�������� ������������
	
	//������� �����/������
	friend ostream & operator << (ostream & stream, const Polynomial &a);
	friend istream & operator >> (istream & stream, Polynomial &a);
};
ostream& operator<<(ostream & stream, const Polynomial &a);//���������� ������
istream& operator >> (istream & stream, Polynomial &a);    //���������� �����

/*
������� ����� Pair (���� �����);
���������� ������ ��������� ����� � ���������� ������������ �����.
���������� ����������� ����� RightAngled (������������� �����������) � ������-��������.
���������� ������ ���������� ���������� � ������� ������������.
*/
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
using namespace std;
class Pair
{
protected:
	int a, b;
public:
	void Set(int a1, int b1)
	{
		a = a1; b = b1;
	}
	int Mult()
	{
		return (a*b);
	}
};

class RightAngled :public Pair
{
public:
	float Gip()
	{
		return (sqrt(pow(a, 2) + pow(b, 2)));
	}
	int Squer()
	{
		return Mult()*1/2;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	int a, b;
	RightAngled obj;
	cout << "������� ������ �����: ";
	cin >> a;
	cout << "������� ������ �����: ";
	cin >> b;
	obj.Set(a, b);
	cout << "����������: " << obj.Gip() << endl;
	cout << "�������: " << obj.Squer() << endl;
	system("Pause");
}
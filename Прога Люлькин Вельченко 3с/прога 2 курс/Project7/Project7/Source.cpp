#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	TimeFull New;
	TimeL New2;
	cout << "������� ����� � ������� �����: " << New2 << endl;
	cout << "������� ����� � ������ �����: " << New << endl;
	TimeFull New3c(10, 56, 34);
	TimeL New4c(10, 56, 34);
	cout << "�������� ����� � ������� �����: " << New4c << endl;
	cout << "�������� ����� � ������ �����: " << New3c << endl;
}
//Bus: ������� � �������� ��������, ����� ��������, ����� ��������, �����, ��� ������ ������������, ������. ������� ������ ��������. ������� :
//	�) ������ ��������� ��� ��������� ������ ��������;
//	�) ������ ���������, ������� ��������������� ������ 10 ���;
//	�) ������ ���������, ������ � ������� ������ 10 000 ��.

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include<fstream>
using namespace std;

class Bus {
	char surname[50];
	char initials[50];
	char busnumber[50];
	int routnumber;
	char model[50];
	int year;
	int mileage;
	int rout;
public:
	void show();
	void set_rout(int);
	void get_info();
	void routlist();
	void yearlist();
	void mileagelist();

	//friend ostream &operator<< (ostream &stream, Bus bus) {
	//	stream << " " << bus.num << " " << bus.surname << " " << bus.group<< " " << bus.balls;
	//	return stream;
	//}
	//friend istream &operator>> (istream &stream, Bus &bus) {
	//	stream >> bus.num >> bus.surname >> bus.group >> bus.balls;
	//	return stream;
	//}

};

void Bus::set_rout(int a) {
	rout = a;
}

void Bus::get_info() {
	ifstream fin("struct.txt");
	try {
		if (!fin) throw 1;
	}
	catch (int mthrow) { cout << "No memory!" << endl; return; }
	ofstream fout("structBin.txt", ios::binary);
	Bus bus;
	while (fin) {
		fin >> bus.surname;  if (!fin)break;
		fin >> bus.initials;
		fin >> bus.busnumber;
		fin >> bus.routnumber;
		fin >> bus.model;
		fin >> bus.year;
		fin >> bus.mileage;
		fout.write((char*)&bus, sizeof(Bus));
	}
	fin.close();
	fout.close();
}


void Bus::show()
{
	ifstream fin("structBin.txt", ios::binary);
	ofstream fout("result.txt", ios::binary);
	try {
		if (!fin) throw 1;
	}
	catch (int mthrow) { cout << "No memory!" << endl; return; }
	Bus bus;
	while (fin) {
		fin.read((char*)&bus, sizeof(Bus));
		if (fin)cout << "�������: " << bus.surname << endl 
			<< "��������: " << bus.initials << endl 
			<< "����� ��������: " << bus.busnumber << endl 
			<< "����� ��������: " << bus.routnumber << endl 
			<< "�����: " << bus.model << endl 
			<< "��� ������ ������������: " << bus.year << endl 
			<< "������: " << bus.mileage << endl;
		cout << endl;
		if (fin)fout << "\r\n" << "�������: " << bus.surname << setw(8)
			<< " ��������: " << bus.initials << setw(8)
			<< " ����� ��������: " << bus.busnumber << setw(8)
			<< " ����� ��������: " << bus.routnumber << setw(8)
			<< " �����: " << bus.model << setw(8)
			<< " ��� ������ ������������: " << bus.year << setw(8)
			<< " ������: " << bus.mileage << endl;
	}
	cout << endl;
	fout.close();
	fin.close();
}


void Bus::routlist()
{
	ifstream fin("structBin.txt", ios::binary);
	ofstream fout("result.txt", ios::binary);
	try {
		if (!fin) throw 1;
	}
	catch (int mthrow) { cout << "No memory!" << endl; return; }
	Bus bus;
	cout << "\n ������ ��������� � �������� ������� ��������:\n" << endl;
	while (fin) {
		fin.read((char*)&bus, sizeof(Bus));
		if (bus.routnumber!=rout) continue;
		if (fin)cout << "�������: " << bus.surname << endl
			<< "��������: " << bus.initials << endl
			<< "����� ��������: " << bus.busnumber << endl
			<< "����� ��������: " << bus.routnumber << endl
			<< "�����: " << bus.model << endl
			<< "��� ������ ������������: " << bus.year << endl
			<< "������: " << bus.mileage << endl;
		cout << endl;
		if (fin)fout << "\r\n" << "�������: " << bus.surname << setw(8)
			<< " ��������: " << bus.initials << setw(8)
			<< " ����� ��������: " << bus.busnumber << setw(8)
			<< " ����� ��������: " << bus.routnumber << setw(8)
			<< " �����: " << bus.model << setw(8)
			<< " ��� ������ ������������: " << bus.year << setw(8)
			<< " ������: " << bus.mileage << endl;
	}
	cout << endl;
	fout.close();
	fin.close();
}

void Bus::yearlist()
{
	ifstream fin("structBin.txt", ios::binary);
	ofstream fout("result.txt", ios::binary);
	try {
		if (!fin) throw 1;
	}
	catch (int mthrow) { cout << "No memory!" << endl; return; }
	Bus bus;
	cout << "\n ������ ���������, ������� ��������������� ������ 10 ���:\n" << endl;
	while (fin) {
		fin.read((char*)&bus, sizeof(Bus));
		if (2018-bus.year<=10) continue;
		if (fin)cout << "�������: " << bus.surname << endl
			<< "��������: " << bus.initials << endl
			<< "����� ��������: " << bus.busnumber << endl
			<< "����� ��������: " << bus.routnumber << endl
			<< "�����: " << bus.model << endl
			<< "��� ������ ������������: " << bus.year << endl
			<< "������: " << bus.mileage << endl;
		cout << endl;
		if (fin)fout << "\r\n" << "�������: " << bus.surname << setw(8)
			<< " ��������: " << bus.initials << setw(8)
			<< " ����� ��������: " << bus.busnumber << setw(8)
			<< " ����� ��������: " << bus.routnumber << setw(8)
			<< " �����: " << bus.model << setw(8)
			<< " ��� ������ ������������: " << bus.year << setw(8)
			<< " ������: " << bus.mileage << endl;
	}
	cout << endl;
	fout.close();
	fin.close();
}

void Bus::mileagelist()
{
	ifstream fin("structBin.txt", ios::binary);
	ofstream fout("result.txt", ios::binary);
	try {
		if (!fin) throw 1;
	}
	catch (int mthrow) { cout << "No memory!" << endl; return; }
	Bus bus;
	cout << "\n ������ ���������, ������ � ������� ������ 10000:\n" << endl;
	while (fin) {
		fin.read((char*)&bus, sizeof(Bus));
		if (bus.mileage<=10000) continue;
		if (fin)cout << "�������: " << bus.surname << endl
			<< "��������: " << bus.initials << endl
			<< "����� ��������: " << bus.busnumber << endl
			<< "����� ��������: " << bus.routnumber << endl
			<< "�����: " << bus.model << endl
			<< "��� ������ ������������: " << bus.year << endl
			<< "������: " << bus.mileage << endl;
		cout << endl;
		if (fin)fout << "\r\n" << "�������: " << bus.surname << setw(8)
			<< " ��������: " << bus.initials << setw(8)
			<< " ����� ��������: " << bus.busnumber << setw(8)
			<< " ����� ��������: " << bus.routnumber << setw(8)
			<< " �����: " << bus.model << setw(8)
			<< " ��� ������ ������������: " << bus.year << setw(8)
			<< " ������: " << bus.mileage << endl;
	}
	cout << endl;
	fout.close();
	fin.close();
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Bus bus;
	while (1) {
		cout << "\n�����������������������������������������������������������������������������������������������������������������������" << endl;
		cout << "�������� ����� ����:\n";
		cout<< "1 - ����� �������� ������ �� �����" << endl
			<< "2 - ������ ��������� ��� ��������� ������ ��������" << endl
			<< "3 - ������ ���������, ������� ��������������� ������ 10 ���" << endl
			<< "4 - ������ ���������, ������ � ������� ������ 10 000 ��" << endl
			<< "5 - �����\n";
		cout<< "�����������������������������������������������������������������������������������������������������������������������\n";
		int chosen;
		cin >> chosen;
		cout << "\n";
		switch (chosen) {
		case 1:
			system("cls");
			bus.get_info();
			bus.show();
			break;
		case 2:
			cout << "������� ����� ��������:" << endl;
			int t; cin >> t; cout << endl;
			bus.set_rout(t);
			bus.routlist(); break;
		case 3:
			bus.yearlist();
			break;
		case 4:
			bus.mileagelist();
			break;
		case 5:
			cout << "�� ��������!";
			exit(1);	                  
			break;
		default: cout << endl << "ERROR" << endl; 
		system("pause");
		}
	}
	cout << endl;
	system("pause");
}
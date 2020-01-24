//Customer: �������, ���, ��������, �����, �������, ����� ��������� ��������, ����� ����������� �����.������� ������ ��������.�������:
//	�) ������ ����������� � ���������� �������;
//	�) ������ �����������, ����� ��������� �������� ������� ��������� � �������� ���������.


#include<iostream>
#include <iomanip>
#include<fstream>			
using namespace std;



class Customer {
	char surname[15], name[10], patronymic[15], address[20];
	int phonenumber, cardnumber, accountnumber;
	int card,card1;
public:
	void get_info();
	void show();
	void cardinterval();
	void alphabet_sort();
	void set_interval (int,int);
};




void Customer::set_interval(int t, int k) {
	card = t;
	card1 = k;
}



void Customer::get_info() {
	ifstream fin("struct.txt");
	try {
		if (!fin) throw 1;
	}
	catch (int mthrow) { cout << "No memory!" << endl; return; }
	ofstream fout("structBin.txt", ios::binary);
	Customer customer;
	while (fin) {
		fin >> customer.surname;  if (!fin)break;
		fin >> customer.name;
		fin >> customer.patronymic;
		fin >> customer.address;
		fin >> customer.phonenumber;
		fin >> customer.cardnumber;
		fin >> customer.accountnumber;
		fout.write((char*)&customer, sizeof(Customer));
	}
	fin.close();
	fout.close();
}



void Customer::show() {
	ifstream fin("structBin.txt", ios::binary);
	ofstream fout("result.txt", ios::binary);
	try {
		if (!fin) throw 1;
	}
	catch (int mthrow) { cout << "No memory!" << endl; return; }
	Customer customer;
	while (fin) {
		fin.read((char*)&customer, sizeof(Customer));
		if (fin)cout <<"�������:"<< customer.surname<<endl <<"���:"<< customer.name <<endl<<"��������:" << customer.patronymic << endl<<"�����:"<<customer.address << endl <<"�������:"<< customer.phonenumber << endl <<"����� ��������� �����:"<< customer.cardnumber << endl<<"����� ����������� �����:" << customer.accountnumber << endl;
		cout << endl;
		if (fin)fout << "\r\n" << "�������:" << customer.surname  << setw(8) << "  ���:" << customer.name << setw(8) << "  ��������:" << customer.patronymic << setw(8) << "  �����:" << customer.address << setw(8) << "  �������:" << customer.phonenumber << setw(8) << "  ����� ��������� �����:" << customer.cardnumber << setw(8) << "  ����� ����������� �����:" << customer.accountnumber << endl;
	}
	cout << endl;
	fout.close();
	fin.close();
}




void Customer::alphabet_sort() {
	Customer x, y;
	int flag = 1;
	while (flag) {
		flag = 0;     int k = 0;
		fstream surname("structBin.txt", ios::binary | ios::in | ios::out);
		while (surname) {
			surname.seekg(k, ios::beg);
			surname.read((char*)&x, sizeof(Customer));
			if (!surname)break;
			surname.read((char*)&y, sizeof(Customer));
			if (!surname)break;
			if (x.surname[0]>y.surname[0]) {
				surname.seekp(k, ios::beg);

				surname.write((char*)&y, sizeof(Customer));
				surname.write((char*)&x, sizeof(Customer));
				flag = 1;
			}
			k += sizeof(Customer);
		}
		surname.close();
	}
	cout << endl;
}




void Customer::cardinterval() {
	ifstream fin("structBin.txt", ios::binary);
	ofstream fout("result.txt", ios::binary);
	try {
		if (!fin) throw 1;
	}
	catch (int mthrow) { cout << "No memory!" << endl; return; }
	Customer customer;
	cout << "\n ������ �����������, ����� ��������� �������� ������� ��������� � �������� ���������:\n" << endl;
	while (fin) {
		fin.read((char*)&customer, sizeof(Customer));
		if (customer.cardnumber < card) continue;
		if (customer.cardnumber > card1) continue;
		if (fin)cout << "�������:" << customer.surname << endl << "���:" << customer.name << endl << "��������:" << customer.patronymic << endl << "�����:" << customer.address << endl << "�������:" << customer.phonenumber << endl << "����� ��������� �����:" << customer.cardnumber << endl << "����� ����������� �����:" << customer.accountnumber << endl;
		cout << endl;
		if (fin)fout << "\r\n" << "�������:" << customer.surname << setw(8) << "  ���:" << customer.name << setw(8) << " ��������:" << customer.patronymic << setw(8) << "  �����:" << customer.address << setw(8) << "  �������:" << customer.phonenumber << setw(8) << "  ����� ��������� �����:" << customer.cardnumber << setw(8) << "  ����� ����������� �����:" << customer.accountnumber << endl;
	}
	cout << endl;
	fout.close();
	fin.close();
}




int main() {
	setlocale(LC_ALL, "Russian");
	Customer customer;
	while (1) {
		cout << "1.������� ������ �� �����" << endl
		<< "2.������ �����������, ����� ��������� �������� ������� ��������� � �������� ���������" << endl
		<< "3.������ ����������� � ���������� �������." << endl
	    <<"4.�����" << endl;
		cout << "�������� ����� ����:" << endl;
		int punkt; cin >> punkt;
		switch (punkt) {
		case  1:
			system("cls");
			customer.get_info();
			customer.show();
			break;
		case  2:	
			cout << "������� �������� ������� ��������� ����:" << endl;
			cout << "������� ����������� � ������������ ����� �����" << endl;
			int t,k; cin >> t>>k; cout << endl;
			customer.set_interval(t,k);
			customer.cardinterval(); break;
		case  3:
			customer.alphabet_sort();
			customer.show();
			break;
		case  4:
			cout << "�� ��������!";
			exit(1); break;
		default: cout << endl << "ERROR" << endl; system("pause");
		}
	}
	system("pause");
}



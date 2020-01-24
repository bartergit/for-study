/*��������� ����� ������ ������ � BoolVector �����������  .
����-������ ��������� �������������, � ��� ����� ����������� ��������-���.
����������� ������ ��� ���������� ����������� ����������, ���������� � ��������� ��������, � ����� �������� ����� ������ � ����� � �������.
����������� �� �� �������� ��� ��������� � ������� ������������� ��������.
����������� �������� ��������� � ������-������ ��� ������� ������.
������� ������ ��������. ���������� ���-���� � �������, ������� ����� �� �������� �� �������*/
#include <iostream> 
using namespace std;
class Bool_vector
{
	int n;
	int* array;
public:
	Bool_vector();
	Bool_vector(int n_, int * array_);
	Bool_vector(const Bool_vector & copy);
	~Bool_vector();
	void show();
	int NumberOfUnity();
	int NumberOfZeros();
	Bool_vector operator&(Bool_vector ob);
	Bool_vector operator|(Bool_vector ob);
	Bool_vector operator-();
	Bool_vector & operator=(const Bool_vector ob);
	Bool_vector modify(Bool_vector ob);
};

using namespace std;

//����������� ��� ���������� 
Bool_vector::Bool_vector()
{
	n = 0;
	array = NULL;
}

// ����������� � ����������� 
Bool_vector::Bool_vector(int n_, int* array_)
{
	n = n_;
	array = new int[n];
	for (int i = 0; i < n; i++)
	{
		if (array_[i]) {
			array[i] = 1;
		}
		else array[i] = 0;
	}
}

//����������� ����������� 
Bool_vector::Bool_vector(const Bool_vector & copy)
{
	n = copy.n;
	array = new int[n + 1];
	if (!array) {
		cout << "Error";
	}
	for (int i = 0; i <= n; i++)
		array[i] = copy.array[i];
}

//���������� 
Bool_vector::~Bool_vector()
{
	delete[] array;
}

//����� ������� 
void Bool_vector::show()
{
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << array[i] << "\t";
	}
	cout << endl;
	cout << "------------------------------------------------------" << endl;
	cout << endl;
}

//���������� ���������� ������ 
int Bool_vector::NumberOfUnity()
{
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (array[i]) k++;
	}
	return k;
}

int Bool_vector::NumberOfZeros()
{
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (!(array[i])) k++;
	}
	return k;
}

//���������� ��������� & 
Bool_vector Bool_vector::operator&(Bool_vector ob)
{

	if (this->n != ob.n) {
		cout << "Error of dimension" << endl;
		return Bool_vector();
	}
	int* newarr = new int[n];
	for (int i = 0; i < n; i++) {
		if (this->array[i] && ob.array[i]) newarr[i] = 1;
		else newarr[i] = 0;
	}
	Bool_vector result(n, newarr);
	return result;
}

Bool_vector Bool_vector::operator|(Bool_vector ob)
{
	if (this->n != ob.n) {
		cout << "Error of dimension" << endl;
		return Bool_vector();
	}
	int* newarr = new int[n];
	for (int i = 0; i < n; i++) {
		if (this->array[i] || ob.array[i]) newarr[i] = 1;
		else newarr[i] = 0;
	}
	Bool_vector result(n, newarr);
	return result;
}


Bool_vector Bool_vector::operator-()
{
	int* newarr = new int[n];
	for (int i = 0; i < n; i++) {
		if (this->array[i]) newarr[i] = 0;
		else newarr[i] = 1;
	}
	Bool_vector result(n, newarr);
	return result;
}

//���������� ��������� ������������ 
Bool_vector & Bool_vector::operator=(const Bool_vector ob)
{
	if (this == &ob)
	{
		return *this;
	}
	for (int i = 0; i < n; i++) {
		this->array[i] = ob.array[i];
	}
	return *this;
}

Bool_vector Bool_vector::modify(Bool_vector ob)
{
	return (*this)&(-ob);
}

void main()
{
	setlocale(0, "rus");
	const int n = 5;
	int array1[n] = { 1 ,2,0,-1,54 };
	int array2[n] = { 0,4,0,0,2 };
	Bool_vector obj1(n, array1);
	Bool_vector obj2(n, array2);
	obj1.show();
	obj2.show();
	cout  << "���������� ������ � 1 ������� : " << obj1.NumberOfUnity() << endl;
	cout << "���������� ����� � 1 �������: " << obj1.NumberOfZeros() << endl;
	cout << "������������ � "; (obj1&obj2).show();
	cout << "������������ ��� "; (obj1 | obj2).show();
	cout << "������������ ��������� "; (-obj2).show();
	cout << "������� ������������ �� �������: " << endl;
	(obj1.modify(obj2)).show();
	system("pause");
};
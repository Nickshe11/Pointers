#include <iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);
int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value);
int* insert(int* arr, int& n, int value, int index);
int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* erase(int* arr, int& n, int index);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value, choice, index;
	//cout << "������� ����������� ��������: "; cin >> value;
	cout << "�������� �������� � ��������:" << endl;
	cout << "1 - ���������� �������� � ����� �������" << endl << "2 - ���������� �������� � ������ �������" << endl << "3 - ���������� �������� � ������ �� �������" << endl;
	cout << "4 - �������� �������� �� ����� �������" << endl << "5 - �������� �������� �� ������ �������" << endl << "6 - �������� �������� �� ������� �� ���������� �������" << endl;
	cin >> choice;
	switch (choice)
	{
	case(1):
		cout << "������� ����������� ��������: "; cin >> value;
		arr = push_back(arr, n, value); break;

	case(2):
		cout << "������� ����������� ��������: "; cin >> value;
		arr = push_front(arr, n, value); break;

	case(3):
		cout << "������� ����������� ��������: "; cin >> value;
		cout << "������� ������ ������������ ��������: "; cin >> index;
		arr = insert(arr, n, value, index); break;
	case(4):
		arr = pop_back(arr, n); break;
	case(5):
		arr= pop_front(arr, n); break;
	case(6):
		cout << "������� ������ ���������� ��������: "; cin >> index;
		arr = erase(arr, n, index); break;
	default: cout << "Input error" << endl; break;
	}
	Print(arr, n);
	delete[] arr;

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//���������� � �������
		//����� ���������� ���������� � �������� �������������
		*(arr + i) = rand() % 100;
	}
}
void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		//���������� � �������
		//����� �������� ��������������
		cout << arr[i] << "\t";
	}
	cout << endl;
}
int* push_back(int* arr, int& n, int value)
{
	//1) ������� �������� ������ ������� �������:
	int* buffer = new int[n + 1];

	//2) �������� ���������� ��������� ������� � ��������
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3) ����� ����, ��� ��� ������ ����������� � ��������� ������� � ��������
	// �������� ������ ������ �� ����� � ��� ����� �������.
	delete[] arr;

	//4) ��������� ����� ��������� ������� � ��������� 'arr' ������� ������ �������
	arr = buffer;

	//5) � ������ ����� ����� ����� �������� ��� ���:
	arr[n] = value;
	//��������� ������ ������ � ������� 'arr' �������� ��� ���� �������, 
	//� ������� ����� ��������� ��������

	//6) ����� ����, ��� �� �������� � ������ �������, 
	//���������� ��������� ������� ������������� �� 1
	n++;
	//7) Mission completed, element added
	return arr;
}
int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		(i == 0 ? buffer[i] = value : buffer[i] = arr[i - 1]);
	}
	delete[]arr;
	arr = buffer;
	n++;
	return arr;
}
int* insert(int* arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		(i <= (index - 1) ? (i == (index - 1) ? buffer[i] = value : buffer[i] = arr[i]) : buffer[i] = arr[i - 1]);
	}
	delete[]arr;
	arr = buffer;
	n++;
	return arr;
}
int* pop_back(int* arr, int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n-1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
int* pop_front(int* arr, int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
int* erase(int* arr, int& n, int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		(i <= (index - 1) ? (i == (index - 1) ? (buffer[i] = arr[i + 1]):(buffer[i] = arr[i])) : buffer[i] = arr[i + 1]);
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
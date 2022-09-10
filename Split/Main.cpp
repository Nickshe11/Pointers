#include<iostream>
using namespace std;
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n = 10;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int m = n / 2;
	int* earr = new int[m];
	int* oarr = new int[m];
	//�� �� �������, ���������� ������� �� ������ � ��������
	for (int i = 0; i < n; i++)
	{
		(i % 2 == 0 ? earr[i / 2] = arr[i] : oarr[i / 2] = arr[i]);
	}
	cout << "����� ���� ����������� ��������, ����������� �� ������ � �������� ��������" << endl;
	Print(earr, m);
	Print(oarr, m);
	cout << "_____________________________________________" << endl<<endl;
	int odd=0, even=0;
	for (int i = 0; i < n; i++)
	{
		(arr[i] % 2 == 0 ? even ++ : odd++);
	}
	cout << "����� ���� ����������� ��������, ����������� �� ��������� ��������-���������� ��������" << endl;
	cout << "even = " << even << "\t" << "odd = " << odd<< endl;
	int* earr1 = new int[even];
	int* oarr1 = new int[odd];
	int ecounter = 0, ocounter = 0;
	for (int i = 0; i < n; i++)
	{
		(arr[i] % 2 == 0 ? (earr1[ecounter] = arr[i], ecounter++) : (oarr1[ocounter] = arr[i], ocounter++));
	}
	Print(earr1, even);
	Print(oarr1, odd);
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr [i] << "\t";
	}
	cout << endl;
}
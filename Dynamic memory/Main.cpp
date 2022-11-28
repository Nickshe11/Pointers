#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int* arr, const int n);
void Print(int** arr, const int rows, const int cols);
int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value);
int* insert(int* arr, int& n, int value, int index);
int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* erase(int* arr, int& n, int index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value, choice, index;
	//cout << "������� ����������� ��������: "; cin >> value;
	cout << "�������� �������� � ��������:" << endl;
	cout << "1 - ���������� �������� � ����� �������" << endl << "2 - ���������� �������� � ������ �������" << endl << "3 - ���������� �������� � ������ �� ������" << endl;
	cout << "4 - �������� �������� �� ����� �������" << endl << "5 - �������� �������� �� ������ �������" << endl << "6 - �������� �������� �� ������� �� ���������� ������" << endl;
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
		cout << "������� ����� ������������ ��������: "; cin >> index;
		arr = insert(arr, n, value, index); break;
	case(4):
		arr = pop_back(arr, n); break;
	case(5):
		arr = pop_front(arr, n); break;
	case(6):
		cout << "������� ����� ���������� ��������: "; cin >> index;
		arr = erase(arr, n, index); break;
	default: cout << "Input error" << endl; break;
	}
	Print(arr, n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1

	int rows, cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;

	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
		
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
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
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
	for (int i = 0; i < n - 1; i++)
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
		(i <= (index - 1) ? (i == (index - 1) ? (buffer[i] = arr[i + 1]) : (buffer[i] = arr[i])) : buffer[i] = arr[i + 1]);
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
} 
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

template<typename T> void Print(T* arr, const int n);
template<typename T> void Print(T** arr, const int rows, const int cols);

template <typename T>T* push_back(T* arr, int& n, T value);
template <typename T>T* push_front(T* arr, int& n, T value);

template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols);

template<typename T> void push_col_back(T** arr, const int rows, int& cols);
template<typename T> void pop_col_back(T** arr, const int rows, int& cols);


template <typename T>T* insert(T* arr, int& n, T value, int index);
template <typename T>T* pop_back(T* arr, int& n);
template <typename T>T* pop_front(T* arr, int& n);
template <typename T>T* erase(T* arr, int& n, int index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
#define delimiter "___________________________________"
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
	cout << delimiter << endl;
	/*arr=pop_row_back(arr,  rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;*/
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;

	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
	
	int first = 0;
	int second = 1;
	int limit,box;
	cout << "������� ���������� �������� ��� ������ ���� ���������:\t" << endl; cin >> limit;
	for (; first <= limit; first=second, second += box)
	{
		cout << first << "\t";
		box = first;
	}
	cout << endl;
	first = 0;
	second = 1;
	cout << "������� ���������� ��������� ��������:\t" << endl; cin >> limit;
	for (int i = 0; i < limit; i++)
	{
		cout << first << "\t";
		box = first;
		first = second;
		second += box;
	}
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
template<typename T> void Print(T* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		//���������� � �������
		//����� �������� ��������������
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T> void Print(T** arr, const int rows, const int cols)
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
template <typename T>T* push_back(T* arr, int& n, T value)
{
	//1) ������� �������� ������ ������� �������:
	T* buffer = new T[n + 1];

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
template <typename T>T* push_front(T* arr, int& n, T value)
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
template <typename T>T* insert(T* arr, int& n, T value, int index)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i <= n; i++)
	{
		(i <= (index - 1) ? (i == (index - 1) ? buffer[i] = value : buffer[i] = arr[i]) : buffer[i] = arr[i - 1]);
	}
	delete[]arr;
	arr = buffer;
	n++;
	return arr;
}
template <typename T>T* pop_back(T* arr, int& n)
{
	T* buffer = new T[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
template <typename T>T* pop_front(T* arr, int& n)
{
	T* buffer = new T[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
template <typename T>T* erase(T* arr, int& n, int index)
{
	T* buffer = new T[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		(i <= (index - 1) ? (i == (index - 1) ? (buffer[i] = arr[i + 1]) : (buffer[i] = arr[i])) : buffer[i] = arr[i + 1]);
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}

template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	return push_back(arr, rows, new T[cols]{});
}
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];
	return pop_back(arr, rows);
}

template<typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = push_back(arr[i], cols, T());
		cols--;
	}
	cols++;
}
template<typename T>void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = pop_back(arr[i], cols);
		cols++;
	}
	cols--;
}

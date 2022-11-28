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
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value, choice, index;
	//cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Выберите операцию с массивом:" << endl;
	cout << "1 - Добавление элемента в конец массива" << endl << "2 - Добавление элемента в начало массива" << endl << "3 - Добавление элемента в массив по номеру" << endl;
	cout << "4 - Удаление элемента из конца массива" << endl << "5 - Удаление элемента из начала массива" << endl << "6 - Удаление значения из массива по указанному номеру" << endl;
	cin >> choice;
	switch (choice)
	{
	case(1):
		cout << "Введите добавляемое значение: "; cin >> value;
		arr = push_back(arr, n, value); break;

	case(2):
		cout << "Введите добавляемое значение: "; cin >> value;
		arr = push_front(arr, n, value); break;

	case(3):
		cout << "Введите добавляемое значение: "; cin >> value;
		cout << "Введите номер добавляемого значения: "; cin >> index;
		arr = insert(arr, n, value, index); break;
	case(4):
		arr = pop_back(arr, n); break;
	case(5):
		arr = pop_front(arr, n); break;
	case(6):
		cout << "Введите номер удаляемого значения: "; cin >> index;
		arr = erase(arr, n, index); break;
	default: cout << "Input error" << endl; break;
	}
	Print(arr, n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1

	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

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
		//Обращаемся к массиву
		//Через арифметику указателей и оператор разыменования
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
		//Обращаемся к массиву
		//Через оператор индексирования
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
	//1) Создаем буферный массив нужного размера:
	int* buffer = new int[n + 1];

	//2) Копируем содержимое исходного массива в буферный
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3) После того, как все данные скопированы с исходного массива в буферный
	// исходный массив больше не нужен и его можно удалить.
	delete[] arr;

	//4) подменяем адрес исходного массива в указателе 'arr' адресом нового массива
	arr = buffer;

	//5) И только после этого можно написать вот так:
	arr[n] = value;
	//поскольку только сейчас в массиве 'arr' появился еще один элемент, 
	//в который можно сохранить значение

	//6) После того, как мы добавили в массив элемент, 
	//количество элементов массива увеличивается на 1
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
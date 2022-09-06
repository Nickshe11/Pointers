#include <iostream>
using namespace std;

//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	int a = 2;		//Объявление переменной 'a' и инициализация ее значением 2
	int* pa = &a;	//Объявление указателя 'pa' и инициализация его адресом переменной а
	//ра - pointer_to_a
	cout << a << endl; //Вывод значения переменной
	cout << &a << endl; //Взятие адреса переменной прямо при выводе
	cout << pa << endl; //Вывод адреса переменной "а", хранящегося в указателе "ра"
	cout << *pa << endl; //Разыменование указателя "ра" и вывод на экран значения по адресу

	int* pb;
	int b = 3;
	pb = &b;
	//int - int
	//int* - указатель на int
	//double - double
	//double* - указатель на double
#endif // POINTERS_BASICS

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl; //В результате видим адрес массива
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
}
#pragma once

#include "List.h"

#include<iostream>
using std::cout;
using std::endl;

class Gun
{
public:
	Gun()
	{
		static int num = 0;
		number = num++;
	};
	int number;
	void Shot() { cout << this << " Bang  ¹"<<number << endl; }
};

int main()
{
	setlocale(0, "");
	{
		{
			List<int> a;
			List<int> b;

			a.Add();
			*a.curObject = 1;

			a.Add();
			int* x = a.GetObj();
			*x = 2;

			b.Add();
			*b.curObject = 3;

			a.Add();

			a.Print();

			a = b;
		}
	
	system("pause");
	system("cls");
	}
	List<int> a;
	for (int i = 0; i < 11; i++)
	{
		a.Add();
		*a.curObject = i;
	}
	a.Print();

	a.PrintCur();
	a.JumpBuck();
	a.PrintCur();
	a.JumpForvard();
	a.PrintCur();

	system("pause");
	system("cls");

	List<Gun> b;

		b.Add();
		b.GetObj()->Shot();

	system("pause");
}
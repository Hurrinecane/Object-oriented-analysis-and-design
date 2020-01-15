#pragma once

#include "List.h"

#include<iostream>
using std::cout;
using std::endl;

class Gun
{
public:
	void Shot() { cout << this << " Bang" << endl; }
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
		List<Gun> b;
		b.Add();
		b.GetObj()->Shot();

		b.Add();
		b.curObject->Shot();

		List<Gun> c;
		c = b;
		c.Print();
	system("pause");
	}
	List<int> a;
	for (int i = 0; i < 11; i++)
	{
		a.Add();
		*a.curObject = i;
	}
	system("cls");
	a.Print();
	system("pause");
}
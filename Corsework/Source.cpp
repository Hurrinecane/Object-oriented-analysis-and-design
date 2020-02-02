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
	void Shot() { cout << this << " Bang  �" << number << endl; }
};

int main()
{
	setlocale(0, "");
	{
		List<int> a;
		for (int i = 0; i < 11; i++)
		{
			a.Add();
			*a.curObject = i;
		}
		a.Print();

		a.Prev();
		a.PrintCur();

		a.Next();
		a.PrintCur();

		a.JumpBack();
		a.PrintCur();
		a.JumpForvard();
		a.PrintCur();

		system("pause");
		system("cls");
	}

	{
		List<int> a;
		List<int> b;

		a.Add();
		*a.curObject = 1;

		cout <<"�� ������ " <<a.curObject <<" ����� " << *a.curObject << endl;

		a.Add();
		int* x = a.GetObj();
		*x = 2;
		cout <<"� �� ������ " << a.GetObj() <<" ����� " <<*a.GetObj() << endl;
		
		a.Print();

		b.Add();
		*b.curObject = 3;

		b.Print();

		cout << "�� ������ " << b.curObject << " ����� " << *b.curObject << endl;

		a = b;

		a.Print();

		cout << "� �� ������ " << a.GetObj() << " ����� " << *a.GetObj() << endl;

		system("pause");
		system("cls");
	}

	List<Gun> a;
	List<Gun> b;

	b.Add();
	b.Add();
	b.Print();
	b.GetObj()->Shot();

	a = b;

	a.Print();
	a.PrintCur();
	a.Prev();
	a.PrintCur();
	a.curObject->Shot();
	system("pause");
}
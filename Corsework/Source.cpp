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
	{
		List<int> a;

		a.Add();
		*a.curObject = 1;

		a.Add();
		*a.curObject = 2;

		a.Add();
		int* x = a.GetObj();
		*x = 3;
	}

	List<Gun> b;
	b.Add();
	b.GetObj()->Shot();

	b.Add();
	b.curObject->Shot();
}
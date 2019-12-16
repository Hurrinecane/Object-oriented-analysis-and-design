#pragma once
using namespace std;

#include <iostream>
#include "Polar.h"

int main()
{
	setlocale(LC_ALL, "");

	Polar a(5, 56.5);
	a.Print();
	Decart d(a);
	d.Print();

	a.DecartToPolar(d);

	cout << a << endl;
	a.Print();

	Polar c(3, 0.5);

	cout << c << endl;

	c -= a;

	cout << c << endl;

	cout << a[0] << " " << a[1]<<endl;
	cin >> a;
	a.Print();
}
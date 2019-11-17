#pragma once
using namespace std;

#include <iostream>

#include "Polar_vector.h"
#include "Decart_vector.h"

int main()
{
	setlocale(LC_ALL, "");

	Polar v1(1, 0.5);
	v1.Print();
	{
		Decart a(v1);
		Polar v2(a);
		v2.Print();
	}

	Decart d(10, 10);
	d.Print();

	Polar v3(d);

	v3.Print();
	d.PolarToDecart(v3);
	d.Print();

	v3.Print();
	v3 = v3 - v1;
	v3.Print();
	v3 += v1;
	v3.Print();

	if (v3 >= v1) cout << "v3 >= v1" << endl;
}
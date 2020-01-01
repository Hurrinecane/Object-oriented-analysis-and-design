#pragma once
using namespace std;

#include <iostream>
#include "Polar.h"

int main()
{
	setlocale(LC_ALL, "");

	Polar a(5, 56.5);

	Decart b(1, 1);

	Object* d = &a;

	d->Print();

	d = &b;

	d->Print();
}
#pragma once
using namespace std;

#include <iostream>
#include "Polar_vector.h"

class Polar;

class Decart
{
	friend class Polar;

public:
	Decart(double, double);
	Decart(const Polar&);

	void Print() const;

	void PolarToDecart(const Polar&);

private:
	double x;
	double y;
};


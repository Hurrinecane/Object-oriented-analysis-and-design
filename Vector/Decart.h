#pragma once

#include "Virtual.h"

class Polar;

#include "Polar.h"

class Decart:public Object
{
	friend class Polar;

public:
	Decart(double, double);
	Decart(const Polar&);

	void Print() const override;

	void PolarToDecart(const Polar&);

	friend Polar operator+(Polar, const Decart&);
	friend Polar operator-(Polar, const Decart&);

private:
	double x;
	double y;
};
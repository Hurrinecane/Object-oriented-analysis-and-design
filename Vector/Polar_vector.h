#pragma once
using namespace std;

#include <iostream>
#include "Decart_vector.h"

class Decart;

class Polar
{
	friend class Decart;

public:
	Polar(double, double);
	Polar(const Decart&);

	~Polar();

	Polar(const Polar& other);

	void Print() const;

	void DecartToPolar(const Decart&);

	Polar operator = (const Polar&);
	Polar operator + (const Polar&);
	Polar operator - (Polar);
	void operator += (const Polar&);
	void operator -= (const Polar&);

	bool operator == (const Polar&);
	bool operator != (const Polar&);
	bool operator < (const Polar&);
	bool operator > (const Polar&);
	bool operator <= (const Polar&);
	bool operator >= (const Polar&);


	ostream& operator << (const Polar&);

private:
	double r;
	double ang;
};
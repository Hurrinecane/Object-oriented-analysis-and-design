#pragma once
#include <iostream>
using namespace std;

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
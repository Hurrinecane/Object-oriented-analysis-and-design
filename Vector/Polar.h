#pragma once

#include <iostream>
#include "Virtual.h"

class Decart;

#include "Decart.h"

class Polar :public Object
{
	friend class Decart;

public:
	Polar();
	Polar(const Decart&);
	Polar(double, double);

	~Polar();
	Polar(const Polar&);



	double operator[] (int);

	Polar operator = (const Polar&);

	Polar operator + (Polar);
	friend Polar operator + (Polar, const Decart&);
	void operator += (const Polar&);

	Polar operator - (Polar);
	friend Polar operator - (Polar, const Decart&);
	void operator -= (const Polar&);

	bool operator == (const Polar&);
	bool operator != (const Polar&);

	bool operator < (const Polar&);
	bool operator > (const Polar&);

	bool operator <= (const Polar&);
	bool operator >= (const Polar&);

	void Print() const override;
	   
	void DecartToPolar(const Decart&);

	void Add(const Polar&);

	friend std::ostream& operator << (std::ostream&, const Polar&); 
	friend Polar& operator>>(std::istream& in, Polar&);

private:
	double* pPolarCoord;

	void ChangeCoords(double, double);
};
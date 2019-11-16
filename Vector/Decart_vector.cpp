#include "Vector.h"

Decart::Decart(double x_, double y_)
{
	x = x_;
	y = y_;
}
Decart::Decart(const Polar& p_)
{
	x = p_.r * cos(p_.ang);
	y = p_.r * sin(p_.ang);
}

void Decart::PolarToDecart(const Polar& p_)
{
	x = p_.r * cos(p_.ang);
	y = p_.r * sin(p_.ang);
}


void Decart::Print() const
{
	cout << endl << "X = " << x << "\tY = " << y << endl;
}

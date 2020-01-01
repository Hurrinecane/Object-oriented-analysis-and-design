#include "Decart.h"

Decart::Decart(double x_, double y_)
{
	x = x_;
	y = y_;
}
Decart::Decart(const Polar& p_)
{
	this->PolarToDecart(p_);
}

void Decart::PolarToDecart(const Polar& p_)
{
	x = p_.pPolarCoord[0] * cos(p_.pPolarCoord[1]);
	y = p_.pPolarCoord[0] * sin(p_.pPolarCoord[1]);
}

void Decart::Print() const
{
	std::cout << std::endl << "X = " << x << "\tY = " << y << std::endl;
}
#include "Polar_vector.h"


Polar::Polar(double r_, double ang_)
{
	cout << "Вызвался конструктор для: " << this << endl;
	r = r_;
	ang = ang_;
}

Polar::Polar(const Decart& d_)
{
	cout << "Вызвался конструктор для: " << this << endl;
	r = sqrt(d_.x * d_.x + d_.y * d_.y);
	if (r != 0)
		ang = asin(d_.y / r);
	else
		ang = 0;
}

Polar::~Polar()
{
	cout << "Вызвался деструктор для: " << this << endl;
}

Polar::Polar(const Polar& other)
{
	cout << "Вызвался Конструктор копирования для: " << this << endl;
	this->ang = other.ang;
	this->r = other.r;
}


void Polar::DecartToPolar(const Decart& d_)
{
	r = sqrt(d_.x * d_.x + d_.y * d_.y);
	if (r != 0)
		ang = asin(d_.y / r);
	else
		ang = 0;
}

Polar Polar::operator = (const Polar& n_)
{
	ang = n_.ang;
	r = n_.r;
	return *this;
}

Polar Polar::operator + (const Polar& p_) 
{
	Decart a(*this);
	Decart b(p_);
	a.x += b.x;
	a.y += b.y;	
	Polar tmp(a);
	return tmp;
}
void Polar::operator += (const Polar& p_)
{
	Decart a(*this);
	Decart b(p_);
	a.x += b.x;
	a.y += b.y;
	this->DecartToPolar(a);
}

Polar Polar::operator - ( Polar p_)
{
	Decart a(*this);
	Decart b(p_);
	a.x -= b.x;
	a.y -= b.y;
	p_.DecartToPolar(a);
	return p_;
}

void Polar::operator -= (const Polar& p_)
{
	Decart a(*this);
	Decart b(p_);
	a.x -= b.x;
	a.y -= b.y;
	this->DecartToPolar(a);
}

bool Polar::operator == (const Polar& p_)
{
	if (this->r == p_.r) return 1;
	else return 0;
}
bool Polar::operator != (const Polar& p_)
{
	if (this->r != p_.r) return 1;
	else return 0;
}
bool Polar::operator < (const Polar& p_)
{
	if (this->r < p_.r) return 1;
	else return 0;
}
bool Polar::operator > (const Polar& p_)
{
	if (this->r > p_.r) return 1;
	else return 0;
}
bool Polar::operator <= (const Polar& p_)
{
	if (this->r <= p_.r) return 1;
	else return 0;
}
bool Polar::operator >= (const Polar& p_)
{
	if (this->r >= p_.r) return 1;
	else return 0;
}

ostream& Polar::operator << (const Polar& p_)
{
	return cout << endl << r << endl << ang << endl;
}


void Polar::Print() const
{
	double grad = ang / 3.1416 * 180;
	cout << endl << "Радиус = "<<r <<"\tУгол = "<<ang <<"\tУгол в градусах = " << grad << endl;
}

#include "Polar.h"

#pragma region Const and dest
Polar::Polar()
{
	std::cout << "Вызвался конструктор для: " << this << std::endl;
	this->pPolarCoord = new double[2];
	pPolarCoord[0] = 0;
	pPolarCoord[1] = 0;
}

Polar::Polar(double r, double ang)
{
	std::cout << "Вызвался конструктор для: " << this << std::endl;
	this->pPolarCoord = new double[2];
	pPolarCoord[0] = r;
	pPolarCoord[1] = ang;
}
Polar::Polar(const Decart& coordD)
{
	std::cout << "Вызвался конструктор для: " << this << std::endl;
	this->pPolarCoord = new double[2];
	this->DecartToPolar(coordD);
}

Polar::~Polar()
{
	std::cout << "Вызвался деструктор для: " << this << std::endl;
	delete[] pPolarCoord;
}

Polar::Polar(const Polar& other)
{
	if (this->pPolarCoord == nullptr) this->pPolarCoord = new double[2];
	std::cout << "Вызвался Конструктор копирования для: " << this << std::endl;
	pPolarCoord[0] = other.pPolarCoord[0];
	pPolarCoord[1] = other.pPolarCoord[1];
}

double Polar::operator[](int index)
{
	return this->pPolarCoord[index];
}

#pragma endregion

#pragma region operators
Polar Polar::operator = (const Polar& n_)
{
	if (this == &n_)
		return *this;
	if (this == nullptr)
		pPolarCoord[1] = n_.pPolarCoord[1];
	pPolarCoord[0] = n_.pPolarCoord[0];
	return *this;
}

Polar Polar::operator + (Polar p_)
{
	Decart a(*this);
	Decart b(p_);
	a.x += b.x;
	a.y += b.y;
	p_.DecartToPolar(a);
	return p_;
}
Polar operator+(Polar p_, const Decart& d)
{
	Decart a(p_);
	a.x += d.x;
	a.y += d.y;
	p_.DecartToPolar(a);
	return p_;
}
void Polar::operator += (const Polar& p_)
{
	Decart a(*this);
	Decart b(p_);
	a.x += b.x;
	a.y += b.y;
	this->DecartToPolar(a);
}

Polar Polar::operator - (Polar p_)
{
	Decart a(*this);
	Decart b(p_);
	a.x -= b.x;
	a.y -= b.y;
	p_.DecartToPolar(a);
	return p_;
}

Polar operator-(Polar p_, const Decart& d_)
{
	Decart a(p_);
	a.x -= d_.x;
	a.y -= d_.y;
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
	if (this->pPolarCoord[0] == p_.pPolarCoord[0]) return 1;
	else return 0;
}
bool Polar::operator != (const Polar& p_)
{
	if (this->pPolarCoord[0] != p_.pPolarCoord[0]) return 1;
	else return 0;
}
bool Polar::operator < (const Polar& p_)
{
	if (this->pPolarCoord[0] < p_.pPolarCoord[0]) return 1;
	else return 0;
}
bool Polar::operator > (const Polar& p_)
{
	if (this->pPolarCoord[0] > p_.pPolarCoord[0]) return 1;
	else return 0;
}
bool Polar::operator <= (const Polar& p_)
{
	if (this->pPolarCoord[0] <= p_.pPolarCoord[0]) return 1;
	else return 0;
}
bool Polar::operator >= (const Polar& p_)
{
	if (this->pPolarCoord[0] >= p_.pPolarCoord[0]) return 1;
	else return 0;
}


std::ostream& operator<<(std::ostream& out, const Polar& p_)
{
	return out << p_.pPolarCoord[0] << "\n" << p_.pPolarCoord[1];
}
Polar& operator>>(std::istream& in, Polar& p_)
{
	in >> p_.pPolarCoord[0];
	in >> p_.pPolarCoord[1];
	return p_;
}

#pragma endregion

void Polar::Print() const
{
	double ang = pPolarCoord[1] / 3.1416 * 180;
	if (ang < 0) ang += 360;
	std::cout << std::endl << "Радиус = " << pPolarCoord[0] << "\tУгол = " << pPolarCoord[1] << "\tУгол в градусах = " << ang << std::endl;
}

void Polar::DecartToPolar(const Decart& d_)
{
	pPolarCoord[0] = sqrt(d_.x * d_.x + d_.y * d_.y);
	if (pPolarCoord[0] != 0)
		pPolarCoord[1] = asin(d_.y / pPolarCoord[0]);
	else
		pPolarCoord[1] = 0;
}

void Polar::Add(const Polar& p_)
{
	Decart a(*this);
	Decart b(p_);
	a.x += b.x;
	a.y += b.y;
	this->DecartToPolar(a);
}


void Polar::ChangeCoords(double r, double ang)
{
	pPolarCoord[0] = r;
	pPolarCoord[1] = ang;
}
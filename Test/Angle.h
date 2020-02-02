#pragma once
#include<iostream>

class Angle
{
public:
	Angle(double);
	
	void Print();

	double GetSin();

	double GetRad() { return grad * 3.14 / 180; };

	void SetGrad(double);

	friend std::ostream& operator << (std::ostream&, const Angle&);
	friend Angle& operator>>(std::istream & in, Angle&);
private:
	double grad;
};

Angle::Angle(double grad_)
{
	grad = grad_;
}

inline void Angle::Print()
{
	std::cout << "”гол в градусах: "<<grad<<std::endl;
}

inline double Angle::GetSin()
{
	return std::sin(grad * 3.14 / 180);
}

inline void Angle::SetGrad(double grad_)
{
	grad = grad_;
}

Angle& operator>>(std::istream& in, Angle& ang)
{
	in >> ang.grad;
	return ang;
}
inline std::ostream& operator<<(std::ostream& out, const Angle& ang)
{
	return out << ang.grad;
}
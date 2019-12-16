//#pragma once
//using namespace std;
//
//#include <iostream>
//
//class Decart;
///*
//конструктор по умолчанию 
//конструктор копирования
//деструктор
//операция =
//перемещающее присваивание
//перемещающее копирование*/
//
//class Polar
//{
//	friend class Decart;
//
//public:
//
//	Polar(Polar&&);
//	
//	void Print() const;
//
//	void DecartToPolar(const Decart&);
//
//	Polar operator = (const Polar&);
//	Polar operator + (const Polar&);
//	Polar operator - (Polar);
//	void operator += (const Polar&);
//	void operator -= (const Polar&);
//
//	bool operator == (const Polar&);
//	bool operator != (const Polar&);
//	bool operator < (const Polar&);
//	bool operator > (const Polar&);
//	bool operator <= (const Polar&);
//	bool operator >= (const Polar&);
//	//add
//
//	ostream& operator<< ( const Polar&);
//
//private:
//	double r;
//	double ang; // double *pd;  
//};
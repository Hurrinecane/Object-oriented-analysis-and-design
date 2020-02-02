#include "Angle.h"

int main()
{
	setlocale(0, "");
	Angle a(10);


	a.Print();
	double b = a.GetRad();
	b = a.GetSin();

}
////class A
////{
////public: virtual void f();
////};
////
////class B : public A
////{
////public: void  f();
////};
////
////class C : public A
////{
////public: void f();
////};
////
////int main()
////{
////	A a1;
////	B b1;
////	C c1;
////	A* p[3] = { &b1,&c1,&a1 };
////	p[0]->f(); //вызов A::f() если не указано virtual
////	p[1]->f(); //вызов A::f()
////	p[2]->f(); //вызов A::f()
////	
////	for (int i = 0; i < 3; i++)
////	{
////		p[i]->f();
////	}
////	
////}
//
//class A
//{
//	void (**ftable)();//***делает система
//public:
//	virtual void x();
//	virtual void y();
//	virtual void z();
//	A();
//	~A();
//
//};
//#define vx 0//***делает система
//#define vy 1//***делает система
//#define vz 2//***делает система
//
////массив адресов функций класса А
//void (A::* TableA[])() = { A::x,A::y,A::z };//***делает система
//A::A()
//{
//	ftable = TableA;//***
//}
//class B :public A
//{
//public:
//	void x();
//	void z();
//
//};
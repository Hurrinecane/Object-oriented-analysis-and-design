#include"Tree.h"

int main()
{
	Tree<int> a;

	a.insert(5);
	a.insert(6);
	a.insert(7);
	a.insert(4);
	a.insert(3);
	a.insert(5);
	a.print();
}
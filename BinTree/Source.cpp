#include "Tree.h"

int main()
{
	setlocale(LC_ALL, "");
	{
		Tree<int> tree;

		tree.Push(5);
		tree.Push(6);
		tree.Push(7);
		tree.Push(4);
		tree.Push(3);
		tree.Push(1);
		tree.Push(2);
		tree.Push(5);


		tree.PrintInLine();
		tree.Print();
	}
}
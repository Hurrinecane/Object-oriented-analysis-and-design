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
		cout << tree.getMax() << endl;
		cout << tree.getMin() << endl;

		tree.Print();
	}
	Tree<char> t;
	t.Push('f');
	t.Push('g');
	t.Push('h');
	t.Push('i');
	t.Push('j');
	t.Push('a');
	t.Push('b');
	t.Push('c');
	t.Push('d');
	t.Push('e');

	t.Print();
}
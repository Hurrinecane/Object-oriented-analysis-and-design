#pragma once

#include "Node.h"
#include<iostream>

using std::cout;
using std::endl;

template <typename Type> class Tree
{
public:
	Tree();
	Tree(Type& new_data);
	
	~Tree();
	void DeleteTree(Node<Type>*&);

	void Push(const Type&);

	void Print() const;
	void Print(Node<Type>*&, int, bool) const;
	
	void PrintInLine(Node<Type>*&) const;
	void PrintInLine() const;
	
	Type getMax();
	Type getMin();

private:
	Node<Type>* root_;
};

#pragma region Const&Dest


template <typename Type>
inline Tree<Type>::Tree()
{
	root_ = nullptr;
}

template<typename Type>
inline Tree<Type>::Tree(Type& new_data)
{
	root_ = new  Node<Type>(new_data);
}

template<typename Type>
inline Tree<Type>::~Tree()
{
	DeleteTree(this->root_);
	delete this->root_;
	system("cls");
	cout << "Дерево " << this << " было удалено" << endl;
}

template<typename Type>
void Tree<Type>::DeleteTree(Node<Type>*& node)
{
	if (node != nullptr)
		if (node->left_ == nullptr && node->right_ == nullptr)
			return;
		else
		{
			if (node->left_ != 0)
			{
				DeleteTree(node->left_);
				delete node->left_;
				node->left_ = nullptr;
				system("cls");
				this->Print();
			}
			if (node->right_ != 0)
			{
				DeleteTree(node->right_);
				delete node->right_;
				node->right_ = nullptr;
				system("cls");
				this->Print();
			}
		}
	//system("pause");
}
#pragma endregion

template<typename Type>
void Tree<Type>::Push(const Type& new_data)
{
	if (root_ == nullptr)
		root_ = new Node<Type>(new_data);
	else
	{
		Node<Type>* pNode = root_;
		do
		{
			if (new_data > pNode->data_)
			{
				if (pNode->right_ == nullptr)
				{
					pNode->right_ = new  Node<Type>(new_data);
					return;
				}
				pNode = pNode->right_;
			}
			else
			{
				if (pNode->left_ == nullptr)
				{
					pNode->left_ = new  Node<Type>(new_data);
					return;
				}
				pNode = pNode->left_;
			}
		} while (true);
	}
}

#pragma region Print
template<typename Type>
void Tree<Type>::Print() const
{
	int u = 0;
	bool border = true;
	if (root_ == nullptr) return;
	else
	{
		Print(root_->left_, ++u, border);
		border = false;
		for (int i = 0; i < u; ++i) cout << "|";
		cout << root_->data_ << endl;
		u--;
	}
	Print(root_->right_, ++u, border);
	//cout << "===================================================================" << endl;
}

template<typename Type>
void Tree<Type>::Print(Node<Type>*& node, int u, bool border) const
{
	if (!node) return;
	else
	{
		Print(node->left_, ++u, border);
		for (int i = 0; i < u; ++i) cout << "|";
		cout << node->data_ << endl;

		u--;
	}
	Print(node->right_, ++u, border);
}

template<typename Type>
void Tree<Type>::PrintInLine(Node<Type> * &node) const
{
	if (node)
	{
		PrintInLine(node->left_);
		cout << node->data_ << " ";
		PrintInLine(node->right_);
	}
}

template<typename Type>
void Tree<Type>::PrintInLine() const
{
	Node<Type>* node = root_;
	if (node)
	{
		PrintInLine(node->left_);
		cout << node->data_ << " ";
		PrintInLine(node->right_);
	}
	cout << endl;
}

#pragma endregion

template<typename Type>
Type Tree<Type>::getMax()
{
	Node<Type>* node = root_;
	while (node->right_ != nullptr)
	{
		node = node->right_;
	}
	return node->data_;
}
template<typename Type>
Type Tree<Type>::getMin()
{
	Node<Type>* node = root_;
	while (node->left_ != nullptr)
	{
		node = node->left_;
	}
	return node->data_;
}
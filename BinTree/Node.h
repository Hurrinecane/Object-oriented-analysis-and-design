#pragma once

template <typename Type> class Tree;

template <typename Type> class Node
{
	friend class Tree<Type>;

public:
	Node(const Type&);

private:
	Type data_;
	Node<Type>* left_;
	Node<Type>* right_;
};

template<typename Type>
inline Node<Type>::Node(const Type& data)
{
	data_ = data;
	Node<Type>* left_ = nullptr;
	Node<Type>* right_ = nullptr;
}
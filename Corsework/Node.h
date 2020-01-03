#pragma once

template<typename Type>
class List;
#include "List.h"

template<typename Type>
class Node
{
	friend List<Type>;
public:
	Node();
	~Node();
private:
	Type* object;
	Node* next;
	Node* prev;
};

template<typename Type>
inline Node<Type>::Node()
{
	object = nullptr;
	next = prev = nullptr;
}

template<typename Type>
inline Node<Type>::~Node()
{
	delete object;
}
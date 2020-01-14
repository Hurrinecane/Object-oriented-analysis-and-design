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
	Node<Type> operator = (const Node<Type>&);
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
	if (this)
	{
		Node<Type>* tmp = this;
		while (tmp->next != nullptr)
			tmp = tmp->next;
		while (tmp->prev != nullptr)
		{
			tmp = tmp->prev;
			delete tmp->next->object;
			tmp->next = nullptr;
		}
		delete tmp->object;
	}
}

template<typename Type>
Node<Type> Node<Type>::operator = (const Node<Type>& other)
{
	if (object)
		delete object;
	object = other.object;
	return this;
}
#pragma once


#include"Node.h"

template<typename Type>
class Node;

template<typename Type>
class List
{
public:
	List();
	~List();

	void Add();
	Type* GetObj();

	void Next();
	void Prev();

	Type* curObject;
private:
	Node<Type>* node;
};

template<typename Type>
inline List<Type>::List()
{
	node = nullptr;
	curObject = nullptr;
}

template<typename Type>
inline List<Type>::~List()
{
	Node<Type>* tmp = node;
	while (tmp->next != nullptr)
		tmp = tmp->next;
	while (tmp->prev != nullptr)
	{
		tmp = tmp->prev;
		delete tmp->next;
		tmp->next = nullptr;
	}
	delete tmp;
	node = nullptr;
	curObject = nullptr;
}

template<typename Type>
inline void List<Type>::Add()
{
	if (node == nullptr)
	{
		node = new Node<Type>;
		node->object = new Type;
		curObject = node->object;
	}
	else
	{
		Node<Type>* tmp = new Node<Type>;
		tmp->object = new Type;
		tmp->next = node->next;
		node->next = tmp;
		tmp->prev = node;
		node = tmp;
		curObject = node->object;
	}
}

template<typename Type>
inline Type* List<Type>::GetObj()
{
	if (node == nullptr)
		this->Add();
	return node->object;
}

template<typename Type>
inline void List<Type>::Next()
{
	if (node->next != nullptr)
	{
		node = node->next;
		curObject = node->object;
	}
}

template<typename Type>
inline void List<Type>::Prev()
{

	if (node->prev != nullptr)
	{
		node = node->prev;
		curObject = node->object;
	}
}

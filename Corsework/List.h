/*6.	Ўаблон структуры данных Ц двусв€зный список (нециклический), каждый элемент списка содержит указатель на объект.
ƒл€ ускорени€ процедуры обхода структуры данные имеетс€ динамический массив указателей на каждый 10-ый эле6мент списка (0,10,20).*/
#pragma once
#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;

#include"Node.h"

template<typename Type>
class Node;

template<typename Type>
class List
{
public:
	List();
	List(const List<Type>&);
	~List();
	void Free();

	void Add();

	void Next();
	void Prev();

	void Print();

	List<Type> operator= (const List<Type>&);

	Type* GetObj();

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
List<Type>::~List()
{
	this->Free();
}

template<typename Type>
inline void List<Type>::Free()
{
	delete this->node;
	node = nullptr;
	curObject = nullptr;
}

template<typename Type>
void List<Type>::Add()
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

template<typename Type>
void List<Type>::Print()
{
	cout << "ќбъекты списка " << this << endl;
	while (node->next != nullptr)
		Next();
	cout << endl << curObject << endl;
	while (node->prev != nullptr)
	{
		cout << "\t\\/" << endl;
		Prev();
		cout << curObject << endl;
	}
}

template<typename Type>
List<Type>::List(const List<Type>& other)
{
	node = nullptr;
	curObject = nullptr;
	Node<Type>* tmp = other.node;
	while (tmp->prev != nullptr)
		tmp = tmp->prev;
	this->Add();
	*node->object = *tmp->object;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
		Add();
		*node->object = *tmp->object;
	}
	curObject = node->object;
}

template<typename Type>
List<Type> List<Type>::operator= (const List<Type>& other)
{
	if (this == &other) return *this;
	Free();
	Node<Type>* tmp = other.node;
	while (tmp->prev != nullptr)
		tmp = tmp->prev;
	Add();
	*node->object = *tmp->object;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
		Add();
		*node->object = *tmp->object;
	}
	curObject = node->object;
	return *this;
}

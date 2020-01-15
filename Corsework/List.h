/*6.	Шаблон структуры данных – двусвязный список (нециклический), каждый элемент списка содержит указатель на объект.
Для ускорения процедуры обхода структуры данныx имеется динамический массив указателей на каждый 10-ый элемент списка (0,10,20).*/
#pragma once
#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;

#pragma region Node

template<typename Type>
class List;

template<typename Type>
class Node
{
	friend List<Type>;
public:
	Node();
	~Node();
	Node<Type> operator = (const Node<Type>&);
private:
	unsigned int number;
	Type* object;
	Node* next;
	Node* prev;
};

template<typename Type>
inline Node<Type>::Node()
{
	number = 0;
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
	return *this;
}

#pragma endregion

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
	void JumpForvard();
	void JumpBuck();

	void Print();
	void PrintCur();

	List<Type> operator= (const List<Type>&);

	Type* GetObj();

	Type* curObject;
private:
	Node<Type>* node;
	vector<Node<Type>*> fastTravel;
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
	fastTravel.clear();
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
		fastTravel.push_back(node);
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
		for (Node<Type>* i = node; i != nullptr; i = i->next)
		{
			i->number = i->prev->number + 1;
			if (i->number % 10 == 0)
				if (fastTravel.size() < i->number / 10 + 1)
					fastTravel.push_back(node);
				else
					fastTravel[i->number] = i;
		}

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
inline void List<Type>::JumpForvard()
{
	if (node->next)
		for (Node<Type> * i = node->next; i != nullptr; i = i->next)
			for (int j = 0; j < fastTravel.size(); j++)
				if (fastTravel[j] == i)
				{
					node = i;
					curObject = node->object;
					return;
				}
}

template<typename Type>
inline void List<Type>::JumpBuck()
{
	if ( node->prev)
		for (Node<Type> * i = node->prev; i != nullptr; i = i->prev)
			for (int j = fastTravel.size() - 1; j >= 0; j--)
				if (fastTravel[j] == i)
				{
					node = i;
					curObject = node->object;
					return;
				}
}

template<typename Type>
void List<Type>::Print()
{
	Node<Type>* tmp = node;
	cout << "Объекты списка " << this << endl;
	while (tmp->next != nullptr)
		tmp = tmp->next;
	cout << endl << tmp->number << ": " << curObject << endl;
	while (tmp->prev != nullptr)
	{
		cout << "\t\\/" << endl;
		tmp = tmp->prev;
		cout << tmp->number << ": " << curObject << endl;
	}
}

template<typename Type>
inline void List<Type>::PrintCur()
{
	cout << endl<<"Текущий объект: " << node->number << ": " << curObject << endl;
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
	Add();
	Node<Type>* tmp = other.node;
	while (tmp->prev != nullptr)
		tmp = tmp->prev;
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

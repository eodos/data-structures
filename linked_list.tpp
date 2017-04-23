#include "linked_list.hpp"
#include <iostream>

template <class T>
Node<T>::Node()
{
	this -> next = nullptr;
	this -> data = T();
}

template <class T>
Node<T>::Node(T data)
{
	this -> next = nullptr;
	this -> data = data;
}

template <class T>
Node<T>::Node(T data, Node* pNext)
{
	this -> next = pNext;
	this -> data = data;
}

template <class T>
T Node<T>::getData()
{
	return this -> data;
}


template <class T>
LinkedList<T>::LinkedList()
{
	this -> head = nullptr;
	this -> tail = nullptr;
	this -> size = 0;
}

template <class T>
LinkedList<T>::LinkedList(T value)
{
	this -> head = new Node<T>(value);
	this -> tail = this -> head;
	this -> size = 1;
}

template <class T>
LinkedList<T>::~LinkedList()
{

}

template <class T>
void LinkedList<T>::push(T value)
{
	Node<T>* n = new Node<T>(value);
	n -> next = nullptr;
	this -> tail -> next = n;
	this -> tail = n;
	this -> size++;
}

template <class T>
T LinkedList<T>::pop()
{
	Node<T>* n = this -> head;
	Node<T>* n_prev;

	while (n -> next)
	{
		n_prev = n;
		n = n -> next;
	}

	n_prev -> next = nullptr;
	this -> tail = n_prev;
	this -> size--;
	return n -> getData();
}

template <class T>
void LinkedList<T>::print()
{
	Node<T>* n = this -> head;

	while (n)
	{
		std::cout << n -> getData() << std::endl;
		n = n -> next;
	}
	std::cout << "------" << std::endl;
}

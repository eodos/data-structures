#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP 1

#include "node.hpp"

template <class T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	int size;

public:
	LinkedList();
	LinkedList(T value);
	~LinkedList();

	void push(T value);
	T pop(void);
	void print(void);
};

#include "linkedlist.tpp"

#endif
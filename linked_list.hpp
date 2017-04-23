#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

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

#include "linked_list.tpp"

#endif
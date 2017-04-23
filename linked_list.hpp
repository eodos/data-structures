#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

template <class T>
class Node
{
private:
	T data;	

public:
	Node* next;

	Node();
	Node(T value);
	Node(T value, Node* pNext);

	T getData();
};

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
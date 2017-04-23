#ifndef NODE_HPP
#define NODE_HPP

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

#include "node.tpp"

#endif
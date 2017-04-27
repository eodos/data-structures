#ifndef NODE_HPP
#define NODE_HPP 1

template <class T>
class Node
{
private:
	T data;

public:
	Node* left;
	Node* right;

	Node();
	Node(T value);

	T getData();
};

#include "node.tpp"

#endif
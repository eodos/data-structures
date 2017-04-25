#ifndef BTREE_H
#define BTREE_H 1

#include "node.hpp"

template <class T>
class Btree {
public:
	Btree();
	Btree(T data);
	~Btree();

	void insert(T data);
	Node<T>* search(T data);
	void destroy();

	void print();

private:
	Node<T>* root;

	void insert(Node<T> *leaf, T data);
	Node<T>* search(Node<T> *leaf, T data);
	void destroy(Node<T> *leaf);

	void print(Node<T> *leaf);
};

#include "btree.tpp"

#endif
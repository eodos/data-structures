#include "btree.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
	Btree<int> tree = Btree<int>();
	tree.insert(1);
	tree.insert(2);
	tree.insert(0);
	tree.insert(-4);
	tree.insert(3);
	tree.print();
	return 0;
}
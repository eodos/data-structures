#include <iostream>
#include "linkedlist.hpp"

int main(int argc, char const *argv[])
{
	LinkedList<int> l = LinkedList<int>(1);
	l.print();
	l.push(2);
	l.print();
	l.push(3);
	l.print();
	std::cout << "Pop: " << l.pop() << std::endl;
	l.print();
	l.push(2);
	l.print();

	return 0;
}
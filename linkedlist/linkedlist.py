#!/usr/bin/env python

class Node:
    def __init__(self, value, next_node=None):
        self.__value = value
        self.__next = next_node

    def get_value(self):
        return self.__value

    def set_value(self, value):
        self.__value = value

    def get_next(self):
        return self.__next

    def set_next(self, next_node):
        self.__next = next_node


class LinkedList:
    def __init__(self,  root=None):
        self.__size = 0
        self.__root = root

    def get_size(self):
        return self.__size

    def add(self, value):
        new_node = Node(value, self.__root)
        self.__root = new_node
        self.__size += 1

    def delete(self, value):
        this_node = self.__root
        previous_node = None
        while this_node:
            if this_node.get_value() == value:
                if previous_node:
                    previous_node.set_next(this_node.get_next())
                else:
                    self.__root = this_node.get_next()
                self.__size -= 1
                return True
            else:
                previous_node = this_node
                this_node = this_node.get_next()
        return False

    def find(self, value):
        this_node = self.__root
        while this_node:
            if this_node.get_value() == value:
                return this_node.get_value()
            else:
                this_node = this_node.get_next()
        return None

    def print_list(self):
        this_node = self.__root
        while this_node:
            print(this_node.get_value())
            this_node = this_node.get_next()

linkedList = LinkedList()

linkedList.add(5)
linkedList.add(10)
linkedList.add('dog')

linkedList.print_list()
print('Size: {}'.format(linkedList.get_size()))
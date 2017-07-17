#!/usr/bin/env python

class HashTable:
    def __init__(self, size):
        self.__size = size
        self.__table = [[] for _ in range(size)]

    def __hash_function(self, x):
        return x % self.__size

    def add(self, key, value):
        self.__table[self.__hash_function(key)].append([key, value])

    def delete(self, key):
        if self.__table[self.__hash_function(key)]:
            for i, pair in enumerate(self.__table[self.__hash_function(key)]):
                if pair[0] == key:
                    del self.__table[self.__hash_function(key)][i]

    def search(self, key):
        if self.__table[self.__hash_function(key)]:
            for pair in self.__table[self.__hash_function(key)]:
                if pair[0] == key:
                    return pair[1]
        return None

    def print_table(self):
        print('----------')
        for i in range(self.__size):
            print('{}: {}'.format(i, self.__table[i]))
        print('----------')

h = HashTable(10)
h.add(15, 'dog')
h.add(25, 'cat')

h.print_table()

print(h.search(25))
h.delete(25)
print(h.search(25))

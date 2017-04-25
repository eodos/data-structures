all: linked_list

linked_list:
	g++ --std=c++11 linkedlist/linkedlist_test.cpp -o linkedlist/linkedlist.out

clean:
	rm *.out
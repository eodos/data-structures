all: linked_list

linked_list:
	g++ --std=c++11 linked_list_test.cpp -o linked_list.out

clean:
	rm *.out
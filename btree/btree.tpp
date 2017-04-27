#include <iostream>

template <class T>
Btree<T>::Btree() {
	root = nullptr;
}

template <class T>
Btree<T>::Btree(T data) {
	root = nullptr;
	Btree::insert(data);
}

template <class T>
Btree<T>::~Btree() {
	destroy();
}

template <class T>
void Btree<T>::insert(T data) {
	if (root != nullptr) {
		insert(root, data);
	}
	else {
		root = new Node<T>(data);
		root -> left = nullptr;
		root -> right = nullptr;
	}
}

template <class T>
void Btree<T>::insert(Node<T>* leaf, T data) {
	if (data < leaf -> getData()) {
		if (leaf -> left != nullptr) {
			insert(leaf -> left, data);
		}
		else {
			leaf -> left = new Node<T>(data);
			leaf -> left -> left = nullptr;
			leaf -> left -> right = nullptr;
		}
	}
	else {
		if (leaf -> right != nullptr) {
			insert(leaf -> right, data);
		}
		else {
			leaf -> right = new Node<T>(data);
			leaf -> right -> left = nullptr;
			leaf -> right -> right = nullptr;
		}
	}
}

template <class T>
void Btree<T>::destroy() {
	destroy(root);
}

template <class T>
void Btree<T>::destroy(Node<T>* leaf) {
	if (leaf != nullptr) {
		destroy(leaf -> left);
		destroy(leaf -> right);
		delete leaf;
	}
}

template <class T>
Node<T>* Btree<T>::search(T data) {
	search(root, data);
}

template <class T>
Node<T>* Btree<T>::search(Node<T>* leaf, T data) {
	if (leaf != nullptr) {
		if (data == leaf -> getData()) {
			return leaf;
		}
		else if (data < leaf -> data) {
			return search(leaf -> left, data);
		}
		else {
			return search(leaf -> right, data);
		}
	}
	return nullptr;
}

template <class T>
void Btree<T>::print() {
	print(root);
}

template <class T>
void Btree<T>::print(Node<T>* leaf) {
	if (leaf != nullptr) {
		std::cout << leaf -> getData() << std::endl;
		print(leaf -> left);
		print(leaf -> right);
	}
}
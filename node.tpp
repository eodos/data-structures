template <class T>
Node<T>::Node()
{
	this -> next = nullptr;
	this -> data = T();
}

template <class T>
Node<T>::Node(T data)
{
	this -> next = nullptr;
	this -> data = data;
}

template <class T>
Node<T>::Node(T data, Node* pNext)
{
	this -> next = pNext;
	this -> data = data;
}

template <class T>
T Node<T>::getData()
{
	return this -> data;
}
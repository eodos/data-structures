template <class T>
Node<T>::Node()
{
	this -> left = nullptr;
	this -> right = nullptr;
	this -> data = T();
}

template <class T>
Node<T>::Node(T data)
{
	this -> left = nullptr;
	this -> right = nullptr;
	this -> data = data;
}

template <class T>
T Node<T>::getData()
{
	return this -> data;
}
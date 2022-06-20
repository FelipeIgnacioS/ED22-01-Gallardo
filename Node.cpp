#include "Node.hpp"
 
template<typename T>
 
Node<T>::Node()
{
    data = NULL;
    next = NULL;
}
 
template<typename T>
Node<T>::Node(T p)
{
    data = p;
    next = NULL;
}

Node Node::getNext

Node<T>::~Node() {}
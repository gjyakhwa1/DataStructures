#pragma once
//Creating node
#include<iostream>
template<class T>
class Node {
public:
    T data;
    Node<T>* next;
    Node();
    Node(T data);
};
template <class T>
Node<T>::Node()
{
    next = NULL;
}
template<class T>
Node<T>::Node(T data)
{
    this->data = data;
}

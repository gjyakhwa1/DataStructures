#pragma once
#include<string>
#include<iostream>
#include "Node.h"
#include "NODEDOESNOTEXIT.h"
#include "EMPTYLIST.h"
template <class T>
class LinkedList
{
protected:
    Node<T>* head;
public:
    LinkedList();
    Node<T>* node_exists(T data);   //Check if a node with given data already exists or not
    void insert_front(T data);    //Inserting node at the beginning
    void insert_back(T data);    //Inserting node at the end
    void insert_after(T data_to_insert, T data_to_insert_after);    //Inserting node after given node
    void insert_before(T data_to_insert, T data_to_insert_before);    //Inserting node before given node
    void remove_front();    //removing the node at the beginning
    void remove_back();    //removing the node at end
    void remove_after(T data_to_remove_after);    //removing node after the given node
    void display();    //Display the data in the node
    ~LinkedList();    //Deallocating dynamically allocated memory
};


template<class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
}
//Check if a node with given data already exists or not
template<class T>
Node<T>* LinkedList<T>::node_exists(T data)
{
    Node<T>* temp = NULL;
        Node<T>* ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data == data)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
}

//Inserting node at the beginning
template<class T>
void LinkedList<T>::insert_front(T data)
{
    Node<T>* n;
    n = new Node<T>;
    n->data = data;
    if (node_exists(n->data) != NULL)
    {
        std::cout << "Node with the following data already exists" << std::endl;
    }
    else
    {
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            n->next = head;
            head = n;
        }
    }
}

//Inserting node at the end
template<class T>
void LinkedList<T>::insert_back(T data)
{
    Node<T>* n;
    n = new Node<T>;
    n->data = data;
    Node<T>* ptr;
    ptr = head;
    if (node_exists(data) != NULL)
    {
        std::cout << "Node with the following data already exists" << std::endl;
    }
    else
    {
        if (head == NULL)
        {
            insert_front(data);
        }
        else
        {
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = n;
        }
    }
}

//Inserting node after given node
template<class T>
void LinkedList<T>::insert_after(T data_to_insert, T data_to_insert_after)
{
    if (node_exists(data_to_insert_after) == NULL)
    {
        std::cout << "Node with given data not found" << std::endl;
    }
    else
    {
        Node<T>* n = new Node<T>;
        n->data = data_to_insert;
        Node<T>* ptr;
        ptr = head;
        while (ptr->data != data_to_insert_after)
        {
            ptr = ptr->next;
        }
        n->next = ptr->next;
        ptr->next = n;
    }
}

//Inserting node before given node


template<class T>
void LinkedList<T>::insert_before(T data_to_insert, T data_to_insert_before)
{
    if (node_exists(data_to_insert_before) == NULL)
    {
        std::cout << "Node with given data not found" << std::endl;
    }
    else
    {
        Node<T>* n = new Node<T>;
        n->data = data_to_insert;
        Node<T>* ptr;
        ptr = head;
        while (ptr->next->data != data_to_insert_before)
        {
            ptr = ptr->next;
        }
        n->next = ptr->next;
        ptr->next = n;
    }
}

//removing the node at the beginning
template<class T>
void LinkedList<T>::remove_front()
{
    Node<T>* ptr = head;
    if (head == NULL)
    {
        throw EMPTYLIST();
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        head = ptr->next;
    }
    delete ptr;
}

//removing the node at end
template<class T>
void LinkedList<T>::remove_back()
{
    if (head == NULL)
    {
        throw EMPTYLIST();
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        Node<T>* preptr = head, * ptr = head;
        ptr = ptr->next;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            preptr = preptr->next;
        }
        preptr->next = NULL;
        delete ptr;
    }
}

//removing node after the given node
template<class T>
void LinkedList<T>::remove_after(T data_to_remove_after)
{
    if (node_exists(data_to_remove_after) == NULL)
    {
        throw NODEDOESNOTEXIST();
    }
    else
    {
        Node<T>* ptr = head, * preptr = head;
        ptr = ptr->next;
        while (preptr->data != data_to_remove_after)
        {
            ptr = ptr->next;
            preptr = preptr->next;
        }
        if (ptr == NULL)
        {
            std::cout << "No node to remove" << std::endl;
            return;
        }
        preptr->next = ptr->next;
        delete ptr;
    }
}
//displaying all the elements of the linked list
template<class T>
void LinkedList<T>::display()
{
    Node<T>* ptr;
        ptr = head;
        while (ptr != NULL)
        {
            std::cout << ptr->data << "-->";
            ptr = ptr->next;
        }
        std::cout << "\n";
}

//Deallocating dynamically allocated memory
template<class T>
LinkedList<T>::~LinkedList()
{
    Node<T>* p, * q;
    p = head;
    q = p->next;
    while (q != NULL)
    {
        delete p;
        p = q;
        q = p->next;
    }
}

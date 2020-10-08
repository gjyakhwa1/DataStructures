#include<iostream>
//creating a class node
template <class T>
class Node
{
public:
  T data;
  Node<T> *prev;
  Node<T> *next;
  Node()
  {
    prev=NULL;
    next=NULL;
  }
  Node(T data)
  {
    this->data=data;
    prev=NULL;
    next=NULL;
  }
};
template<class T>
class DoublyLinkedList
{
private:
  Node<T> *head;
public:
  DoublyLinkedList();//Initialization
  Node<T>* node_exist(T data);//check whether node with given data exist or not
  void insert_front(T data);//inserting node at the front of list
  void insert_back(T data);//inseting node at the end of the list
  void insert_after(T data,T after);//inserting node after given node
  void insert_before(T data,T before);//inserting node before given node
  void remove_front();//removing node from front
  void remove_back();//removing node at the end
  void remove_after(T after);//removing node after a given node
  void remove_before(T before);//removing node before a given node
  void display();//displaying all the elments of the node
  ~DoublyLinkedList();//deallocating dynamically allocated memory
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  head=NULL;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  Node<T> *p,*q;
  p=head;
  q=p->next;
  while(p!=NULL)
  {
    delete p;
    p=q;
    q=p->next;
  }
}

template <class T>
void DoublyLinkedList<T>::display()
{
  Node<T> *ptr{head};
  while(ptr!=NULL)
  {
    std::cout<<ptr->data<<"<-->";
    ptr=ptr->next;
  }
  std::cout<<std::endl;
}

template<class T>
Node<T>* DoublyLinkedList<T>::node_exist(T data)
{
  Node<T> *ptr{head},*temp{NULL};
  while(ptr!=NULL)
  {
    if(ptr->data==data)
    {
      temp=ptr;
    }
    ptr=ptr->next;
  }
  return temp;
}

template<class T>
void DoublyLinkedList<T>::insert_front(T data)
{
  Node<T> *ptr=new Node<T>(data);
  if(head==NULL)
  {
    head=ptr;
  }
  else
  {
    Node<T> *temp{head};
    ptr->next=temp;
    temp->prev=ptr;
    head=ptr;
  }
}

template<class T>
void DoublyLinkedList<T>::insert_back(T data)
{
  Node<T> *ptr=new Node<T>(data);
  if(head==NULL)
  {
    head=ptr;
  }
  else
  {
    Node<T> *temp{head};
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    ptr->prev=temp;
    temp->next=ptr;
  }
}

template<class T>
void DoublyLinkedList<T>::insert_after(T data,T after)
{
  if(node_exist(after)==NULL)
  {
    throw "Node doesnot exist";
  }
  else
  {
    Node<T> *ptr=new Node<T>(data);
    if(head==NULL)
    {
      head=ptr;
    }
    else
    {
      Node<T> *temp{head};
      while(temp->data!=after)
      {
        temp=temp->next;
      }
      ptr->next=temp->next;
      ptr->prev=temp;
      temp->next->prev=ptr;
      temp->next=ptr;
    }
  }
}

template<class T>
void DoublyLinkedList<T>::insert_before(T data,T before)
{
  if(node_exist(before)==NULL)
  {
    throw "Node doesnot exist";
  }
  else
  {
      Node<T> *ptr=new Node<T>(data);
      if(head==NULL)
      {
        head=ptr;
      }
      else
      {
        Node<T> *temp{head};
        while(temp->data!=before)
        {
          temp=temp->next;
        }
        ptr->next=temp;
        ptr->prev=temp->prev;
        temp->prev->next=ptr;
        temp->prev=ptr;
      }
  }
}

template<class T>
void DoublyLinkedList<T>::remove_front()
{
  if(head==NULL)
  {
    throw "Empty List";
  }
  else
  {
    Node<T> *temp{head};
    if(temp->next==NULL)
    {
      head=NULL;
    }
    else
    {
      Node<T> *ptr{head};
      ptr->next->prev=NULL;
      head=ptr->next;
    }
    delete temp;
  }
}

template<class T>
void DoublyLinkedList<T>::remove_back()
{
  if(head==NULL)
  {
    throw "Empty List";
  }
  else
  {
    Node<T> *ptr{head};
    while(ptr->next!=NULL)
    {
      ptr=ptr->next;
    }
    Node<T> *temp{ptr->prev};
    temp->next=NULL;
    ptr->prev=NULL;
    delete ptr;
  }
}

template<class T>
void DoublyLinkedList<T>::remove_after(T after)
{
  if(node_exist(after)==NULL)
  {
    throw "Node deosnot exist";
  }
  else
  {
    Node<T> *ptr{head};
    while(ptr->data!=after)
    {
      ptr=ptr->next;
    }
    if(ptr->next==NULL)
    {
      throw "No item to delete";
    }
    else if(ptr->next->next==NULL)
    {
      remove_back();
    }
    else
    {
      Node<T> *temp;
      temp=ptr->next;
      ptr->next=temp->next;
      temp->next->prev=ptr;
      delete temp;
    }
  }
}

template<class T>
void DoublyLinkedList<T>::remove_before(T before)
{
  if(node_exist(before)==NULL)
  {
    throw "Node deosnot exist";
  }
  else
  {
    Node<T> *ptr{head};
    while(ptr->data!=before)
    {
      ptr=ptr->next;
    }
    if(ptr->prev==NULL)
    {
      throw "No item to delete";
    }
    else if(ptr->prev->prev==NULL)
    {
      remove_front();
    }
    else
    {
      Node<T> *temp;
      temp=ptr->prev;
      ptr->prev=temp->prev;
      temp->prev->next=ptr;
      delete temp;
    }
  }
}

int main()
{
  DoublyLinkedList<int> n;
  try{
  n.insert_front(1);
  n.display();
  n.insert_back(2);
  n.display();
  n.insert_after(3,1);
  n.display();
  n.insert_before(4,3);
  n.display();
  n.insert_before(5,4);
  n.display();
  n.remove_after(5);
  n.display();
  n.remove_before(2);
  n.display();
  n.remove_front();
  n.display();
  n.remove_back();
  n.display();
}
catch(const char *s)
{
  std::cout<<"Error:"<<s<<std::endl;
}
  return 0;
}

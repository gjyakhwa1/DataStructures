#include<iostream>
//Error that can occur in linked list
class CUSTOMERROR
{
private:
  std::string exception;
public:
  CUSTOMERROR()
  {
    exception='\0';
  }
  CUSTOMERROR(std::string exception)
  {
    this->exception=exception;
  }
  std::string get_exception()
  {
    return exception;
  }
};
class EMPTYLIST:public CUSTOMERROR
{
public:
  EMPTYLIST():CUSTOMERROR("Removing from empty list is not possible"){}
};
class NODENOTEXIST:public CUSTOMERROR
{
public:
  NODENOTEXIST():CUSTOMERROR("Trying to remove a node after a node that does not exist"){}
};

//Creating node
template<class T>
class Node{
public:
  T data;
  Node<T> *next;
  Node()
  {
    next=NULL;
  }
  Node(T data)
  {
    this->data=data;
  }
};

//Creating linked list
template<class T>
class Linked_list
{
public:
  Node<T> *head;
  Linked_list()
  {
    head=NULL;
  }
  //Check if a node with given data already exists or not
  Node<T>* node_exists(T data)
  {
    Node<T> *temp=NULL;
    Node<T> *ptr=head;
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

  //Inserting node at the beginning
  void insert_front(T data)
  {
    Node<T>* n;
    n=new Node<T>;
    n->data=data;
    if(node_exists(n->data)!=NULL)
    {
      std::cout<<"Node with the following data already exists"<<std::endl;
    }
    else
    {
      if(head==NULL)
      {
        head=n;
      }
      else
      {
        n->next=head;
        head=n;
      }
    }
  }

  //Inserting node at the end
  void insert_back(T data)
  {
    Node<T> *n;
    n=new Node<T>;
    n->data=data;
    Node<T> *ptr;
    ptr=head;
    if(node_exists(data)!=NULL)
    {
      std::cout<<"Node with the following data already exists"<<std::endl;
    }
    else
    {
      if(head==NULL)
      {
        insert_front(data);
      }
      else
      {
        while(ptr->next!=NULL)
        {
          ptr=ptr->next;
        }
        ptr->next=n;
      }
    }
  }

  //Inserting node after given node
  void insert_after(T data_to_insert,T data_to_insert_after)
  {
    if(node_exists(data_to_insert_after)==NULL)
    {
      std::cout<<"Node with given data not found"<<std::endl;
    }
    else
    {
      Node<T> *n=new Node<T>;
      n->data=data_to_insert;
      Node<T> *ptr;
      ptr=head;
      while(ptr->data!=data_to_insert_after)
      {
        ptr=ptr->next;
      }
      n->next=ptr->next;
      ptr->next=n;
    }
  }

  //Inserting node before given node
  void insert_before(T data_to_insert,T data_to_insert_before)
  {
    if(node_exists(data_to_insert_before)==NULL)
    {
      std::cout<<"Node with given data not found"<<std::endl;
    }
    else
    {
      Node<T> *n=new Node<T>;
      n->data=data_to_insert;
      Node<T> *ptr;
      ptr=head;
      while(ptr->next->data!=data_to_insert_before)
      {
        ptr=ptr->next;
      }
      n->next=ptr->next;
      ptr->next=n;
    }
  }

  //removing the node at the beginning
  void remove_front()
  {
    Node<T> *ptr=head;
    if(head==NULL)
    {
      throw EMPTYLIST();
    }
    else if(head->next==NULL)
    {
      head=NULL;
    }
    else
    {
    head=ptr->next;
    }
    delete ptr;
  }

  //removing the node at end
  void remove_back()
  {
    if(head==NULL)
    {
      throw EMPTYLIST();
    }
    else if(head->next==NULL)
    {
      head=NULL;
    }
    else
    {
      Node<T> *preptr=head,*ptr=head;
      ptr=ptr->next;
      while(ptr->next!=NULL)
      {
        ptr=ptr->next;
        preptr=preptr->next;
      }
      preptr->next=NULL;
      delete ptr;
    }
  }

  //removing node after the given node
  void remove_after(T data_to_remove_after)
  {
    if(node_exists(data_to_remove_after)==NULL)
    {
      throw NODENOTEXIST();
    }
    else
    {
      Node<T> *ptr=head,*preptr=head;
      ptr=ptr->next;
      while(preptr->data!=data_to_remove_after)
      {
        ptr=ptr->next;
        preptr=preptr->next;
      }
      if(ptr==NULL)
      {
        std::cout<<"No node to remove"<<std::endl;
        return;
      }
      preptr->next=ptr->next;
      delete ptr;
    }
  }

  //Display the data in the node
  void display()
  {
    Node<T>* ptr;
    ptr=head;
    while(ptr!=NULL)
    {
      std::cout<<ptr->data<<"-->";
      ptr=ptr->next;
    }
    std::cout<<"\n";
  }

  //Deallocating dynamically allocated memory
  ~Linked_list()
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
};

int main()
{
  Linked_list<std::string> l;
  try{
  l.insert_front("one");
  l.display();
  l.insert_front("two");
  l.insert_front("three");
  l.display();
  l.remove_front();
  l.display();
  l.insert_after("four","two");
  l.display();
  l.insert_before("five","four");
  l.display();
  l.remove_after("five");
  l.display();
  l.insert_back("six");
  l.display();
  l.insert_back("seven");
  l.display();
  l.remove_back();
  l.display();
}
catch(EMPTYLIST e)
{
  std::cout<<"Error:"<<e.get_exception();
}
catch(NODENOTEXIST e)
{
  std::cout<<"Error:"<<e.get_exception();
}
  return 0;
}

#include<iostream>
const int max=10;
class Node
{
public:
  int data;
  int next;
  Node()
  {
    next=-1;
  }
  Node(int data)
  {
    this->data=data;
    next=-1;
  }
};
class CustomList
{
private:
  int head;
  int avail;
  int arr[max];
public:
  CustomList()
  {
    head=0;
    avail=0;
  }
  void insert(int data)
  {
    Node n(data);
    if(avail>max)
    {
      std::cout<<"Error"<<std::endl;
      return;
    }
    else if(avail==0)
    {
      arr[avail]=n.data;
    }
    else
    {
      int temp=head;
      while(temp!=-1)
      {
        temp=n.next;
      }

    }
  }
};

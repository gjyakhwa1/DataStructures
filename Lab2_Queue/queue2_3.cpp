//Qno-2

#include<iostream>
const int MAX=4;
//To check error in queue
class QUEUE_ERR
{
private:
  std::string exception;
public:
  QUEUE_ERR(std::string exception)
  {
    this->exception=exception;
  }
  std::string get_exception()
  {
    return exception;
  }
};

class QUEUE_UNDERFLOW:public QUEUE_ERR
{
public:
  QUEUE_UNDERFLOW():QUEUE_ERR("Queue underflow"){}
};
class QUEUE_OVERFLOW:public QUEUE_ERR
{
public:
  QUEUE_OVERFLOW():QUEUE_ERR("Queue overflow"){}
};

//Creating a circular queue
template<class T>
class Circular_Queue
{
protected:
  int front;
  int rear;
  T arr[MAX];
public:
  //decalration of methods in circular queue
  Circular_Queue();
  void enqueue(T item);
  T dequeue();
  void display();
  bool is_empty();
  bool is_full();
};
//definition of methods in circular queue
template<class T>
Circular_Queue<T>::Circular_Queue()
{
  front=-1;
  rear=-1;
}
template<class T>
bool Circular_Queue<T>::is_empty()
{
  return front==-1?true:false;
}
template<class T>
bool Circular_Queue<T>::is_full()
{
  return front==(rear+1)%MAX?true:false;
}
template<class T>
void Circular_Queue<T>::enqueue(T item)
{
  if(is_full())
  {
    throw QUEUE_OVERFLOW();
  }
  else
  {
    if(front==-1)
    {
      front=0;
    }
    rear=(rear+1)%MAX;
    arr[rear]=item;
  }
}
template<class T>
T Circular_Queue<T>::dequeue()
{
  if(is_empty())
  {
    throw QUEUE_UNDERFLOW();
  }
  else
  {
    T temp;
    temp=arr[front];
    if(front==rear)
    {

      front=-1;
      rear=-1;
    }
    else
    {
      front=(front+1)%MAX;
    }
    return temp;
  }
}
template<class T>
void Circular_Queue<T>::display()
{
  if(is_empty())
  {
    std::cout<<"Queue is empty"<<std::endl;
  }
  else
  {
    if(front>rear)
    {
      for(int i=front;i<MAX;i++)
      {
        std::cout<<arr[i]<<" ";
      }
      for(int i=0;i<=rear;i++)
      {
        std::cout<<arr[i]<<" ";
      }
      std::cout<<std::endl;
    }
    else
    {
    for(int i=front;i<=rear;i++)
    {
      std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
  }
}
}

//main for Circular_Queue

int main()
{
  Circular_Queue<int> a;
  try
  {
    a.enqueue(1);
    a.enqueue(2);
    a.display();
    a.dequeue();
    a.display();
    a.enqueue(3);
    a.enqueue(4);
    a.display();
    a.dequeue();
    a.display();
    a.enqueue(5);
    a.display();
    a.dequeue();
    a.dequeue();
    a.display();
    a.dequeue();
    a.display();
    a.dequeue();
  }
  catch(QUEUE_OVERFLOW s)
  {
    std::cout<<"Error:"<<s.get_exception()<<std::endl;
  }
  catch(QUEUE_UNDERFLOW s)
  {
    std::cout<<"Error:"<<s.get_exception();
  }
}

//Qno-3

//creating a circular dequeue
template<class T>
class Deque:public Circular_Queue<T>
{
public:
  Deque();
  void enqueue_front(T item);
  void enqueue_rear(T item);
  T dequeue_front();
  T dequeue_rear();
  void display();
};
template<class T>
Deque<T>::Deque()
{
  Circular_Queue<T>::front=-1;
  Circular_Queue<T>::rear=-1;
}
template<class T>
void Deque<T>::enqueue_rear(T item)
{
  Circular_Queue<T>::enqueue(item);
}
template<class T>
T Deque<T>::dequeue_front()
{
  T temp;
temp=Circular_Queue<T>::dequeue();
return temp;
}
template<class T>
void Deque<T>::enqueue_front(T item)
{
  if(Circular_Queue<T>::is_full())
  {
    throw QUEUE_OVERFLOW();
  }
  else if(Circular_Queue<T>::front==-1 && Circular_Queue<T>::rear==-1)
  {
    Circular_Queue<T>::front=0;
    Circular_Queue<T>::rear=0;
  }
  else if(Circular_Queue<T>::front==0)
  {
    Circular_Queue<T>::front=MAX-1;
  }
  else
  {
    Circular_Queue<T>::front-=1;
  }
  Circular_Queue<T>::arr[Circular_Queue<T>::front]=item;
}
template<class T>
T Deque<T>::dequeue_rear()
{T temp;
  if(Circular_Queue<T>::is_empty())
  {
    throw QUEUE_UNDERFLOW();
  }
  else if(Circular_Queue<T>::front==Circular_Queue<T>::rear)
  {

    temp=Circular_Queue<T>::arr[Circular_Queue<T>::front];
    Circular_Queue<T>::front=-1;
    Circular_Queue<T>::rear=-1;
  }
  else if(Circular_Queue<T>::rear==0)
  {
    temp=Circular_Queue<T>::arr[Circular_Queue<T>::rear];
    Circular_Queue<T>::rear=MAX-1;
  }
  else
  {
    temp=Circular_Queue<T>::arr[Circular_Queue<T>::rear];
    Circular_Queue<T>::rear-=1;
  }
  return temp;
}
template<class T>
void Deque<T>::display()
{
  Circular_Queue<T>::display();
}

//main for deque
/*
int main()
{
  Deque<int> a;
  try
  {
    a.enqueue_rear(1);
    a.enqueue_front(2);
    a.enqueue_front(0);
    a.display();
    a.dequeue_front();
    a.display();
    a.enqueue_front(3);
    a.enqueue_rear(4);
    a.display();
    a.dequeue_rear();
    a.display();
    a.enqueue_rear(5);
    a.display();
    a.dequeue_front();
    a.dequeue_front();
    a.display();
    a.dequeue_front();
    a.display();
    a.dequeue_front();
  }
  catch(QUEUE_OVERFLOW exc)
  {
    std::cout<<"Error:"<<exc.get_exception()<<std::endl;
  }
  catch(QUEUE_UNDERFLOW exc)
  {
    std::cout<<"Error:"<<exc.get_exception();
  }
}
*/

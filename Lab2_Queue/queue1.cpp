#include<iostream>
const int MAX=10;
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

//Creating a linear queue
template<class T>
class Linear_Queue
{
private:
  T arr[MAX];
  int front;
  int rear;
public:
  //declaration of method in linear queue
  Linear_Queue();
  void enqueue(T item);
  T dequeue();
  void display();
  bool is_empty();
  bool is_full();
};
//definition of method in linear queue
template<class T>
Linear_Queue<T>::Linear_Queue()
{
  front=0;
  rear=-1;
}
template<class T>
bool Linear_Queue<T>::is_full()
{
  return rear==MAX-1?true:false;
}
template<class T>
bool Linear_Queue<T>::is_empty()
{
  return front>rear?true:false;
}
template<class T>
void Linear_Queue<T>::enqueue(T item)
{
  if(is_full())
  {
    throw QUEUE_OVERFLOW();
  }
  else
  {
    rear++;
    arr[rear]=item;
  }
}
template<class T>
T Linear_Queue<T>::dequeue()
{
  if(is_empty())
  {
    throw QUEUE_UNDERFLOW();
  }
  else
  {
    T temp;
    temp=arr[front];
    front++;
    return temp;
  }
}
template<class T>
void Linear_Queue<T>::display()
{
  if(is_empty())
  {
    std::cout<<"Queue is empty"<<std::endl;
  }
  else{
  for(int i=front;i<=rear;i++)
  {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}
}
int main()
{
  Linear_Queue<std::string> a;
  try
  {
    a.enqueue("One");
    a.enqueue("Two");
    a.display();
    a.dequeue();
    a.display();
    a.enqueue("Three");
    a.enqueue("Four");
    a.display();
    a.dequeue();
    a.display();
    a.dequeue();
    a.dequeue();
    a.display();
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

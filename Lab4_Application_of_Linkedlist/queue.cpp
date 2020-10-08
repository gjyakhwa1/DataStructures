#include "LinkedList.h"
template <class T>
class Queue
{
private:
LinkedList<T> n; 
public:
void enqueue(T data);//inseting data into the queue
void dequeue();//deleteing data from the queue
void display();
};
template<class T>
void Queue<T>::enqueue(T data)
{
    n.insert_back(data);
}
template <class T>
void Queue<T>::dequeue()
{
    n.remove_front();
}
template <class T>
void Queue<T>::display()
{
    n.display();
}
int main()
{
    Queue<std::string> a;
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
  }
  catch(EMPTYLIST s)
  {
    std::cout<<"Error:"<<s.get_exception()<<std::endl;
  }
    return 0;
}
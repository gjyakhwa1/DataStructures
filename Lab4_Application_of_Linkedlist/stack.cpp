#include "LinkedList.h"
template <class T>
class Stack
{
private:
LinkedList<T> n;
public:
    void push(T data);//pushing an item to the stack
    void pop();//removing an item from the stack
    void display();//displaying all the elements from the stack
};
template <class T>
void Stack<T>::push(T data)
{
    n.insert_back(data);
}
template <class T>
void Stack<T>::pop()
{
    n.remove_back();
}
template <class T>
void Stack<T>::display()
{
    n.display();
}

int main()
{
  Stack<int> s;
  try
  {
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    s.push(4);
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.pop();
    s.display();
    s.pop();
    s.push(5);
    s.display();
  }
  catch(EMPTYLIST s)
  {
    std::cout<<"Error:"<<s.get_exception()<<std::endl;
  }
return 0;
}
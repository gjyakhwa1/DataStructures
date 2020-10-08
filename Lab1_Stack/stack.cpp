#include<iostream>
#include<math.h>
#include<string>
const int MAX=15;

//Error that can occur in stack
class STACK_ERR
{
public:
  std::string exception;
  STACK_ERR()
  {
    exception='\0';
  }
  STACK_ERR(std::string exception)
  {
    this->exception=exception;
  }
  std::string get_exception()
  {
    return exception;
  }
};
class STACK_OVERFLOW:public STACK_ERR
{
public:
  STACK_OVERFLOW():STACK_ERR("Stack overflow"){}
};
class STACK_UNDERFLOW:public STACK_ERR
{
public:
  STACK_UNDERFLOW():STACK_ERR("Stack underflow"){}
};

//Creating stack using array
template<class T>
class Stack
{
private:
  T arr[MAX];
  int top;
public:
  Stack();
  void push(T data);
  T pop();
  T peek();
  void display();
  bool is_empty();
  bool is_full();
};
template<class T>
Stack<T>::Stack()
{
  top=-1;
}
template<class T>
void Stack<T>::push(T data)
{
  if(is_full())
  {
    throw STACK_OVERFLOW();
  }
  else
  {
    top++;
    arr[top]=data;
  }
}
template<class T>
T Stack<T>::pop()
{
  if(is_empty())
  {
    throw STACK_UNDERFLOW();
  }
  else
  {
    T temp;
    temp=arr[top];
    top--;
    return temp;
  }
}
template<class T>
T Stack<T>::peek()
{
  if(is_empty())
  {
    throw STACK_UNDERFLOW();
  }
  return arr[top];
}
template<class T>
void Stack<T>::display()
{
  if(is_empty())
  {
    std::cout<<"Stack is empty"<<std::endl;
  }
  for(int i=0;i<=top;i++)
  {
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}
template<class T>
bool Stack<T>::is_empty()
{
  return top==-1?true:false;
}
template<class T>
bool Stack<T>::is_full()
{
  return top==MAX-1?true:false;
}

//reversing a string with swapping parenthesis
std::string reverse(std::string str)
{
  std::string rev;
   for (int i=str.length()-1; i>=0; i--)
    {
      if(str[i]=='(')
      {
        rev+=')';
      }
      else if(str[i]==')')
      {
        rev+='(';
      }
      else{
        rev+=str[i];
      }

    }
    return rev;
}
//To check the precedence
int get_precedence(char op)
{
  if(op=='^')
  {
    return 3;
  }
  else if(op=='*' || op=='/')
  {
    return 2;
  }
  else if(op=='+' || op=='-')
  {
    return 1;
  }
  else
  {
    return -1;
  }
}

//Converting from infix to postfix
std::string infix_to_postfix(std::string text)
{
  Stack<char> a;
  std::string postfix;
  for(int i=0;text[i]!='\0';i++)
  {
    if((text[i]>='A' && text[i]<='Z') || (text[i]>='a' && text[i]<='z'))
    {
      postfix+=text[i];
    }
    else if(text[i]=='(')
    {
      a.push(text[i]);
    }
    else if(text[i]=='+' || text[i]=='-' || text[i]=='/' ||text[i]=='*' || text[i]=='^')
    {
      if(a.is_empty())
      {
        a.push(text[i]);
      }
      else
      {
        if(get_precedence(a.peek())<get_precedence(text[i]))
        {
          a.push(text[i]);
        }
        else
        {
          while(get_precedence(a.peek())>=get_precedence(text[i]))
          {
            postfix+=a.pop();
            if(a.is_empty())
            {
              break;
            }
          }
          a.push(text[i]);
        }
      }
    }
    else if(text[i]==')')
    {
      while(a.peek()!='(')
      {
        postfix+=a.pop();
      }
      a.pop();
    }
  }
  while(!a.is_empty())
  {
    postfix+=a.pop();
  }
  return postfix;
}

//converting from infix to prefix
std::string infix_to_prefix(std::string text)
{
  return reverse(infix_to_postfix(reverse(text)));
}

//evaluation of postfix expression
void evaluate_postfix(std::string text)
{
  Stack<std::string> a;
  int num1,num2,result,temp=0;
  for(int i=0;text[i]!='\0';i++)
  {
    if(text[i]==',')
    {
      continue;
    }
    else if(isdigit(text[i]))
    {

      if(text[i+1]!=',')
      {
      while(text[i]!=',')
      {
        temp=temp*10+(text[i]-'0');
        i++;
      }
      a.push(std::to_string(temp));
    }
    else
    {
      a.push(std::string(1,text[i]));
    }
    }
    else
    {
      num1=std::stoi(a.pop());
      num2=std::stoi(a.pop());
      switch(text[i])
      {
        case '+':
            result=num2+num1;
            break;
        case '-':
            result=num2-num1;
            break;
        case '/':
            result=num2/num1;
            break;
        case '*':
            result=num2*num1;
            break;
        case '^':
            result=pow(num2,num1);
            break;
      }
        a.push(std::to_string(result));
    }
    a.display();
  }
  std::cout<<"Ans:"<<a.pop();
}

//Checking for balanced paranthesis
bool balanced_parenthesis(std::string expr)
{
  Stack<char> a;
  for(int i=0;expr[i]!='\0';i++)
  {
    if(expr[i]=='(')
    {
      a.push(expr[i]);
    }
    else if(expr[i]==')')
    {
      if(a.is_empty())
      {
        return false;
      }
      else
      {
        a.pop();
      }
    }
  }
  return a.is_empty()?true:false;
}
//push pop operation
// int main()
// {
//   Stack<int> s;
//   try
//   {
//     s.display();
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     s.display();
//     s.push(4);
//     s.display();
//     std::cout<<"Peek value:"<<s.peek()<<std::endl;
//     s.pop();
//     s.display();
//     s.pop();
//     s.pop();
//     s.display();
//     s.pop();
//     s.display();
//     s.pop();
//     s.push(1);
//   }
//   catch(STACK_UNDERFLOW s)
//   {
//     std::cout<<"Error:"<<s.get_exception()<<std::endl;
//   }
//   catch(STACK_OVERFLOW s)
//   {
//     std::cout<<"Error:"<<s.get_exception()<<std::endl;
//   }
//   return 0;
// }

//infix to postfix
// int main()
// {
//   std::string a;
// std::cout<<"Enter infix string >>";
// std::cin>>a;
// std::string pf;
// pf=infix_to_postfix(a);
// std::cout<<pf;
// return 0;
// }

// evaluation of postfix string
int main()
{
  std::string text;
  text="6,2,3,+,-,3,8,2,/,+,*,2,^,3,+";
  evaluate_postfix(text);
return 0;
}

//Infix to prefix
// int main()
// {
//   std::string a;
// std::cout<<"Enter infix string >>";
// std::cin>>a;
// std::string pf;
// pf=infix_to_prefix(a);
// std::cout<<pf;
// return 0;
// }

//Balanced parenthesis
// int main()
// {
//   std::string text;
//   std::cout<<"Enter string to check>>";
//     std::cin>>text;
//
//   if(balanced_parenthesis(text))
// {
// 	std::cout<<"expression is correct"<<std::endl;
// }
// else
// {
// 	std::cout<<"expression is not correct"<<std::endl;
// }
// return 0;
// }

#include<iostream>
//fibonacci using non tail recursion
int fib(int n)
{
  if(n==1 || n==0)
  {
    return n;
  }
  else
  {
    return fib(n-1)+fib(n-2);
  }
}

//fibonacci using tail recursion
int tail_fib(int n,int a=0,int b=1)
{
  if(n==0)
  {
    return a;
  }
  else if(n==1)
  {
    return b;
  }
  else
  {
    return tail_fib(n-1,b,a+b);
  }
}
int main()
{
  int n;
  std::cout<<"Enter n>>";
  std::cin>>n;
  std::cout<<"fibonacci("<<n<<"):"<<fib(n)<<std::endl;
  std::cout<<"Using tail recursion fibonacci("<<n<<"):"<<tail_fib(n);
  return 0;
}

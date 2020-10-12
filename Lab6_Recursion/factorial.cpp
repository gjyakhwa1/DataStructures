#include<iostream>
//factorial using nontail recursion
int fact(int n)
{
  if(n==0 || n==1)
  {
    return 1;
  }
  else
  {
    return n*fact(n-1);
  }
}

//factorial using tail recursion
int tail_fact(int n,int res=1)
{
  if(n==1 || n==0)
  {
    return res;
  }
  else
  {
    return tail_fact(n-1,res*n);
  }
}

int main()
{
  int num;
  std::cout<<"Enter number>>";
  std::cin>>num;
  std::cout<<"factorial("<<num<<"):"<<fact(num)<<std::endl;
  std::cout<<"Using tail recursion factorial("<<num<<"):"<<tail_fact(num);
  return 0;
}

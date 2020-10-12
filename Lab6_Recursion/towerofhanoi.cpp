#include<iostream>
//function to move rings from one peg to another
//A=source B=auxiliary C=destination
void move(int n,char A,char B,char C)
{
  if(n>0)
  {
    move(n-1,A,C,B);
    std::cout<<A<<" to "<<C<<std::endl;
    move(n-1,B,A,C);
  }
}
int main()
{
  move(4,'A','B','C');
  return 0;
}

#include<iostream>
void display(int *ptr,int n)
{
  std::cout<<"[";
  for(int i=0;i<n;i++)
  {
    if(i==n-1)
    {
        std::cout<<ptr[i];
    }
    else
    {
    std::cout<<ptr[i]<<",";
    }
  }
  std::cout<<"]"<<std::endl;
}
void swap(int &a,int &b)
{
  int temp;
  temp=a;
  a=b;
  b=temp;
}
void bubble_sort(int *ptr,int n)
{
for(int i=0;i<n-1;i++)
{
    std::cout<<"\nPass"<<i+1<<std::endl;
  for(int j=0;j<n-1-i;j++)
  {
    if(ptr[j]>ptr[j+1])
    {
      swap(ptr[j+1],ptr[j]);
    }
    display(ptr,n);
  }
}
}
int main()
{
  int n;
  std::cout<<"Enter total items in the list>>";
  std::cin>>n;
  int *ptr=new int[n];
  //getting elements of the list
  for(int i=0;i<n;i++)
  {
    std::cout<<"Enter element "<<i+1<<">>";
    std::cin>>ptr[i];
  }
  std::cout<<"Items in the list..."<<std::endl;
  display(ptr,n);
  bubble_sort(ptr,n);
  std::cout<<"\nDisplaying sorted list using bubble sort..."<<std::endl;
  display(ptr,n);
  delete ptr;
  return 0;
}

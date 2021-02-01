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
void insertion_sort(int *ptr,int n)
{
  int temp,j;
  for(int i=1;i<n;i++)
  {
    std::cout<<"\nPass"<<i<<std::endl;
    temp=ptr[i];
    j=i-1;
    std::cout<<"Temp:"<<temp<<std::endl;
    while(ptr[j]>temp && j>=0)
    {
      ptr[j+1]=ptr[j];
      j--;
      display(ptr,n);
    }
    ptr[j+1]=temp;
    display(ptr,n);
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
  insertion_sort(ptr,n);
  std::cout<<"\nDisplaying sorted list using insertion sort..."<<std::endl;
  display(ptr,n);
  delete ptr;
  return 0;

}

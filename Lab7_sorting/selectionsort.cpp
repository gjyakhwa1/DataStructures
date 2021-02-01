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
void selection_sort(int *ptr,int n)
{
  int min;
  for(int i=0;i<n-1;i++)
  {
    min=i;
    for(int j=i+1;j<n;j++)
    {
      if(ptr[j]<ptr[min])
      {
        min=j;
      }
    }
    if(min!=i)
    {
      swap(ptr[i],ptr[min]);
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
  selection_sort(ptr,n);
  std::cout<<"Displaying sorted list using selection sort..."<<std::endl;
  display(ptr,n);
  delete ptr;
  return 0;

}

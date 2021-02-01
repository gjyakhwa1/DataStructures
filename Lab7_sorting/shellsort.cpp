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
void shell_sort(int *ptr,int n)
{
  for(int i=n;i>=1;i=i/2)
  {
    for(int j=i;j<n;j++)
    {
      for(int k=j-i;k>=0;k=k-i)
      {
        if(ptr[k+i]>ptr[k])
        {
          break;
        }
        else
        {
          swap(ptr[k+i],ptr[k]);
        }
      }
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
  shell_sort(ptr,n);
  std::cout<<"Displaying sorted list using shell sort..."<<std::endl;
  display(ptr,n);
  delete ptr;
  return 0;

}

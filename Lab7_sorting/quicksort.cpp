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
int partition(int *ptr,int low,int up)
{
  int pivot{ptr[low]};
  int head{low};
  int tail{up};
  while(head<tail)
  {
    while(ptr[head]<=pivot)
    {
      head++;
    }
    while(ptr[tail]>pivot)
    {
      tail--;
    }
    if(head<tail)
    {
      swap(ptr[head],ptr[tail]);
    }
  }
  swap(ptr[low],ptr[tail]);
  return tail;
}
void quick_sort(int *ptr,int lower_index,int upper_index)
{
  int position;
  if(lower_index<upper_index)
  {
    position=partition(ptr,lower_index,upper_index);
    quick_sort(ptr,lower_index,position-1);
    quick_sort(ptr,position+1,upper_index);
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
  quick_sort(ptr,0,n);
  std::cout<<"Displaying sorted list using quick sort..."<<std::endl;
  display(ptr,n);
  delete ptr;
  return 0;

}

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

//merging sub array
void merge(int *ptr,int lower_bound,int mid,int upper_bound)
{
  int i{lower_bound},j{mid+1},k{lower_bound};
  int a[upper_bound];
  while(i<=mid && j<upper_bound)
  {
    if(ptr[i]<=ptr[j])
    {
      a[k]=ptr[i];
      i++;
    }
    else
    {
      a[k]=ptr[j];
      j++;
    }
    k++;
  }
  if(i>mid)
  {
    while(j<upper_bound)
    {
      a[k]=ptr[j];
      j++;
      k++;
    }
  }
  else
  {
    while(i<=mid)
    {
      a[k]=ptr[i];
      i++;
      k++;
    }
  }
  for(int l=lower_bound;l<upper_bound;l++)
  {
    ptr[l]=a[l];
  }
}

//dividing array to subarray
void merge_sort(int *ptr,int lower_bound,int upper_bound)
{
  int mid;
  if(lower_bound<upper_bound)
  {
    mid=(lower_bound+upper_bound)/2;
    merge_sort(ptr,lower_bound,mid);
    merge_sort(ptr,mid+1,upper_bound);
    merge(ptr,lower_bound,mid,upper_bound);
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
  merge_sort(ptr,0,n);
  std::cout<<"Displaying sorted list using merge sort..."<<std::endl;
  display(ptr,n);
  delete ptr;
  return 0;

}

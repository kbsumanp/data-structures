//linear search

#include<iostream>
using namespace std;

int l_search(int arr[], int n, int x) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
         return i; 
    return -1; 
} 


int main()
{
  int a[]={1,2,3,4,5,6,7,8,9};
  int x;
  cout<<"\nEnter the value to be searched for:";
  cin>>x;
  int f=l_search(a,9,x);
  if(f!=-1)
   cout<<"\nFound at position: "<<f+1;
  else
   cout<<"\nElement not in the list";
 }

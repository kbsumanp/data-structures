#include<iostream>
using namespace std;

int count=0,pass=1;
void Selection_sort(int A[],int n)
{
  for(int i=0;i<n-1;i++)          //loop till n-2
   {
     int min=i;                   //first element as minimum
     for(int j=i+1;j<n;j++)          //2nd element 
      {
		count++;
        if(A[j]<A[min])
          min=j;
      }
     int temp=A[i];                    //swapping a[min] a[i]
     A[i]=A[min];
     A[min]=temp;
     cout<<"\nPass "<<pass<< ": " ;
     for(int k=0;k<n;k++)
      {
		  cout<<A[k]<<" ";
	  }
	 pass++;
	 cout<<"\n";
   }
}

int main()
{
int a[100],size;
cout<<"enter the size of array:";
cin>>size;
cout<<"enter the elements of array:";
for(int i=0;i<size;i++)
  {
	  cin>>a[i];
  }
Selection_sort(a,size);
cout<<"\nNo of comparisons="<<count;
cout<<"\nSorted array is: ";
for(int i=0;i<size;i++)
  {
	  cout<<a[i]<<" ";
  }
}

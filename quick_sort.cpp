#include<iostream>
using namespace std;

int partition(int A[],int start,int end)
{
	int pivot=A[end];
	int p_index=start;
	for(int i=start;i<end;i++)
	 {
		 if(A[i]<=pivot)
		  {
			  //swapping(A[i],A[p_index]);
			  int temp=A[i];
			  A[i]=A[p_index];
			  A[p_index]=temp;
			  p_index++;
		  }
	 }
int temp2=A[p_index];
A[p_index]=A[end];
A[end]=temp2;
return p_index;
}

void quick_sort(int A[],int start,int end)
{
	if(start<end)
	{
	 int p_index=partition(A,start,end);
	 quick_sort(A,start,p_index-1);
	 quick_sort(A,p_index+1,end);
	}
}


int main()
{
	
int a[10],size;
cout<<"enter the size of array:";
cin>>size;
cout<<"enter the elements of array:";
for(int i=0;i<size;i++)
  {
	  cin>>a[i];
  }
//int a[9]={4,2,9,5,8,1,15,23,11};
quick_sort(a,0,size);
cout<<"\nSorted array is: ";
for(int i=0;i<size;i++)
  {
	  cout<<a[i]<<" ";
  }
}

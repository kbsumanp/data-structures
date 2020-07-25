//using recursion


#include<iostream>
using namespace std;

//for sorting
void merge(int A[],int L[],int leftCount,int R[],int rightCount) 
{
	int i,j,k;
	// i - left aubarray (L)
	// j - right sub-raay (R)
	// k - merged subarray (A)
	i = 0; j = 0; k =0;

	while(i<leftCount && j<rightCount) 
	{
		if(L[i]< R[j]) 
		    A[k++] = L[i++];
		else 
		   A[k++] = R[j++];
	}
	
	while(i<leftCount)
	    A[k++]= L[i++];
	while(j<rightCount) 
	    A[k++]= R[j++];
}


void merge_sort(int A[],int n)
{
	if(n<2)
	{
		return;
    }
    
  int mid=n/2;
  int L[mid];
  int R[n-mid];
  
  for(int i=0;i<mid;i++)
   {
	   L[i]=A[i];
   }
  for(int i=mid;i<n;i++)
   {
	   R[i-mid]=A[i];
   }
merge_sort(L,mid);
merge_sort(R,n-mid);
merge(A,L,mid,R,n-mid);          //merging left and right sub-arrays
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
merge_sort(a,size);
cout<<"\nSorted array is: ";
for(int i=0;i<size;i++)
  {
	  cout<<a[i]<<" ";
  }
}

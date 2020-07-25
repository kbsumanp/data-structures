#include<iostream>
using namespace std;

int main()
{
int count=0;
int arr[100],size,temp=0,pass=1;
cout<<"enter the size of array:";
cin>>size;
cout<<"enter the elements of array:";
for(int i=0;i<size;i++)
  {
	  cin>>arr[i];
   }


for(int i=1;i<size;i++)
 {
	  for(int j=0;j<size-i;j++)
	    {
			count++;
			if(arr[j]>arr[j+1])             //increasing order
			 {
				 temp=arr[j];
				 arr[j]=arr[j+1];
				 arr[j+1]=temp;
			}
	     }
	  cout<<"the intermediate array for pass "<<pass<<" is:";
	  for(int k=0;k<size;k++)
	    {
			cout<<arr[k]<<"\t";
	    }
	  pass++;
	  cout<<"\n";
 }

 cout<<"total no of comparisons="<<count<<endl;
 cout<<"final sorted array:";
 for(int j=0;j<size;j++)
   cout<<arr[j]<<"\t";
}

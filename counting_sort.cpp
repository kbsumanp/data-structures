#include <iostream>
using namespace std;

void countingSort(int arr[],int n,int RANGE){
    int count[RANGE]={0};
    int i;
    int out[n];
    
    
    for(i=0;i<n;i++)         //count
       ++count[arr[i]];
  /*  cout<<"\nCount of each element :";
    for(int c=0;c<n;c++)
     {
		 cout<<count[arr[c]]<<" ";
	 }*/
    
    for(i=1;i<RANGE;i++)        //sumcount
        count[i]+=count[i-1];
  /*  cout<<"\nSum_Count of each element :";
    for(int c=0;c<n;c++)
     {
		 cout<<count[arr[c]]<<" ";
	 }*/
 
    
    for(i=n-1;i>=0;i--)
    {
        out[count[arr[i]]-1]=arr[i];
        --count[arr[i]];
    }
  /*  cout<<"\nSum_Count of each element while presenting output :";
    for(int c=0;c<n;c++)
     {
		 cout<<count[arr[c]]<<" ";
	 }*/
    
    for(i=0;i<n;i++)
       arr[i]=out[i];
    
    
    
}
void print(int arr[],int n){
    //  cout<<"\nArray : ";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<' ';
    cout<<endl;
}

int main() {
	// your code goes here
	int arr[]={1, 4, 1, 2, 7, 5, 2};
	int n=sizeof(arr)/sizeof(arr[0]);
	int RANGE=9;
	
	print(arr,n);
	
	countingSort(arr,n,RANGE);
	
	cout<<"\nSorted array:\n";
    print(arr,n);
	
	return 0;
}

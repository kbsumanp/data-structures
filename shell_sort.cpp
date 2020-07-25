//generalisation of insertion sort
//we compare the values at 'gap' distant apart where gap=floor[n/2] then gap=floor[gap/2]

#include<iostream>
 
using namespace std;
 
// A function implementing Shell sort.
void ShellSort(int a[], int n)
{
	int gap, j, k, temp;
	
	// Gap 'i(gap)' between index of the element to be compared, initially n/2.
	
	for(gap = n/2; gap> 0; gap = gap/2)
	{
		for(j=gap;j<n;j++)
		{
			for(k=j-gap;k>=0;k=k-gap)
			{
				// If value at higher index is greater, then break the loop.
				if(a[k+gap]>=a[k])
				    break;
				// Swap the values otherwise.
				else
				{
					temp = a[k];
					a[k] = a[k+gap];
					a[k+gap] = temp;
				}
			}
		}
	}
}
int main()
{	
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	ShellSort(arr, n);
 
	// Printing the sorted data.
	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
		cout<<arr[i]<<" ";
 
	return 0;
}

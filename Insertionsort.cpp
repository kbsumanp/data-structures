//comparing adjacent values

#include<iostream>
using namespace std;

int main()
{

int count=0;
int a[100],size,pass=1;
cout<<"enter the size of array:";
cin>>size;
cout<<"enter the elements of array:";
for(int i=0;i<size;i++)
  {
	  cin>>a[i];
  }

for (int i = 1; i <size ; i++)               //loop starts from 1
  {
	    count++;
		int temp=a[i];
		int j=i;
		while(j>0 && temp<a[j-1])                    //comparing with previous element
		{
			a[j]=a[j-1];
			j=j-1;

		}
		
	  a[j]=temp;
	  cout<<"the intermediate array for pass "<<pass<<" is: ";
	  for(int k=0;k<size;k++)
	    {
			cout<<a[k]<<"\t";
	    }
	  pass++;
	  cout<<"\n";
	}
 cout<<"total no of comparisons:"<<count<<endl;
 cout<<"final sorted array:";
 for(int j=0;j<size;j++)
   cout<<a[j]<<"\t";

}

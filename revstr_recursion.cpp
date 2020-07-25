//-------------------------reverse string using recursion--------------------------------------


#include<iostream>
using namespace std;

void swap(char a[],char b[])
{
	char temp;
  for(int i=0;a[i]!='\0';i++)
  {
	temp=a[i];
	a[i]=b[i];
	b[i]=temp;
  }
}

void rev(char A[], int i, int size)
{
	if(i<=(size/2))
	{
		swap(A[i],A[size-i]);
		rev(A,i+1,size);
	}
}

int main()
{
	int size=0;
	char A[100];
	cout<<"\nEnter any string: ";
	cin.getline(A,100);
	while(A[size]!='\0'){
		size++;
	}
	cout<<"\nReverse string: ";
	rev(A,0,size-1);
	cout<<A;
	return 0;
}

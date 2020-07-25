//-----------------calculating power using recursion----------------------------

#include<iostream>
using namespace std;
int calc(int b, int r)
{
	if(r==1)
		return b;
	else
		return b*calc(b,r-1);
}
int main()
{
	int b,r;
	int tvalue;
	cout<<"\nEnter any number to calculate it's power: ";
	cin>>b;
	cout<<"\nEnter power value: ";
	cin>>r;
	tvalue=calc(b,r);
	cout<<b<<"^"<<r<<" = "<<tvalue;
	return 0;
}

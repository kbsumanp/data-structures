
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
	int i,count=0;
	char str[50];
	char ch;
	cout<<"enter the string=";
	cin.get(str,50);
	
	int l=strlen(str);
	cout<<"enter the char whose occurence u need to search=";
	cin>>ch;
	
	for(i=0;i<=l;i++)
	{
		
		if(str[i]==ch)
		{
			count++;
		}
	}
	cout<<"no of times your required char appeared is="<<count<<endl;
	
}

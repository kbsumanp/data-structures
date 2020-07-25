
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
	char ch1,ch2,str[50];
	int i;
	cout<<"enter the string=";
	cin.get(str,50);
	cout<<"enter the character u need to change=";
	cin>>ch1;
	cout<<"enter the new character=";
	cin>>ch2;
	
	for(i=0;str[i]!='\0';i++)
	{
		
		if(str[i]==ch1)
		{
			str[i]=ch2;
			
		}
		
		cout<<str[i];
	}
	
	
	
}

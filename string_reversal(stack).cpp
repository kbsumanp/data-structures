#include<iostream>
#include<string.h>
//#include<stack>
using namespace std;

#define f 10

class stack
{
 private:
 
   char a[f];
   int c;     //top
 
 public:
    stack()
    {
		c=-1;
    }
   
   void push(char x);
   int pop();
   bool isempty();
   int top();
 //  void reverse(char c[],int v);
};


void stack::push(char x)
   {
    if(c==(f-1))
     {
       cout<<"\nStack overflow";
       return;
     }
    else
    {
    // int b;
    // b=a[c]+1;
     //b=x;
     c=c+1;
     a[c]=x;
     //c++;
     }
   }
   int stack::pop()
   {
      if(isempty())
       {
       cout<<"\nStack underflow";
       return 0;
       }
    else
    {
     char y;   
     y=a[c];
     c--;
   return y;
}  }
   
   int stack::top()
   {
      return c;
   }
   bool stack::isempty()
   {
     if(c==-1)
      return true;
     else
      return 0;
   }


stack S;

void reverse(char c[],int n)    //char *c
{
	//stack<char> S;
	for(int i=0;i<n;i++)
	 {
		  S.push(c[i]);
	 }
	
	for(int i=0;i<n;i++)
	 {
		 c[i]=S.top();
		 S.pop();
		//cout<<c[i];
	 }

}


int main()
{
	char s[50];              //array of characters not string
	cout<<"\nEnter a string: ";
	cin.getline(s,50);
	int l=strlen(s);
	reverse(s,l);
	cout<<"\nReverse string is: ";
	for(int i=0;i<l;i++)
	{
	cout<<s[i];
    }

}

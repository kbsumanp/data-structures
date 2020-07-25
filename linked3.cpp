#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int val;
	node *next;
};

int main()
{
	node *head=new node;
	head->val=12;
	head->next=NULL;
	node *t=head;
char found=false;
char ch='y';
while(ch=='y' || ch=='Y')
 {
	 node *p=new node;
	 cout<<"enter the value to be added at the ned of the list:";
     cin>>p->val; 
     cout<<"do u want to add more elements?";
	 cin>>ch;
	  
  }
  int x;
  
  cout<<"enter the node after which u want to add x:";
  cin>>x;
while((t!=NULL) && (!found))
{
	if(t->val==x)
	   found=true;
	else
	   t=t->next;
}
if(!found)
  cout<<x<<" does not occur in the list";
else
 {
	 node *q=head;
  q=t->next;
  node *r=head;
  r->val=14;
  r->next=NULL;
  t->next=r;
  r->next=q;
 }
node *d;
d=head;
while(d->next!=NULL)
{
	if(d->next==NULL)
	  cout<<d->val<<"->NULL";
	else
	 cout<<d->val<<"->";
	d=d->next;
}

}
  

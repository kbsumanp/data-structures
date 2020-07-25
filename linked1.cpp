
//-------------------ADD AT TAIL-----------------//


#include<iostream>
using namespace std;
struct node
{
	int val;
	node *next;
};

int main()
{
node *head;
head=new node;
head->val=12;
head->next=NULL;
node *t;
t=head;
char ch='y';
while(ch=='y' || ch=='Y')
  {
	  
	  node *p=new node;
	  cout<<"enter the value to be added at the ned of the list:";
	  cin>>p->val;
	  p->next=NULL;
	  t->next=p;
	  t=p;
	  cout<<"do u want to add more elements?";
	  cin>>ch;
	  
  }
  node *q;
  q=head;
  while(q!=NULL)
 {
	 
	 if(q->next==NULL)
	  cout<<q->val<<"->NULL";
	else
	  cout<<q->val<<"->";
	q=q->next;
 }

}

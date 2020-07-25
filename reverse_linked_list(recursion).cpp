//previous yesr question
//a recursive function to display a single linked list of integers in reverse order

#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

node *head;

void reverse(node *p)
{
  if(p==NULL)
   {
     head=p;
     return;
   }
  reverse(p->next);
  cout<<p->data<<" ";
}

//insertion at head
node* insert(node *head,int x)
{
	node *temp=new node;
	temp->data=x;
	temp->next=NULL;
	if(head!=NULL)
	  temp->next=head;
	head=temp;
return head;
}

void print(node* head)
{
	cout<<"\nThe list is: ";
	while(head!=NULL)
	 {
		 cout<<head->data<<" ";
		 head=head->next;
	 }
cout<<"\n";
}

int main()
{
	node* head=NULL;
	head=insert(head,2);
	head=insert(head,4);
	head=insert(head,6);
	head=insert(head,8);
	print(head);
	cout<<"\nThe list in reverse order is: ";
	reverse(head);
}

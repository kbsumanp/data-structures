//previous yesr question
//a recursive function to display a single linked list of integers in reverse order

#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* reverse(node* head)
{
	node *next,*curr,*prev;
	curr=head;
	prev=NULL;
	
	while(curr!=NULL)
	 {
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
head=prev;
return head;
}

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
	head=reverse(head);
	print(head);
}

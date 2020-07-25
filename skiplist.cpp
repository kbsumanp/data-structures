//--------------------------------------SKIP LIST-----------------------------------------

#include<iostream>
using namespace std;

struct node
{
 int val;
 node *next;
};

node *head=NULL;

//INSERTING ELEMENTS OF LINKED LIST(sorted)

void insert(int x)
{
 node *temp=head;
 node *p=new node;
 p->val=x;
 temp->next=p;
 temp=p;
}



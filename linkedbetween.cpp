#include<iostream>
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
node *t,*i;
t=head;
i=head;
    
char ch='y';
while(ch=='y' || ch=='Y')
{
node *p=new node;
cout<<"enter nodes to be added:";
cin>>p->val;
p->next=NULL;
t->next=p;
t=p;
cout<<"do u want to enter more elemennts:";
cin>>ch;
}
    
node *q;
q=head;
cout<<"\n the list is \n ";
while(q!=NULL)
{
cout<<q->val<<"->";
q=q->next;
}


char found=false;
int x,y;
cout<<"\nnode after which element to add:";
cin>>x;
cout<<"\nnode before which element to add:";
cin>>y;

    
while((i!=NULL)&&(!found))
{
if((i->val==x)&&((i->next)->val==y))
 { found=true;
   
   node *s=new node;
   s->val=15;
   s->next=NULL;
   s->next=i->next;
   i->next=s;
    
   
  }
else
  i=i->next;
   
}

if(!found)
{
cout<<"\n nodes does not exist in the list\n";
}

node *u;
u=head;
cout<<"\n the new list is \n";
while(u!=NULL)
{
    //-------- display---------    
     
   cout<<u->val<<"->";
   u=u->next;
}
}
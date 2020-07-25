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
node *t,*i,*j;
t=head;
i=head;
j=head;
    
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
int x;
cout<<"\n node before which element to add:";
cin>>x;

if(i->val!=x)  
  i=i->next;
while((i!=NULL)&&(!found))
{
if(i->val==x)
 { found=true;
   
   node *s=new node;
   s->val=11;
   s->next=NULL;
   j->next=s;
   s->next=i;
    
   
  }
else
 {  i=i->next;
    j=j->next;
 }
   
}

if(!found)
{
cout<<"\n node does not exist in the list\n";
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
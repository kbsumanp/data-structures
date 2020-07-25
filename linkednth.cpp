#include<iostream>
using namespace std;
struct node
{
int val;
node *next;
};

node *head=NULL;

void insert() 
{
    node *t=new node;
    int n;
    cout<<"\nenter the node to be added:";
    cin>>t->val;
    t->next=NULL;
    cout<<"\nenter node position:";
    cin>>n;
    if(n==1)
    {
    t->next=head;
    head=t;
    return;
   }
node *t1=head;
for(int i=1;i<n-1;i++)
  {
   t1=t1->next;     
  }
t->next=t1->next; 
t1->next=t;        
}

void print()
{ 
node *q;
q=head;
cout<<"\n the list is \n ";
while(q!=NULL)
{
cout<<q->val<<"->";
q=q->next;
}
cout<<"NULL";
}

int main()
{

char ch;
do
{ 
insert();
print();
cout<<"\ndo u want to enter more elements:";
cin>>ch;
}while(ch!='n');
    
}


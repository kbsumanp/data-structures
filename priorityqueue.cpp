//linked representation of priority queue(singly)


#include<iostream>
using namespace std;

struct node
{
int val;
int priority;
node *next;
};

class pqueue
{
node *front;

public:
  pqueue()
   {
   front=NULL;
   }
void insert(int x,int p);
void del();
void display();
};


//lowest no has highest priority
void pqueue::insert(int x,int p)
{
node *temp,*q;
temp=new node;
temp->val=x;
temp->priority=p;
if(front==NULL || p<front->priority)
  {
   temp->next=front;                      //insertion at head
   front=temp;
  }
else
  {
    q=front;                               //traversing
    while(q->next!=NULL && q->next->priority<=p)
          q=q->next;
    temp->next=q->next;
    q->next=temp;
  }
}


void pqueue::del()
{
if(front==NULL)
  cout<<"\nQueue underflow";
else
  {
   node* temp=front;
   cout<<"\nDeleted item is:"<<temp->val;
   front=front->next;                //move front to the next element 
   delete(temp);                    //free the front element
  }
}


void pqueue::display()
{
node *p=front;
if(front==NULL)
  {
   cout<<"\nQueue empty";
  }
else 
 {
 cout<<"Queue is:";
 while(p!=NULL)
    {
      cout<<p->val<<" ";
      p=p->next;
    }
 }
}


int main()
{ 
pqueue pq;
int choice;   
cout<<"\n1.Add";
cout<<"\n2.Delete";
cout<<"\n3.Display";
do{ 
cout<<"\nEnter ur choice:";
cin>>choice;
switch(choice)
  {
   case 1: int p;
           cout<<"\nenter element:";
           cin>>p;
           int p1;
           cout<<"\nenter its priority:";
           cin>>p1;
           pq.insert(p,p1);break;
   case 2: 
           pq.del();break;
   case 3: pq.display();break;
   default: cout<<"\nwrong choice";
  }
}while(choice!=4);
}





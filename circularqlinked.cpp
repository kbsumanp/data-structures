//linked implementation of circular queue (singly linked list)
//previous year question

#include<iostream>
using namespace std;

struct node
{
int val;
node *next;
};

class queue
{
	public:
node *front,*rear;
 queue()
 {
	 front=NULL;
	 rear=NULL;
  }
};

void add(queue *p,int data)
{
 node *temp=new node;
 temp->val=data;
 if(p->front==NULL)
  {
   p->front=temp;
  }
 else
   p->rear->next=temp;     //Link setup 
p->rear=temp;          //now adding ekement 
}


int deleteq(queue *t)
{
  if(t->front==NULL)
    cout<<"\nqueue is empty";
  int value;
  if(t->front==t->rear)
    {
     value=t->front->val;
     delete(t->front);
     t->front=NULL;
     t->rear=NULL;
    }
  else
    {
    node *temp=t->front;
    value=temp->val;
    t->front=t->front->next;
    t->rear->next=t->front;
    delete(temp);
    }
return value;
}

void print(queue *s)
{ 
cout<<"\ncircular queue is:";
node *temp=s->front;
while(temp!=s->rear)
  {
    cout<<temp->val<<"->";
    temp=temp->next;
  }
cout<<temp->val;
}


int main()
{
int choice;     
queue *q=new queue;
//q->front=q->rear=NULL; 
cout<<"\n1.Add";
cout<<"\n2.Delete";
cout<<"\n3.Display";
do{ 
cout<<"\nEnter ur choice:";
cin>>choice;
switch(choice)
  {
   case 1: int d;
           cout<<"\nenter element to be added:";
           cin>>d;
           add(q,d);break;
   case 2: 
           deleteq(q);break;
   case 3: 
           print(q);break;
   default: cout<<"\nwrong choice";
  }
}while(choice!=4);
}


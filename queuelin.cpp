// linked implementation of queue 

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
int n;
node *next;
};

class queue 
{
private:
  node *front,*rear;
public:
  queue()
   {
    front=NULL;
    rear=NULL;
   }
  void addnode();
  void deletenode();
  void display();
    
};


queue t;

void queue::addnode()
{
node *p=new node;
cout<<"\nEnter a value:";
cin>>p->n;
if(front==NULL && rear==NULL)
 {
   p->next=rear;
   rear=p;
   front=p;
 }
else
 {
  p->next=rear->next;
  rear->next=p;
  rear=p;
 }
}


void queue::deletenode()
{
node *q=front;
if(front==rear)
  {
   front=NULL;
   rear=NULL;
  }
else
  {
    front=q->next;
    delete q;
  }
}


void queue::display()
{
node *q=front;
cout<<"\nQueue is:";
while(q!=NULL)
  {
    cout<<q->n<<"->";
    q=q->next;
  }
cout<<"NULL";
}


int main()
{
int choice;   
cout<<"\n1.Add";
cout<<"\n2.Deletenode";
cout<<"\n3.Display";
do{ 
cout<<"\nEnter ur choice:";
cin>>choice;
switch(choice)
  {
   case 1: 
           t.addnode();break;
   case 2: 
           t.deletenode();break;
   case 3: 
           t.display();break;
   default: cout<<"\nwrong choice";
  }
}while(choice!=4);
}

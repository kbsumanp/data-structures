// linked implementation of stack 

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
int n;
node *next;
};

class stack 
{
private:
  node *head;            //top
public:
  stack()
   {
    head=NULL;
   }
  void push();
  void pop();
  void display();
 // void print(node*);
  node* reverse();
    
};


stack s;
void stack::push()
{
  node *p=new node;
  if(!p)
   {
   cout<<"Memory exhausted";
   exit(1);
   }
  else
   {
    cout<<"Enter a value:";
    cin>>p->n;
    p->next=head;   //adding at head 
    head=p;
   }
}

void stack::pop()
{
if(head)   
 {
    node *p=head;
    head=p->next;
    cout<<"\ndeleted element is: "<<p->n;
    delete(p);
  }
else
  cout<<"\nstack underflow";
}

void stack::display()
{
node *q=head;
cout<<"\nstack is:";
while(q!=NULL)
  {
    cout<<q->n<<"->";
    q=q->next;
  }
cout<<"NULL";
}

/*
void stack::print(node *p)
{
	if(p==NULL)
	 return;
	cout<<p->n<<" ";
	print(p->next);
}
*/

node* stack::reverse()
{
	
	node *curr,*prev,*next;
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


int main()
{
int choice;
 
cout<<"\n1.Push";
cout<<"\n2.Pop";
cout<<"\n3.Display";
cout<<"\n4.Reverse";
//cout<<"\n5.Print in reverse order";
do{ 
cout<<"\nEnter ur choice:";
cin>>choice;
switch(choice)
  {
   case 1: 
           s.push();break;
   case 2: 
           s.pop();break;
   case 3: 
           s.display();break;
   case 4: s.reverse();break;
  // case 5: s.print(head);break;
   default: cout<<"\nwrong choice";
  }
}while(choice!=5);
}

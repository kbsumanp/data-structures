//implemented using doubly linked list


#include<iostream>
using namespace std;

struct node
{
int val;
node *next;
node *prev;
};

class deque
{
node *front;
node *rear;
    
public:
  deque()
   {
      front=NULL;
      rear=NULL;
   }
void insert_front(int x);
void insert_rear(int x);
int delete_front();
int delete_rear();
bool isempty();
void display();
};


bool deque::isempty()
{
	if(front==NULL)
	  return true;
	else
	  return false;
}


void deque::insert_front(int x)
{
	node *temp=new node;
	temp->val=x;
	temp->next=NULL;
	temp->prev=NULL;
	
	if(isempty())
	 {
		 front=rear=temp;
	 }
	else
	 {
		 temp->next=front;
		 front->prev=temp;
		 front=temp;
	 }
}


void deque::insert_rear(int x)
{
	node *temp=new node;
	temp->val=x;
	temp->next=NULL;
	temp->prev=NULL;
	
	if(isempty())
	 {
		 front=rear=temp;
	 }
	else
	 {
		 rear->next=temp;
		 temp->prev=rear;
		 rear=temp;
	 }
}

int deque::delete_front()
{
	if(isempty())
	{
		cout<<"Deletion not possible";
		return 0;
	}
	
	int data=front->val;
	node *temp=front;
	front=front->next;
	if(front==NULL)
	 {
	   rear=NULL;
	 }
	else
	 {
	   front->prev=NULL;
	 }
	delete temp;
return data;
}


int deque::delete_rear()
{
	if(isempty())
	 {
		 cout<<"Deletion not possible...empty!!!";
		 return 0;
	 }
	
	int data=rear->val;
	node *temp=rear;
    rear=rear->prev;
    if(rear==NULL)
     {
       front=NULL;
	 }
	else
	 {
		 rear->next=NULL;
	 }
	delete temp;
return data;
} 


void deque::display()
{
   node *q=front;
   cout<<"\n the list is \n ";
   while(q!=NULL)
    {
        cout<<q->val<<"->";
        q=q->next;
    }
}


int main()
{
deque dq;
int choice;   
cout<<"\n1.Add at front";
cout<<"\n2.Add at rear";
cout<<"\n3.Delete from front";
cout<<"\n4.Delete from rear";
cout<<"\n5.Display";
do{ 
cout<<"\nEnter ur choice:";
cin>>choice;
switch(choice)
  {
   case 1: int p;
           cout<<"\nenter element:";
           cin>>p;
           dq.insert_front(p);break;
   case 2: int p1;
           cout<<"\nenter element:";
           cin>>p1;
           dq.insert_rear(p1);break;
   case 3: dq.delete_front();break;
   case 4: dq.delete_rear();break;
   case 5: dq.display();break;
   default: cout<<"\nwrong choice";
  }
}while(choice!=6);
}

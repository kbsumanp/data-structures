
//----------------------------------------DOUBLY ENDED QUEUE-----------------------------------------------------------------
//Properties - 1. add at rear and front both(normally adding at rear)
//             2. delete at rear and front both(normally deleting from front)

#include<iostream>
using namespace std;
#define max 5


class deque
{
int arr[max];
int front;
int rear;
    
public:
  deque()
   {
      front=-1;
      rear=-1;
   }
void insert_front(int x);
void insert_rear(int x);
void delete_front();
void delete_rear();
void display();
};



void deque::insert_front(int x)
{
if(front==-1)
  {
  front=0;              
  rear=0;
  arr[rear]=x;        //moving forward and adding(at first position only)
  }
else if(front!=0)
  {
    front=front-1;        //moving backward ... the concept of deque front and rear can go backwards too
    arr[front]=x;       //when front is in between ..decrement front upto 0(after this no addition we cant take pointer to max-1)
  }
  else
     cout<<"\nInsertion not possible!!!!!";
}


void deque::insert_rear(int x)
{
 if(rear>=max-1)
  {
     cout<<"Queue overflow";
     return;
  }
 else
 {	
  if(front==-1)
  {
  front++;
  rear++;
  }
 else
    rear=rear+1;
 arr[rear]=x;
}
}


void deque::delete_front()
{
if(front==-1)
  {
    cout<<"\nDeletion is not possible!!!!!";      
  }
else
{
cout<<"\nDeleted element is:"<<arr[front];
if(front==rear)
{
 front=-1;
 rear=-1;
}
else 
  front=front+1;            //element deleted from front ,, move front forward(first element in the queue is deleted)
}
}

void deque::delete_rear()
{
if(front==-1)
  {
    cout<<"\nQueue is empty";
    return;
  }
else
{
cout<<"\nDeleted element is:"<<arr[rear];
if(front==rear)
{
 front=-1;
 rear=-1;
}
else 
   rear=rear-1;           //element is deleted from rear end ,, so move rear backwards(last element was deleted)
}
}

void deque::display()
{
   cout<<"\nqueue is:";
   for(int i=front;i<=rear;i++) 
      cout<<arr[i]<<" ";
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



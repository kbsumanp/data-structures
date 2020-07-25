#include<iostream>
using namespace std;
#define size 6

class queue
{
int front,rear;
int arr[size];
public:
queue()
{
	front=rear=-1;
}

void add_queue(int val);
int del_queue();
void display();
};

//Access policy ... addition at rear only

void queue::add_queue(int val)
{
  if((front==0 && rear==size-1) || (front==rear+1))
   {
	     cout<<"Queue is full";
         return;
   }
  if(front==-1)
   {
	   front=rear=0;
	   arr[rear]=val;
   }
  else if(rear==size-1 && front!=0)
    {
		rear=0;
		arr[rear]=val;
	}
    else
      {
		  rear++;
		  arr[rear]=val;
	  }
}

//Access policy ... deletion from front only

int queue::del_queue()
{
	if(front==-1)
	 {
		 cout<<"Queue is empty";
		 return 0;
	 }
	int ele=arr[front];
    if(front==rear)
	  {
        front=-1;
        rear=-1;
      }
    else if(front==size-1)
           front=0;
         else
             front++;
return ele;
}

void queue::display()
{
	if(front==-1)
	  cout<<"Queue is empty";
	cout<<"\nCircular queue is:";
	if(rear>=front)
	  {
		  for(int i=front;i<=rear;i++)
		     cout<<arr[i]<<" ";
	  }
	  else 
	    {
			for(int i=front;i<size;i++)
			   cout<<arr[i]<<" ";
			for(int i=0;i<=rear;i++)
			   cout<<arr[i]<<" ";
		}
}


int main()
{
int choice;     
queue q;
cout<<"\n1.Add";
cout<<"\n2.Delete";
cout<<"\n3.Display";
do
{ 
cout<<"\nEnter ur choice:";
cin>>choice;
switch(choice)
  {
   case 1: int d;
           cout<<"\nenter element to be added:";
           cin>>d;
           q.add_queue(d);break;
   case 2: q.del_queue();break;
   case 3: q.display();break;
   default: cout<<"\nwrong choice";
  }
}while(choice!=4);

}

	   
	   

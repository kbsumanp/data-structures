#include<iostream>
using namespace std;
#define n 10

class queue
{
 private:
 
 int a[n];
 int front,rear;
 
 public:
 
 queue()
 {
  front=-1;
  rear=-1;
 }
 bool isempty();
 bool isfull();
 void add_rear(int x);
 int deleteq_front();
 void print();
};


 queue q;
 bool queue::isempty()
 {
   if(front==-1)
     return true;
   else
     return false;
 }
 bool queue::isfull()
 {
  if(rear==n-1)
     return true;
  else 
     return false;
 }
 void queue::add_rear(int x)
 {
	 if(!isfull())
	  {   
		  if(front==-1)
		  {  front=rear=0;}
		  a[rear]=x;
		  rear++;
	  }
	 else
	  cout<<"\nqueue overflow";
 }

 int queue::deleteq_front()
 {
	if(!isempty())
	 {
		 int x;
		 x=a[front];
		 front++;
		 return x;
      }
    else
     {
		 cout<<"\nqueue underflow";
		 return -1;
      }
}

 void queue::print()
 {
	
	cout<<"Queue is: ";
	for(int i=front;i<rear;i++)
	    {
			cout<<a[i]<<" ";
	    }
	
 } 

int main()
{
	        
int choice;
cout<<"\n1.Add an element at rear in queue";
cout<<"\n2.Delete an element(from front) from queue";
cout<<"\n3.Display queue";
do{
cout<<"\nEnter ur choice:";
cin>>choice;
switch(choice)
  {
	   case 1: int p;
	           cout<<"\nenter element to be added:";
	           cin>>p;
	           q.add_rear(p);break;
       case 2: q.deleteq_front();break;
       
       case 3: q.print();break;
       default: cout<<"\nwrong choice";
  }
}while(choice!=4);

}

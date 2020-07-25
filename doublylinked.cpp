//Kumari Suman
//2017CSC1067

#include<iostream>
using namespace std;

struct node
{
int val;
node *next;
node *prev;
};

node *head;

void insertathead(int x);
void insertattail(int x);
void insertatnth(int data,int pos);
void addbefore();
void addafter();
void delete_node(int n);
void deletefirstnode();
void deletelastnode();
void print(node *head);

//---------------------------------------

void insertathead(int x)
{
node *temp=new node;
temp->val=x;
temp->prev=NULL;
temp->next=head;
head->prev=temp;
head=temp;
print(head);
}


//----------------------------------------

void insertattail(int x)
{
node *temp1=new node;
node *p=head;       //for traversing
temp1->val=x;
while(p->next!=NULL)
    p=p->next;
p->next=temp1;
temp1->next=NULL;
temp1->prev=p;
print(head);
}

//--------------------------------------

void insertatnth(int data,int pos)
{
node *temp=new node;
node *p=head;
temp->val=data;
if(pos==1)               //inserting at head
 {
  temp->prev=NULL;
  temp->next=head;
  head->prev=temp;
  head=temp;
  }
for(int i=1;(i<pos-1) && (p!=NULL);i++)               //traversing
  {
  p=p->next;
  }
temp->prev=p;              //2 pointers so 4 linkings,,firstly temp (prev & next) and p (prev & next) 
temp->next=p->next;
if(p->next!=NULL)
  (p->next)->prev=temp;
p->next=temp;
print(head);
}

//---------------------------------------

void addafter()
{
    node *p,*q;      //q=t
    int a, b;        //a=x
    p=new node;
    q=head;

    cout<<endl<<"Enter the node after which u want to add:"<<endl;
    cin>>a;

    cout<<"Enter value to be added"<<endl;
    cin>>b;
    p->val=b;
    p->next=NULL;
    p->prev=NULL;
    while (q !=NULL)
         {
             if(q->val==a)
             {
                 (q->next)->prev=p;
                 p->next=q->next;
                 q->next=p;
                 p->prev=q;
                 cout<<" Element "<<b<<"    successfully added"<<endl;
                 break;
               }
              if(q->next==NULL)
              cout<<"Element "<<a<<" is not present in the Doubly Linked List"<<endl;

        q=q->next;
         }

print(head);
}

//----------------------------------------


void addbefore()
{
    node *q,*p;
    q=head;
    int a, b;
    p=new node;

    cout<<endl<<"Enter node before which you want to insert"<<endl;
    cin>>a;

    cout<<"Enter value to be added"<<endl;
    cin>>b;
    p->val=b;
    p->next=NULL;
    p->prev=NULL;
    while (q!=NULL)
         {
             if((q->next)->val==a)            //just check for next value,,rest same
             {
                 (q->next)->prev=p;
                 p->next=q->next;
                 q->next=p;
                 p->prev=q;
                 cout<<" Element "<<b<<" successfully added"<<endl;
                 break;
             }
              if(q->next==NULL)
              cout<<"Element "<<a<<" is not present in the Doubly Linked List"<<endl;

        q=q->next;
         }
print(head);
}

//-----------------------------------------

void delete_node(int n)
{
node *temp,*p;
p=head;
while(p->next!=NULL)
   {
    if(p->next->val==n)
      {
      temp=p->next;
      p->next=temp->next;
      (p->next)->prev=temp->prev;
      delete(temp);
      }
    p=p->next;
   }
print(head);
}

//---------------------------------------

void deletefirstnode()
{
node *temp=head;
head=head->next;
head->prev=NULL;
delete(temp);
print(head);
}

//------------------------------------–-–

void deletelastnode()
{
node *tail=new node;

node *current=head;
node *previous=new node;

while(current->next!=NULL)      
   { 
     previous=current; 
     current=current->next;	 
   } 
tail=previous;
tail->next=NULL;
delete(current);
print(head);
}

//---------------------------------------

void print(node *head)
{ 
node *q=head;
cout<<"\n the list is \n ";
while(q!=NULL)
{
cout<<q->val<<"->";
q=q->next;
}
}

//--------------------------------------

int main()
{

head=new node;
head->next = NULL;
head->prev = NULL;
head->val=14; 
int choice;
cout<<"\n1. insert at head ";
cout<<"\n2. insert at tail ";
cout<<"\n3. insert at nth position ";
cout<<"\n4. insert after given node";
cout<<"\n5. insert before given node ";
cout<<"\n6. delete node at nth position";
cout<<"\n7. delete node at head";
cout<<"\n8. delete node at end";
cout<<"\n9. print";
do{ 
cout<<"\nchoose ur choice :";
cin>>choice;
switch(choice)
  {
    case 1: int x;
            cout<<"\nenter datavalue:";
            cin>>x;
            insertathead(x);break;
    case 2: int x1;
            cout<<"\nenter datavalue:";
            cin>>x1;
            insertattail(x1);break;
    case 3: int d,p;
            cout<<"\nenter data value:";
            cin>>d;
            cout<<"\nenter position:";
            cin>>p;
            insertatnth(d,p);break;
    case 4: addafter();break;
    case 5: addbefore();break;
    case 6: int n;
            cout<<"\nenter the node to be deleted:";
            cin>>n;
            delete_node(n);break;
    case 7: deletefirstnode();break;
    case 8: deletelastnode();break;
    case 9: print(head);break;
    default:cout<<"\nwrong choice";
   }
                
}while(choice!=10);
    
}


//-----------end--------–---

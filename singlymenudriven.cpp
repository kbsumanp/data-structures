//Kumari Suman
//2017CSC1067

#include<iostream>
using namespace std;

struct node
{
int val;
node *next;
};

node *head=NULL;

//-----------------------------------------

void print();
void insert();  // insert at nth position
void insertathead(int x);   // insert at head
void insertattail(int x);  // insert at tail
void insertafterx();   // insert after x
void insertbeforex();   // insert before x
void insertbetween();   // insert between x
void delete_node();    // delete node

//-----------–---------------------------

void insertattail(int x) 
{
    node *p=new node;
    p->val=x;
    p->next=NULL;
    if(head==NULL)
     {
		//cout<<"Head is NULL!!"<<endl;
		//return;
		p->next=head;             //i.e insertion at head
		head=p;
	 }
	else
	{   node *temp=head;                  //moving head pointer
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
    temp->next=p;
    temp=p;
    }
    print();
}

//----------------------------------------

void insertathead(int x)
{
node *m=new node;
m->val=x;
m->next=head;
head=m;
print();
}

//---------------------------------------


void insertafterx()
{ 
char found=false;
int x;
cout<<"\n node after which element to add:";
cin>>x;
node *i=head;          //traversing

    
while((i!=NULL)&&(!found))
{
if(i->val==x)
 { 
   found=true;
   node *r=new node;        //linking
   node *s=new node;     //insertion of new node
   s->val=14;
   s->next=NULL;
   r=i->next;
   i->next=s;
   s->next=r;
 }
 
else
  i=i->next;
   
}

if(!found)
{
cout<<"\n node does not exist in the list\n";
}
print();
}

//-----------------------------------------

void insertbeforex()
{ 
char found=false;
int x;
cout<<"\n node before which element to add:";
cin>>x;
node *i,*j;
i=head;       //for traversing
j=head;        //for linking


while((i!=NULL)&&(!found))
{
if(i->val==x)
 { 
   found=true;
   node *s=new node;
   s->val=11;
   s->next=NULL;
   j->next=s;
   s->next=i;         //to insert s before i
  }
else
 {  i=i->next;
    j=j->next;
 }
   
}

if(!found)
{
cout<<"\n node does not exist in the list\n";
}
print();
}

//-–---------------------------------------

void insertbetween()
{ 
char found=false;
int x,y;
cout<<"\nnode after which element to add:";
cin>>x;
cout<<"\nnode before which element to add:";
cin>>y;
node *i=head;

    
while((i!=NULL)&&(!found))
{
if((i->val==x)&&((i->next)->val==y))
 { found=true;
   
   node *s=new node;
   s->val=15;
   s->next=NULL;
   s->next=i->next;
   i->next=s;
    
   
  }
else
  i=i->next;
   
}

if(!found)
{
cout<<"\n nodes does not exist in the list\n";
}
print();
}

//-----------------------------------------
//insert at nth position
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
for(int i=1;i<n-1;i++)           //loop till (pos-1) and insert in position pos
  {
   t1=t1->next;     
  }
t->next=t1->next; 
t1->next=t;   
print();
}
    
//-----------------------–----------------

void delete_node(int n)
{
node *temp=head;
if(n==1)                     //1st node
 {
  head=temp->next;
  delete(temp);
  }
else
 {
    
    for(int i=1;i<=n-2;i++)
      {
        temp=temp->next;    // 2nd node  traversing
      }
    node *temp1=temp->next;  // 3rd node
    temp->next=temp1->next;
    delete(temp1);
  }
print();
}

//----------------------------------------
    
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

//-----------------------------------------

int main()
{

int choice;
cout<<"\n1. insert at head ";
cout<<"\n2. insert at tail ";
cout<<"\n3. insert after x ";
cout<<"\n4. insert before x ";
cout<<"\n5. insert between x and y ";
cout<<"\n6. insert at nth position ";
cout<<"\n7. delete node ";
cout<<"\n8. print";
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
    case 3: insertafterx();break;
    case 4: insertbeforex();break;
    case 5: insertbetween();break;
    case 6: insert();break;
    case 7: int n;
            cout<<"\nenter position:";
            cin>>n;
            delete_node(n);break;
    case 8: print();
    default:cout<<"\nwrong choice";
   }
                
}while(choice!=9);
    
}



//------------end-------------


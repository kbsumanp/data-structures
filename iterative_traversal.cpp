#include<iostream>
using namespace std;
#define MAX 20

class bstnode                  //node for binary search tree
{
	public:
	int info;
	bstnode *left, *right;
	
	bstnode()
	{
		info=0;
		left=NULL;
		right=NULL;
	}	
	bstnode(int x)
	{
		info=x;
		left=NULL;
		right=NULL;
	}
};

class stack
{
	bstnode *st[MAX];                      //stack of type bstnode
	int top;
	
	public:
		stack()
		{
			top=-1;
		}
		int isempty()
		{
			if(top==-1)
				return 1;
			else 
				return 0;
		}
		void push(bstnode *x)
		{
			if(top==(MAX-1))
				cout<<"\nStack overflow";
			else
			{
				top=top+1;
				st[top]=x;
			}
		}
		bstnode* ret_top()
		{
			return st[top];
		}
		
		bstnode* pop()
		{
			if(top==-1)
			 {	cout<<"\nUnderflow"; 
				 exit(0);
				 }
			else
			{
				bstnode* x=st[top];
				top=top-1;
				return x;
			}	
		}
	
};

class queue
{
	bstnode *A[MAX];
	int front, rear;
    public:
	queue()
	{
		front= -1;
		rear= -1;
	}
	
	int IsEmpty()
	{
        if((front == -1)&&(rear == -1))
            return 1;
        else
            return 0;
	}
	int IsFull()
	{
		if((front == rear+1)||((front == 0)&&(rear == MAX-1)))
            return 1;
        else
            return 0;
	}
	
	void Enqueue(bstnode *x)
	{
		if(IsFull())
		{
			cout<<"\nQueue is full.";
			return;
		}
		else
		{
		    if(front == -1)
            {
                rear++;
                front++;
            }
            else if(rear == MAX-1)
            {
                rear=0;
            }
            else
            {
                rear++;
            }
            A[rear]=x;
		}
	}
	
	bstnode* Dequeue()
	{
		if(IsEmpty())
		{
			cout<<"\nQueue is empty.";
		}
		else
		{
			bstnode *x= A[front];
			if(front == MAX-1 )
			{
				front = 0;
			}
			else if(front == rear)
			{
				front = rear = -1;
			}
			else
	        {
	            front++;
			}
			return x;
		}
			
	}
	
};

class bst
{
	bstnode *root;
	stack s;
	//queue q;
	public:
	bst()
	{
		root=NULL;
	}
		
	void insert(int x)			//function for inserting values to binary tree.
	{
		bstnode *p, *q, *prev;
		p=new bstnode(x);
		q=root;
		if(q==NULL)
		{
			root=p;
		}
		else
		{
			while(q!=NULL)
			{
				if(x<q->info)
				{
					prev=q;
					q=q->left;
				}
				else
				{
					prev=q;
					q=q->right;
				}
			}
			
			if(x<prev->info)
				prev->left=p;
			else
				prev->right=p;
		}
	}
	
	bstnode* ret_root()
	{
		return root;
	}	
	
	
//***********************ITERATIVE TRAVERSALS**********************
	void pre_order_ite(bstnode *p)
	{
		bstnode *curr;                   //DLR
 		if(p!=NULL)
		{
			s.push(p);                 //pushing root
			
			while(!s.isempty())
			{
				curr=s.pop();
				cout<<curr->info<<" ";
				if(curr->right!=NULL)
					s.push(curr->right);
				if(curr->left!=NULL)
					s.push(curr->left);
			}
		}
		else
			cout<<"\nTree is empty.";
	}
			
	void in_order_ite( bstnode *curr)
	{

   curr=root;          //LDR
   
   while(curr!=NULL || s.isempty()==false)     //stack is not empty
    {
		while(curr!=NULL)
		 {
			 s.push(curr);          //pushing the node
			 curr=curr->left;
		 }
		curr=s.ret_top();
		s.pop();                  //popping the last node
		cout<<curr->info<<" ";
		curr=curr->right;
	}

}
	
	void post_order_ite(bstnode *current)                   //LRD
	{
		  current = root;
        while(current!=NULL || !s.isempty())
        {
            if(current!=NULL)
            {
                s.push(current);
                current = current->left;
            }
            else
            {
                bstnode *temp = s.ret_top()->right;
                if (temp ==NULL) 
                {
                    temp = s.pop();
                    cout<<temp->info<<" ";
                    while (!s.isempty() && temp == s.ret_top()->right) 
                    {
                        temp = s.pop();
                        cout<<temp->info<< " ";
                    }
                }
                 else 
                 {
                    current = temp;
                 }
          }
          }
	}


	void mirror( bstnode *p)
	{
		bstnode *temp;
		if(p!=NULL)
		{
			mirror(p->left);
			mirror(p->right);
			
			temp=p->left;
			p->left=p->right;
			p->right=temp;
		}
	}
	
	int getLeafCount(bstnode *p)
	{
		
	  if( p==NULL)       
	    return 0;
	  if(p->left ==NULL && p->right==NULL)      
	    return 1;            
	  else
	    return getLeafCount(p->left)+
	           getLeafCount(p->right);      
	}
	
	int totalNode(bstnode *p)
	{
		if(p==NULL)
			return 0;
		else
			return 1+totalNode(p->left)+totalNode(p->right);
	}

};

int main()
{
	bst ob;
	char ch;
	int num, num2;
	int leaf, nleaf;
	do
	{
		system("cls");
		cout<<"\n********MENU***********";
		cout<<"\n1. Insert element.";
		cout<<"\n2. Pre-order traversal.";
		cout<<"\n3. In-order traversal.";
		cout<<"\n4. Post-order traversal.";
		cout<<"\n5. Mirror image of tree.";
		cout<<"\n6. Count leaf and non-leaf nodes.";
		cout<<"\n7. Exit.";
		cout<<"\nEnter your choice: ";
		cin>>num;
		
		switch(num)
		{
			case 1: system("cls");
					do
					{
						cout<<"\nEnter value: ";
						cin>>num2;
						ob.insert(num2);
						cout<<"\nEnter more values(y/n): ";
						cin>>ch;
					}while(ch=='y');
					break;
					
			case 2: system("cls");
					ob.pre_order_ite( ob.ret_root());
				
					break;
					
			case 3: system("cls");
					ob.in_order_ite( ob.ret_root());
				
					break;
					
			case 4: system("cls");
					ob.post_order_ite( ob.ret_root());
					break;

			case 5: ob.mirror( ob.ret_root());
					break;
				
			case 6: leaf=ob.getLeafCount( ob.ret_root());
					nleaf=ob.totalNode( ob.ret_root()) -leaf;
					if(leaf==1 && nleaf==0)
					{
						cout<<"\nOnly root node present.";
					}
					else
					{
						cout<<"\nNumber of leaf nodes: "<<leaf;
						cout<<"\nNumber of non-leaf node: "<<nleaf;
					}	
					break;
					

			case 7: cout<<"\nExiting...";
					exit(100);
					break;
			default: cout<<"\nWrong input!!!";
					break;
		}
		cout<<"\n\nReturn to menu(y/n): ";
		cin>>ch;
	}while(ch=='y');
	return 0;
}

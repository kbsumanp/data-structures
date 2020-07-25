#include<iostream>
using namespace std;

struct node
{
int info;
node *left;
node *right;
};

//inserting root node
node *newnode(int item)
{ 
node *temp=new node;
temp->info=item;
temp->left=temp->right=NULL;
return temp;
}

//inserting node in a tree
node* insert(node *item,int x)
{
if(item==NULL)
  return newnode(x);
if(x<item->info)
   item->left=insert(item->left,x);
else if(x>item->info)
     item->right=insert(item->right,x);
return item;
}

//search for an element in tree
bool search(node *root,int data)
{
	if(root==NULL)
	  return false;
	if(root->info==data)
	   return true;
	else if(data<root->info)
	     return search(root->left,data);
	     else
	        return search(root->right,data);
}
	
//count total nodes of the tree
int countnode(node *root)
{
	if(root==NULL)
	  return 0;
	else
	{
	  int l=1;
	  l+=countnode(root->left);
	  l+=countnode(root->right);
	  return l;
	}
}

//find minimum node in tree
int find_min(node *root)                //Binary search tree so min value is present in left side
{
	 if(root==NULL)
	  {
		  cout<<"\nTree is empty!!!";
		  return 0;
	  }
	else if(root->left==NULL)            //tree with just one node
		 return root->info;
		else
		   return find_min(root->left);
}


//find maximum node in the tree
int find_max(node *root)                //Binary search tree so max value is present in right side
{
	 if(root==NULL)
	  {
		  cout<<"\nTree is empty!!!";
		  return 0;
	  }
	else if(root->right==NULL)
		 return root->info;
	  else
	     return find_max(root->right); 
}

//counting no of leaf nodes in a tree
int getLeafCount(node *p)
	{
		
	  if( p==NULL)       
	    return 0;
	  if(p->left ==NULL && p->right==NULL)      
	    return 1;            
	  else
	    return getLeafCount(p->left)+
	           getLeafCount(p->right);      
	}
	
	
//preorder traversal(DLR)
void preorder(node *root)
{
if(root!=NULL)
 { 
  cout<<root->info<<" ";     //DATA
  preorder(root->left);    //LEFT
  preorder(root->right);      //RIGHT
 }
}


//inorder traversal(LDR)
void inorder(node *root)
{
if(root!=NULL)
  {
    inorder(root->left);     //LEFT
    cout<<root->info<<" ";    //DATA
    inorder(root->right);     //RIGHT
  }
}



//postorder traversal(LRD)
void postorder(node *root)
{
if(root!=NULL)
  {
  postorder(root->left);       //LEFT
  postorder(root->right);      //RIGHT
  cout<<root->info<<" ";         //DATA
  }
}



int main()
{
node *root=NULL;

/*           50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 */
root=insert(root,50);
insert(root,30);
insert(root,20);
insert(root,40);
insert(root,70);
insert(root,60);
insert(root,80);
cout<<"--preorder series--";
preorder(root);
cout<<"\n--inorder series--";
inorder(root);
cout<<"\n--postorder series--";
postorder(root);
cout<<"\n\nNo of nodes the the tree="<<countnode(root);
cout<<"\n\n";
int num;
cout<<"Enter no. to be searched:";
cin>>num;
if(search(root,num))
  cout<<"\nNode is present in the tree";
else
  cout<<"\nNode is not present in the tree";
  

cout<<"\nMinimum node is:"<<find_min(root);
cout<<"\nMaximum node is:"<<find_max(root);
cout<<"\nNo of leaf nodes:"<<getLeafCount(root);
}



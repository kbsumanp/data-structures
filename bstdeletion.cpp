#include<iostream>
using namespace std;

struct Node
 {
	int data;
	Node *left;
	Node *right;
};

//Function to find minimum in a tree. 
Node* FindMin(Node* root)
{
	if(root==NULL) return NULL;
	while(root->left != NULL)
	  {
		   root = root->left;
	  }
	return root;
}


// Function to search a delete a value from tree.
Node* Delete(Node *root, int data)
 {
	//finding node to be deleted
	if(root == NULL) return root;  
	else if(data < root->data) 
	    root->left = Delete(root->left,data);           //left subtree
	else if (data > root->data) 
	    root->right = Delete(root->right,data);         //right subtree
	                                               // Wohoo... I found you, Get ready to be deleted	
	else 
	{
		   // Case 1:  No child  (Leaf node)
		
		if(root->left == NULL && root->right == NULL)
		 { 
			delete root;
			root = NULL;        //to avoid the case of dangling pointer ( point root to null)
	   	 }
		
		//Case 2: One child 
		
		else if(root->left == NULL) 
		{
			Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL)
		 {
			Node *temp = root;
			root = root->left;
			delete temp;
		}
		
	  // case 3: 2 children
	  //deletion by copying
		else 
		{ 
			Node *temp = FindMin(root->right);    //(finding minimum in the right subtree) i.e inorder successor
			root->data = temp->data;                     //copying data
			root->right = Delete(root->right,temp->data);        //deleting the successor node(duplicates)
		}
   }
return root;
}
 
//Function to visit nodes in Inorder
void Inorder(Node *root)
{
	if(root == NULL) return; 
	Inorder(root->left);       //Visit left subtree
	cout<<root->data<<" ";     //Print data
	Inorder(root->right);      // Visit right subtree
}
 
 
// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root,int data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}

int main() {
	/*                                       when 3 is deleted    (inorder traversal-1,4,5,10,11)
	            5                                  5
			   / \                                / \
			  3   10                             4   10
			 / \   \                            /      \
			1   4   11                         1        11
    */
	Node* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4); 
	root = Insert(root,1); root = Insert(root,11);
	/*root=Insert(root,6);
	root=Insert(root,2);
	root=Insert(root,11);root=Insert(root,1);
	root=Insert(root,8);root=Insert(root,15);
	root=Insert(root,9);root=Insert(root,10);*/
    cout<<"\nInorder traversal:";
    Inorder(root);                // 1,3,4,5,10,11
    
	// Deleting node 
	int n;
	cout<<"\nEnter the node to be deleted:";
	cin>>n;
	
	root = Delete(root,n);

	//Print Nodes in Inorder after deletion
	
	cout<<"\nInorder traversal after deletion: ";
	Inorder(root);
	cout<<"\n";
}

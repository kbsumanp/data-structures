/* C++ program to find Inorder successor in a BST */


#include<iostream>
using namespace std;


struct Node {
	int data;
    Node *left;
	Node *right;
};

//Function to find some data in the tree(searching)
Node* Find(Node* root, int data) 
{
	if(root == NULL)
	    return NULL;
	else if(root->data==data) 
	    return root;
	else if(root->data < data)              //(data is greater(so move right) than root->data) 
	    return Find(root->right,data);      //right subtree
	else 
	    return Find(root->left,data);       //left subtree  (for this case 1 is less than 5 )
}

//Function to find Node with minimum value in a BST
Node* FindMin(Node* root) 
{
	if(root == NULL) return NULL;
	while(root->left != NULL)
		root = root->left;             //leftmost node
	return root;
}

//Function to find Inorder Successor in a BST
Node* Getsuccessor(Node* root,int data) 
{
	
	// Search the Node - O(h)
	
	Node* current = Find(root,data);    // the node whose inorder successor is to taken out
	if(current == NULL) return NULL;
	if(current->right != NULL) 
	{                                         //Case 1: Node has right subtree(find minimum in the right subtree)
		return FindMin(current->right);       // O(h) [leftmost node in the right subtree]
	}
	else
	 {                                       //Case 2: No right subtree  - O(h)
		Node* successor = NULL;
		Node* ancestor = root;        
		while(ancestor != current)           //to reach the current node
		{
			if(current->data < ancestor->data)       //(data in current node is lesser than data in ancestor node)i.e LEFT subtree
			{
				successor = ancestor;              // so far this is the deepest node for which current node is in left
				ancestor = ancestor->left;
			}
			else                                 //current node lies in right
				ancestor = ancestor->right;       //deeppest node in right subtree
		}
		return successor;                   //(go to the nearest ancestor for which current node is in its left subtree)
	}
}
 
//Function to visit nodes in Inorder
void Inorder(Node *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}
 
// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root,char data) {
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
	/*
	            5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
	Node* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4); 
	root = Insert(root,1); root = Insert(root,11);

	//Print Nodes in Inorder
	cout<<"Inorder Traversal: ";
	Inorder(root);
	cout<<"\n";

	// Find Inorder successor of some node. 
	Node* successor = Getsuccessor(root,1);
	if(successor == NULL)
	   cout<<"No successor Found\n";
	else
       cout<<"Successor is "<<successor->data<<"\n";
}

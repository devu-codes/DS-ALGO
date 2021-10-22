// IMPLEMENTATION 
/*
BST background 

		Array(unsorted) 	Array(Sorted) 	Linked List    BST(balanced) 	Hash Table
		--------------------------------------------------------------------------------
Search 		O(N)				O(LogN)			O(N)			O(LogN)			O(1)	
Insert 		O(1)				O(N)			O(1)			O(LogN)			O(1)
Delete 		O(N)				O(N)			O(N)			O(LogN)			O(1)
Find clos-  O(N)				O(LogN)			O(N)			O(LogN)			O(N)
est
sorted-		O(nLogN)			O(N)			O(nLogN)		O(N)			O(nLogN)
Traversal

it's linked list 

c++ STL 
map, set, multimap, multiset

Operations: 
 O(h) : Time 

 h - height of search tree
skew tree O(N)
balanced BST - O(LogN)
	

*/


#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// Node for BST
struct Node
{	
	int key;
	Node* left;
	Node* right;

	Node(int x){
		key = x;
		left = right = NULL;
	}
};

// =========================== Search in BST ==================================
// Time O(h) Space O(h)
// =============================recursive===================================
bool search(Node* root, int x){
	if(root == NULL)
		return false; 
	else if(root->key == x){
		return true;
	}
	else if(root->key > x){
		return search(root->left, x);
	}
	else{
		return search(root->right, x);
	}
}


// ========================== Insert in BST =================================

// =============================Recursive ==================================
// Time O(h) space O(n)
Node* insert(Node* root, int x){

	if (root == NULL)
		return new Node(x);

	else if(root->key < x){
		root->right = insert(root->right, x);
	}
	else if(root->key > x){
		root->left = insert(root->left, x);
	}
	return root;
}

// ========================= Iterative =======================

// Time O(h) space: O(1)
Node* insert(Node* root, int x){

	Node* temp = new Node(x);
	Node* parent = NULL;
	Node* curr = root;

	while(curr!=NULL){
		parent = curr;
		if(curr->key > x){
			curr = curr->left;
		}	
		else if(curr->key < x){
			curr = curr->right;
		}
		else{
			return root;
		}
	}
	// for empty tree
	if(parent == NULL){
		return temp;
	}
	if(parent->key > x){
		parent->left = temp;
	}  
	else
		parent->right = temp;

	return root;
}

// =========================== Delete Node BST =============================
Node* getSuccessor(Node* curr){
	curr = curr->right;
	while(curr!=NULL and curr->left!=NULL){
		curr = curr->left;
	}
	return curr;
}

Node* delNode(Node* root, int x){
	if(root == NULL)
		return root;

	if(root->key > x){
		root->left = delNode(root->left, x);
	}
	else if (root->key < x)
		root->right = delNode(root->right, x);
	else{
		// when left is empty
		if(root->left == NULL){
			Node* temp = root->right;
			delete root;
			return temp;
		}
		// when right is empty 
		else if(root->right == NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		}
		// when both children are Not empty 
		else{
			Node* succ = getSuccessor(root);
			root->key = succ->key;
			root->right = delNode(root->right, succ->key);
		}

	}
	return root;
}

// ============================== Floor in a BST ===========================
// key given, if key is present in tree return Node , else return predecessor 
// Time: O(h)  Space: O(1)

Node* floor(Node* root, int x){
	Node* res = NULL;
	while(root!= NULL){
		if(root->key == x){
			return root;
		}
		else if(root->key > x){
			root = root->left;
		}
		else{
			res = root;
			root = root->right;
		}
	}
	return res;
}

//  ============================= Ceil in BST ===============================

Node* ceil(Node* root, int x){
	Node* ans = NULL;
	while(root->NULL){
		if(root->key == x){
			return root;
		}
		else if(root->key > x){
			ans = root;
			root = root->left;
		}
		else{
			root = root->right;
		}
	}
}



//  ========================================== Driver Code =========================
int main(int argc, char const *argv[])
{
	


	return 0;
}  
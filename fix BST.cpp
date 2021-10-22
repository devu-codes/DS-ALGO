// Fix a BST with two Nodes swapped 

#include <iostream>

using namespace std;

struct Node{
	int key;
	Node *left, *right;
	Node(int x){
		key = x;
		left = right = NULL;
	}
}

/*
Approach 
prev= -inf, first = NULL, second = NULL
inordoer traversal of BST is sorted array
for every iteration 
	check arr[i] < prev 
	if above is true-- then violations 
		if first = NULL 
			first = prev 
		second = current Node 
	prev = arr[i]	

*/


Node* prev = NULL, *first = NULL, *second = NULL;

void fixBST(Node* root){

	if(root == NULL)
		return;
	fixBST(root->left);

	if(prev!=NULL and root->key < prev->key){
		if(first == NULL)
			first = prev;
		second = root;
	}
	prev = root;
	fixBST(root->right);

}

int main(){

	return 0;
}
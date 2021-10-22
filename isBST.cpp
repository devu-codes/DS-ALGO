// Check for BST

#include <iostream>

using namespace std;

bool isBST(Node* root){

	if(root == NULL)
		return true;

	root->left = isBST(root->left);
	root->right = isBST(root->right);

	if(root->left < root & root->right > root)
		return true;

	return false;qqqq
}

// efficient 

bool BST(Node* root, int min, int max)
{

	if(root == NULL){
		return True;
	}

	return (root->key > min and root->key < max and BST(root->left, min, root->key)
			and BST(root->right,root->key, max));
}

// efficient Inorder solution
int prev = INT_MIN;
bool BST_check(Node* root){
	if(root == NULL)
		return true;
	if (BST_check(root->left)== false) 
		return false;
	if(root->key <= prev)
		return false;
		prev = root->key;
	return BST_check(root->right); 
}


int main(int argc, char const *argv[])
{
	/* code */

	int min = INT_MIN;
	int max = INT_MAX
	cout << BST(root, min, max);
	return 0;
}
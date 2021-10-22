// Kth smallest Elements 

#include <iostream>
#include <set>
#include <vector>
#include <climits>

using namespace std;

struct Node{
	int key;
	Node *left, *right;
	int lcount;
	Node (int x){
		key = x;
		left = right = NULL;
		lcount = 0;
	}

};
// Naive 
int cnt = 0;
void printKth(Node* root,int k)
{
	if(root!=NULL){
		printKth(root->left, k);
		cnt++;
		if(cnt == k)
			cout << root->key;
		printKth(root->right, k);
	}
}


// Travel inorder
Node* Kth(Node* root, int k){
	
	if(root == NULL)
		return NULL;
	int count = root->lcount + 1;

	if(count == k)
		return root;
	if (count > k){
		return Kth(root->left, k);	
	}
	return Kth(root->right, k-count);
}


int main(int argc, char const *argv[])
{
	/* code */
	Node* root = new Node(1);
	root->left = new Node (INT_MIN);
	root->right = new Node(INT_MAX);

	Node* ans = Kth(root,1);
	cout << ans->key;
	return 0;
}
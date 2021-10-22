// Pair with given sum in BST 

#include <iostream>
#include <unordered_set>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
	Node(int x){
		data = x;
		left = right = NULL;
	}
};

// x + y = sum 
//  x = sum - y

// Method 2 - Hashing 
// O(N) Time & Space 
bool isPairSum(Node* root, int sum, unordered_set<int> &s){
	if(root == NULL)
		return false;
	if(isPairSum(root->left, sum, s) == true)
		return true;
	if(s.find(sum - root->key) != s.end())
		return true;
	else 
		s.insert(root->key);
	return isPairSum(root->right, sum, s);
}
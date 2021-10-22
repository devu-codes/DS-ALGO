// Bottom View of Tree 

#include <iostream>
#include <queue>
#include <map>

using namespace std; 

struct Node
{
	int key;
	Node* left, *right;
	Node(int x){
		key = x;
		left = right = NULL;
	}
};

void bottomView(Node* root){

	std::map<int, int> map;
	queue<pair<Node*, int> > q;
	q.push(make_pair(root, 0));

	while(!q.empty()){
		pair<Node*, int> temp = q.front();
		Node* node = temp.first;
		int hd = temp.second;

		map[hd]=(node->key);
		if(node->left)
			q.push(make_pair(node->left, hd-1));
		if(node->right)
			q.push(make_pair(node->right, hd+1));
	}

	for(auto x: map)
		cout << x.second << " ";

}


int main(int argc, char const *argv[])
{
		
	Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    cout << "Bottom view of the given binary tree :\n";
    bottomView(root);
    return 0;

	return 0;
}
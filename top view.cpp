// Top View of Binary Tree 


#include <iostream>
#include <map>
#include <utility>
#include <queue>
using namespace std; 


struct Node{
	int key;
	Node*left, *right;
	Node(int x){
		key = x;
		left = right = NULL;
	}
};

void topView(Node* root){
	std::map<int, int> map;
	queue<pair<Node*, int > > q;
	q.push(make_pair(root, 0));

	while(!q.empty()){
		pair<Node*, int> temp = q.front();
		q.pop();
		Node* node = temp.first;
		int hd = temp.second;
		map[hd] = node->key;
		if(node->left)
			q.push(make_pair(node->left, hd-1));
		if(node->right)
			q.push(make_pair(node->right, hd+1));	
	}
	for(auto x:map){
		cout << x.second << endl;
	}
}


int main(){
	Node* root = new Node(10);
	root->left = new Node(1);
	root->right = new Node(2);

	topView(root);

	return 0;
}
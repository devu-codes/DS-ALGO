// Vertical traversal of tree 

#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

struct Node {

	int key;
	Node *left *right;
	Node(int x){
		key = x;
		left = right = NULL;
	}
};


void vertical_traverse(Node* root){

	map<int, vector<int>> HashMap;
	queue<pair<Node*, int >> q; 
	q.push({root, 0});

	while(!q.empty()){
		pair<Node*, int> temp = q.front();
		q.pop();
		hd = temp.second();
		Node* node = temp.first;


		HashMap[hd].push_back(node->key);
		if(node->left)
			q.push({node->left, hd -1 });
		if(node->right)
			q.push({node->right, hd+1});


	}
	for(auto x: HashMap)
		cout << x.second << " "; 
}

int main(int argc, char const *argv[])
{
	


	return 0;
}
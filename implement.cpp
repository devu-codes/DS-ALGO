// Implementation of tree 


// Applications 
// build tree 
// Appication 
// - Organisationsal structure 
// - Folder 
// - XML/HTML (JSON)
// - OOP(Inheriance)

// Binary search Tree

// Binary Heop - Priority queue
// B and B+ tree in DBMS
// Spanning and Shorted path trees in Computer Networks 
// Parse Tree, Expression in Compilers

// Trie
// Suffix Tree 
// Binary Indexed Tree
// Segment Tree 

/*Binary Tree Implementation
	Tree Traversal - Inorder, Preorder, postorder  (DFS)
	level order (BFS)
*/



#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

struct Node
{
	int key;
	Node *left;
	Node *right;
	// Constructor
	Node(int k){
		key = k;
		left = right = NULL;
	}
};


// ---------------------------Traversals of Tree ------------------------//
// DFS --> Pre , post, inorder 
// Complexity - O(N) Time   O(h) Space 
void inorder(Node* root){
	if(root!=NULL){
		inorder(root->left);
		cout << root->key << " ";
		inorder(root->right);
	}
}

void preorder(Node* root){
	if(root!=NULL){
		cout << root->key << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Node* root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout << root->key << " "; 
	}
}


// ----------------------Iterative Inorder Traversal -------------------------

void iter_inorder(Node* root){

	stack<Node*> st;
	Node* curr = root;
	while(curr != NULL or s.empty() == false){
		while(curr!=NULL){
			st.push(curr);
			curr = curr->left;
		}
		curr = st.top();
		st.pop();
		cout << (curr->key) << " ";
		curr = curr->right;
	}
}

// ---------------- Iterative Preroder traversal ----------------------
// root - left - right
void iter_preorder(Node* root){
	if(root == NULL)
		return;
	stack <Node*> st;

	st.push(root);

	while(!st.empty()){
		Node* curr = st.top();
		cout << curr->key << " ";
		st.pop();
		if(curr->right)
			st.push(curr->right);
		if(curr->left)
			st.push(curr->left);
	}
}

// ----------------- tree Traversal in Spiral Form -----------------------

void spiral(Node* root){
	if(root == NULL){
		return;
	}
	queue<Node* > return;
	stack<int > st;
	bool reverse = false;
	q.push(root);
	while(!q.empty()){
		int cnt = q.size();
		for(int i=0; i<cnt; i++){
			Node* curr = q.front();
			q.pop();
			if(reverse){
				s.push(curr->key);
			}
			else{
				cout << curr->key << " ";
			}
			if(curr->left)
				q.push(curr->left);
			if(curr->right)
				q.push(curr->right);

		}
		if(reverse){
			while(!st.empty()){
				cout << st.top() << " "
				st.pop(); 
			}
		}
		reverse = !reverse;
		cout << endl;
	}


}

// -------------------------------Height and Distance of tree ----------------------------

int height(Node* root){

	if(root == NULL)
		return 0;
	return max(height(root->left),height(root->right)) + 1;
}

void printKDist(Node* root, int k){
	if(root == NULL)
		return;
	if(k == 0){
		cout << root->key <<  " ";
	}
	else{
		printKDist(root->left, k-1);
		printKDist(root->right, k-1);
	}
}


// Level Order Traversals (BFS)

// Approach 1: Find Height of tree then print from root toh height h 
// O(h*N) : Time 
void level_order(Node* root){
	int h = height(root);
	for(int i=0; i<h; i++){
		printKDist(root, i);
	}
}

// Time: Theta(N); Space: O(N) (theta(1) to theta(N)) 
void level_order_print(Node* root){
	if(root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while(q.empty() == false){
		Node *temp = q.front();
		q.pop();
		cout << temp->key << " ";
		if(temp->left!=NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
	}
}

// level order traversal line by line 

void printLevelOrder(Node* root){
	if(root==NULL)
		return;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(q.size() > 1){
		Node *temp = q.front();
		q.pop();
		if(temp ==NULL){
			cout << "\n";
			q.push(NULL);
			continue;
		}
		cout << temp->key << " ";
		if(temp->left != NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
	}
}

// Method - 2 Level order traversal 
// O(N) : Time  theta(width) : Space 

void print_level_order(Node* root){
	if(root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while(q.empty()==false){
		int count = q.size();
		for(int i=0; i<count; i++){
			Node *curr = q.front();
			q.pop();
			cout << curr->key << " ";
			if(curr->left!=NULL)
				q.push(curr->left);
			if(curr->right != NULL)
				q.push(curr->right);
		}
		cout << endl;
	}

}

// --------------------------Size of Tree -----------------------
//  ------------No of Nodes -----------------

// O(N) : Time & O(h) : Space 
int size(Node* root){
	if(root == NULL)
		return 0;
	return size(root->left) + size(root->right) + 1; 
}


// -----------------------Maximum in Binary Tree --------------

int maximum(Node* root){
	if(root==NULL)
		return INT_MIN;
	return max(root->key, max(maximum(root->left), maximum(root->right)));
}

// ** -----------------------------Imp: Left View of Binary Tree --------

// recursive - preorder approach
// Time : O(N) space: theta(h)
int maxLevel = 0;
void leftView(Node* root, int level){
	if(root==NULL)
		return;
	if(maxLevel < level){
		cout << root->key << " ";
		maxLevel = level;
	}
	printLeft(root->left, level+1);
	printLeft(root->right, level+1);

}

void printLeftView(Node* root){
	leftView(root, 1);
}

// Method 2 - iterative 
void printLeft(Node* root){

	if(root == NULL)
		return;
	queue<int> q;
	q.push(root);

	while(q.empty() == false){
		int count = q.size();
		for(int i=0; i<count; i++){
			Node *curr = q.front();
			q.pop();
			if(i == 0)
				cout << curr->key << " ";
			if(curr->left !=NULL)
				q.push(curr->left);
			if(curr->right != NULL)
				q.push(curr->right);
		}
	}

}

// ----------------------Children Sum Property ------------------------
// left child + right child = Root 
// O(N): time  O(h): space
bool isCSum(Node* root){
	if(root == NULL)
		return true;
	if(root->left == NULL and root->right == NULL)
		return true;
	int sum = 0;
	if(root->left != NULL)
		sum += root->left->key;
	if(root->right != NULL)
		sum += root->right->key;
	return (root->key == sum) and isCsum(root->left) and isCSum(root->right);
}

// ---------------------------Balanced binary tree -------------------
// Time: O(N2) and space: O(h)
bool isBalanced(Node* root){
	if(root==NULL)
		return true;
	
	int h1 = height(root->left);
	int h2 = height(root->right);

	return abs(h1-h2) <= 1 and isBalanced(root->left) and isBalanced(root->right);
}

// Time: O(N) and space: O(h)
int is_balanced(Node* root){
	if(root==NULL)
		return 0;
	int lh = is_balanced(root->left);
	if(lh == -1)
		return -1;
	int rh = is_balanced(root->right);
	if(rh == -1)
		return -1;
	if(abs(lh-rh) > 1)
		return -1;
	else
		return max(lh, rh) + 1;
}

// --------------------------- Max width of binary tree ------------------
// O(N) Time , O(N) : Aux space 
int maxWidth(Node* root){
	if(root == NULL)
		return 0;
	queue<Node*> q;
	q.push(root);
	int res = 0;
	while(q.empty() == false){
		int count = q.size();
		res = max(res, count);
		for(int i=0; i<count; i++){
			Node* curr = q.front();
			q.pop();
			if(curr->left != NULL)
				q.push(curr->left);
			if(curr->right != NULL)
				q.push(curr->right);
		}
	}
	return res;
}

// -------------Binary Tree to Doubly Linked list ---------------------
// Inorder Traversal left, root, right 

Node *prev = NULL;
Node* BTToDLL(Node* root){
	if(root == NULL)
		return root;
	// call left 
	Node *head = BTToDLL(root->left);
	// process root 
	if(prev == NULL)
		head = root;
	else{
		root->left = prev; 
		prev->right = root; 
	}
	prev = root;
	// call right 
	BTToDLL(root->right);
	return head;
}  

// ---------------------Binary Tree from Inorder and preorder ---------
// inorder = left, root, right
// preorder = root, left, right 
// is : inorder start, 
// ie : inorder end 

int preIndex = 0;
Node* construct(int inorder[], int preorder[], int is, int ie){
	// base case 
	if(is > ie)
		return NULL;

	// make node every time 
	Node* root = new Node(preorder[preIndex]);
	preIndex++;

	// search root in Inorder array 
	int inIndex;
	for(int i=is; i=ie; i++){
		if(inorder[i] == root->key){
			inIndex = i;
			break;
		}
	}
	// recursive call in left and right subtree.
	root->left = construct(inorder, preorder, is, inIndex -1);
	root->right = construct(inorder, preorder, inIndex + 1, is);

	return root;
}

// -------------------------------diameter --------------------
int diameter(Node* root){
	if(root == NULL)
		return 0;
	int d1 = diameter(root->left);
	int d2 = diameter(root->right);
	int d3 = 1 + height(root->left) + height(root->right);

	return max(d1, max(d2, d3));
}

// Efficient - O(N): Time  O(h): Space 
int res = 0;
int height(Node* root){
	if(root == NULL)
		return 0;
	int lh = height(root->left);
	int rh = height(root->right);
	res = max(res, lh+rh+1);
	return 1 + max(lh, rh);
}


// --------------------- LCA ----------------------------
// Naive time: thetha(n) and O(N): Space
bool findPath(Node* root, vector<int > &p, int n){
	if(root == NULL)
		return false;
	p.push_back(root);
	if(root->key == n)
		return true;
	if(findPath(root->left, p, n) or (findPath(root->right, p, n)))
		return true;

	p.pop_back();
	return false;
}

Node* lca(Node* root, int n1, int n2){
	vector<Node* > path1, path2;
	if(findPath(root, path1, n1) == false or findPath(root, path2, n2) == false){
		return NULL;
	}
	for(int i=0; i<path1.size()-1 and i<path2.size()-1; i++){
		if(path1[i+1] != path2[i+1])
			return path[i];
	}
	return NULL;
}

// Efficient solution O(N): time and theta(h): space

Node* LCA(Node* root, int n1, int n2){
	// if nothing 
	if(root==NULL)
		return NULL;
	// present in one of root
	if(root->key == n1 or root->key == n2){ 
		return root;
	}

	Node* lca1 = LCA(root->left, n1, n2);
	Node* lca2 = LCA(root->right, n1, n2);
	// one in left and other in right 
	if(lca1 != NULL and lca2 != NULL)
		return root;
	// present in one of subtrees 
	if(lca1 != NULL)
		return lca1;
	else{
		return lca2;
	}
}

// ------------------- COunt Nodes in Complete Binary tree -----------

int countNodes(Node* root){

	int lh = 0, rh = 0;
	Node* curr = root;
	while(curr!=NULL){
		lh++;
		curr = curr->left;
	}
	curr = root;
	while(curr!=NULL){
		rh++;
		curr = curr->right;
	}
	if(lh == rh){
		return pow(2, lh) - 1;
	}
	return 1 + countNodes(root->left) + countNodes(root->right);
}

// -------------------------- burn leaf --------------------------

int burnLeaf(Node* root, int leaf, int &dist){
	if(root == NULL)
		return 0;
	if(root->key == leaf){
		dist = 0;
		return 1;
	}
	int ldist = -1, rdist = -1;
	int lh = burnLeaf(root->leaf, leaf, ldist);
	int rh = burnLeaf(root -)
}

// ========================Dist bw two nodes=================================
bool isNodePresent(Node* root, int n1){
	if(root == NULL)
		return false;

	if (root == n1)
		return true;

	return isNodePresent(root->left, n1) or isNodePresent(root->right, n1);
}

Node* findLCA(Node* root,int n1,int n2){
	if(root == NULL)
		return;
	// if one is left and other is right
	Node* left = findLCA(root->left, n1, n2);
	Node* right = findLCA(root->right, n1, n2);

	if(left and right){
		return root;
	} 
	if(left){
		return left;
	}
	return right;
}

int findLevel(Node* root, Node* node, int level){
	//base case
	if(root == NULL)
		return INT_MIN;
	if(root == node)
		return level;

	int left = findLevel(root->left, node, level + 1);
	if(left !=  INT_MIN){
		return left;
	}
	return findLevel(root->right, node, level + 1);
}


int findDistance(Node* root, Node* n1, Node* n2){
	Node* lca =  NULL;

	if(isNodePresent(root, n1) and isNodePresent(root, n2)){
		lca = findLCA(root, n1, n2);
	}
	else{
		return NULL;
	}
	return findLevel(lca, x, 0) + findLevel(lca, y ,0);
}

//  ============================== Serialize and deserialize ================
// serialize(node* root, vector <int > arr) .. takes the root fill it in array

// deserialize(vector<int> &arr) .... takes the array return the root 

// application = send binary tree structure over the network to other's 
// Naive 
// int inorder(Node* root){
// 	vector<int> v;

// 	if(root == NULL){
// 		v.push_back(-1);
// 		return;
// 	}
// 	inorder(root->left);
// 	v.push_back(root->key);
// 	inorder(root->left);
// 	return v;
// }

// int preorder(Node* root){
// 	vector<int > V;
// 	if(root == NULL)
// 		return -1;
// 	V.push_back(root->key);
// 	preorder(root->left);
// 	preorder(root->right);
// }


// Serialisation Function
const int EMPTY = -1;

void serialize(Node* root, vector<int > &V){
	if(root == NULL){
		V.push_back(EMPTY);
		return;
	}

	// preorder
	V.push_back(root->key);	
	serialize(root->left, V);
	serialize(root->right, V);
}

// Derialise function
// construct tree back from array
// arr[] = [10, 20, -1, -1, -1]
const int EMPTY = -1;
int index= 0;
Node* deserialize(vector<int> &V){
	if(index ==V.size())
		return NULL;
	int val = V[index];
	index++;
	if(val == EMPTY)
		return NULL;
	Node* root = new Node(val);
	root->left = deserialize(V);
	root->right = deserialize(V);
	return root; 
}

//  ---------------------------Driver Code --------------------------
int main(int argc, char const *argv[])
{
	/* code */
	Node* root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);	

	// level_order(root);
	// level_order_print(root);
	printLevelOrder(root);

	return 0;
}
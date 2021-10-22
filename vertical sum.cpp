
#include <iostream>
#include <map>
using namespace std;

// utility function
void vertical_sum(Node* root, int hz, map<int, int > &HashMap){

	if(root==NULL)
		return;
	vertical_sum(root->left, hz-1, HashMap);
	HashMap[hz] += root->data;
	vertical_sum(root->right, hz+1, HashMap);

}


void vSum(Node* root){
	map<int, int > HashMap;
	vSum(root, 0, HashMap);

	for(auto sum: HashMap)
		cout << sum.second << " ";
}


int main(int argc, char const *argv[])
{
	


	return 0;
}

// kth smallest 

#include <iostream>
#include <set>
#include <vector>

using namespace std;

// struct Node{
// 	int key; 
// 	Node* left, *right;
// 	int lcount = 0;

// 	Node(int x){
// 		key =x; 
// 		left = right = NULL;
// 		lcount = 0;
// 	}
// }
// 7,8,9,24,1,3,67,5
void Ceilleft(int arr[], int n){
	vector<int> V;


	set<int> s;

	for(int i=0; i<n; i++){
		auto greater = s.lower_bound(arr[i]);
		if(greater == s.end())
			V.push_back(-1);
		else 
			V.push_back(*greater);
		s.insert(arr[i]);
	}
	for(int i=0; i < n; i++){
		cout << V[i] << " ";
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	int arr[] = {8, 20 , 30, 15, 5, 12};
	int n = sizeof(arr)/ sizeof(int);

	Ceilleft(arr, n);

	return 0;
}
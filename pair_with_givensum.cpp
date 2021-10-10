

#include <iostream>
#include <unordered_set>

using namespace std;


// O(N) Complexity
bool isPair(int arr[], int n, int sum){

	unordered_set<int> HashSet;
	for(int i=0; i<n; i++) {
		if(HashSet.find(sum-arr[i])!=HashSet.end()){
			return true;
		}
		HashSet.insert(arr[i]);
	}
	return false;
}


int main(int argc, char const *argv[])
{
	int arr[]= {};
	int n; 

	int sum;

	cout << isPair(arr, n, sum);

	return 0;
}
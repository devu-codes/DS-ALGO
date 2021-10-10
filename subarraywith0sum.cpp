
// 4,2,-3,1,6
// 4, 6, 3, 4, 6



#include <iostream>
#include <unordered_set>

using namespace std;

bool subArray(int arr[], int n){
	unordered_set< int > HashSet;

	int sum = 0;

	for(int i=0; i<n; i++){
		sum += arr[i];

		if(sum == 0 or HashSet.find(sum) != HashSet.end()){
			return true;
		}

		HashSet.insert(sum);
	}
	return false;
}
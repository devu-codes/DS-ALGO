

#include <iostream>
#include <unordered_set>

using namespace std;

// Naive 
bool subarraySum(int arr[], int n, int sum){
	unordered_set<int> HashSet;
	int preSum = 0;

	for(int i=0; i<n; ++i){
		preSum += arr[i];
		if(preSum == sum)
			return true;
		if(HashSet.find(presum - sum) != HashSet.end()){
			return true;
		}
		HashSet.insert(preSum);
	}
	return false;
}
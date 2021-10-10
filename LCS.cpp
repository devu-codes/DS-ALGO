// Longest Consecutiv subsequences 

#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


// Method 1 :

// Use sorting  - O(NlogN)

int findLongest(int arr[], int n){
	sort(arr, arr+n);
	int res = 1, curr = 1;
	for(int i=1; i<n; i++){
		if(arr[i] == arr[i-1] + 1)
			curr++;
		else{
			res = max(res, curr);
			curr =1;
		}
	}
	res = max(res, curr);
	return res;
}

// Using HashMap
int find_longest(int arr[], int n){
	int res = 0;
	unordered_set<int> HashSet;
	for(int i=0; i<n; i++){
		HashSet.insert(arr[i]);
	}
	for(int i=0; i<n; i++){
		if(HashSet.find(arr[i] -1) == HashSet.end()){
			int curr = 1;
			while(HashSet.find(arr[i]+curr) != HashSet.end()){
				curr++;
			}
			res = max(res, curr);
		}
	}
	return res;
}
/*
arr[] = {15, 12, 13, 12, 12, 13, 18}
output = 4 
15, 12, 13 ,18

arr[] = {10, 10, 10}
op = 1

arr[] = {10, 11, 12}
op = 3
*/

#include <iostream>
#include <unordered_set>

using namespace std;
// Naive O(N2)
int count_distinct(int arr[], int n){
	
	int res = 0;
	for(int i=0; i<n; ++i){
		bool flag = false;
		for(int j=0; j<i; ++j){
			if(arr[i] == arr[j]){
				flag = true;
				break;
			}
		}
		if(flag == false)
			res++;
	}
	return res; 
}

// Efficient - O(N)
int countDistinct(int arr[], int n){

	unordered_set<int> s;
	for(int i=0; i<n; ++i)
		s.insert(arr[i]);

	return s.size();

}

// Improved efficient 
int distinctCount(int arr[], int n){
	unordered_set<int> s(arr, arr+n);
	return s.size();
}


int main(int argc, char const *argv[])
{
	
	int arr[] = {10, 20, 101, 20 ,20, 15, 14};
	int n = sizeof(arr) / sizeof(int);

	cout << distinctCount(arr, n);

	return 0;
}
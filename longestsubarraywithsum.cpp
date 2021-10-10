// Longest subarray with given sum

// arr [] = 5, 8, -4, -4, 9, -2, 2
// sum = 0
// Op = 3

# include <iostream>
# include <unordered_map>
using namespace std;

// Naive Solution

int maxLen(int arr[], int n, int sum){
	int res = 0;
	for(int i=0; i<n; i++){
		int curr_sum = 0;
		for(int j=i; j<n; j++){
			curr_sum += arr[j]; 
			if (curr_sum == sum){
				res = max(res, j-i+1);
			}
		}
	}
	return res;
}

// Efficient Solution 
int MaxLen(int arr[], int n, int sum){
	unordered_map <int, int > m;
	int preSum = 0, res =0; 
	for(int i=0; i<n; i++){
		preSum += arr[i];
		if(preSum == sum)
			res = i+1;
		if(m.find(preSum) == m.end())
			m.insert({preSum, i});
		if(m.find(preSum - sum) != m.end())
			res = max(res, i - m[preSum - sum]);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	/* code */
	int arr[] = {};
	int n; 
	int sum; 

	cout << MaxLen(arr, n, sum) << endl;
	return 0;
}
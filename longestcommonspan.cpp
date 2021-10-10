// Longest Common Span 
// arr =  0,1,0,0,0,0
// arr1 = 1,0,1,0,0,1 
// op = 4  

# include <iostream>

using namespace std;

int maxCommon(bool arr[], bool arr1[], int n){
	int res = 0;
	for(int i=0; i<n; i++){
		int sum1 =0, sum2 = 0;
		for(int j=i; j<n; j++){
			sum1 += arr[j];
			sum2 += arr1[j];

			if(sum1 == sum2){
				res = max(res, j-i+1);
			}
		}
	}
	return res;
}

// method 2 --
// trick: subtract corresponding elements then find longest subarray with zeor sum

int maxCommonsubArray(int arr1, int arr2, int n){

	int temp[n];
	for(int i=0; i<n; i++){
		temp[i] = arr1[i] - arr2[i];
	}

	unordered_map<int, int > HashMap;

	int preSum = 0, res = 0;
	for(int i=0; i<n; i++){
		preSum += temp[i];

		if(preSum = 0){
			res =i+1;
		}
		if(HashMap.find(preSum) != HashMap.end()){
			res = max(res, i-HashMap[preSum]);
		}
		else{
			HashMap.insert({preSum, i});
		}
	}
	return res;
}
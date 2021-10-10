// Longest subarray with equal no of 0 and 1

# include <iostream>
# include <unordered_map>
using namespace std;

int longestSub(bool arr[], int n){

	int res = 0;
	for(int i=0; i<n; i++){
		int c0 = 0, c1= 0;
		for(int j=i; j<n; j++){
			if(arr[j] == 0){
				c0++;
			}
			else{
				c1++;
			}
			if(c0 == c1){
				res = max(res, j-i+1);
			}
		}
	}
	return res;
}
/* Efficint Sum 
Trick = [0,1,1,1,1,1,0,0,0,0,1,1,1]
if we replace every 0 with -1 then, 
problem is length of subarray with sum is 0

*/

int longestsubArray(int arr[], int n){
	// for(int i=0; i<n; i++){
	// 	if(arr[i] == 0){
	// 		arr[i] = -1;
	// 	}
	// }
	unordered_map <int, int > HashMap;
	int preSum = 0, res = 0;
	for(int i=0; i<n; i++){
		preSum += arr[i];
		if(preSum == 0){
			res = i+1;
		}
		
		if(HashMap.find(preSum) != HashMap.end()){
			res = max(res, i - HashMap[preSum]);
		}
		else{
			HashMap[preSum] = i;
		}
	}
	return res; 
}

int main(int argc, char const *argv[])
{
	
	int arr[] = {1,0,1,0,1,0,1,1,0,1,0,1,1,1};
	int n = sizeof(arr) / sizeof(int);

	for(int i=0; i<n; i++){
		if(arr[i] == 0)
			arr[i] = -1;
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << longestsubArray(arr, n) << endl;

	return 0;
}
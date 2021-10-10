// Count Distinct Element in Every Window 

# include <iostream>
# include <unordered_map>
using namespace std;

// Efficient Method 

void printDistinct(int arr[], int n, int k){
	unordered_map <int, int> HashMap;

	int cnt = 0;
	for(int i=0; i<k; i++){
		if(HashMap[arr[i]] == 0)
			cnt++;
		HashMap[arr[i]]++;
	}

	cout << cnt << endl;

	for(int i=k; i<n; i++){
		HashMap[arr[i-k]]--;
		if(HashMap[arr[i-k]] == 1)
			cnt--;

		if(HashMap[arr[i]] == 0){
			cnt++;
		}
		HashMap[arr[i]]++;

		cout << cnt << endl;
	}
}
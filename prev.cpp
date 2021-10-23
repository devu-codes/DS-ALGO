// previous greater element 

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std; 

// arr = 15 10 18 12 4 6 2 8
// op = -1 15 -1 18 12 12 6 12

// if null return -1 


// O(N) time and space 
void prev_greater(int arr[], int n){
	stack <int > s;
	cout << -1 << " ";
	s.push(arr[0]);
	for(int i=1; i<n; i++){
		while(!s.empty() and s.top() < arr[i]){
			s.pop();
		}
		int ans = s.empty()? -1:s.top();
		cout << ans << " ";
		s.push(arr[i]);

	}

}

// arr = 10 15 20 25  => 25 20 15 10 
// op = 15 20 25 -1   => -1 25 20 15 

vector<int> next_greater(int arr[], int n){
	stack<int > s;
	vector<int > V;
	s.push(arr[n-1]);

	for(int i = n-2; i>=0; i--){
		while(s.empty() == false and s.top()<= arr[i]){
			s.pop();
		}
		int ans = s.empty()?-1:s.top();
		// cout << ans << " ";
		V.push_back(ans);

		s.push(arr[i]);
	}
	reverse(V.begin(), V.end());
	return V;
	// print output in reverse order 
}

int main(int argc, char const *argv[])
{
	/* code */

	int arr[] = {15, 10, 18, 12, 4, 6 ,2, 8};
	vector<int > v;
	int n = sizeof(arr) / sizeof(int);

	prev_greater(arr, n);
	cout << endl;
	v = next_greater(arr, n);
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " "; 
	}
	return 0;
}
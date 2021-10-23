// Stock Span Problem

#include <iostream>
#include <stack>
using namespace std;

void printSpan(int arr[], int n){
	for(int i=0; i<n; i++){
		int span = 1;
		for(int j=i-1; j=0 and arr[j] <= arr[i]; j--){
			span++;
		}
		cout << span <<  " ";
	}
}

// Efficient solution - O(N)

void print_Span(int arr[], int n){
	stack <int > s;
	s.push(0);
	cout << 1 << " ";

	for(int i=1; i<n; i++){
		while(s.empty() == false and arr[s.top()] <= arr[i]){
			s.pop();
		}
		int span = s.empty()?i+1:i-s.top();
		cout << span << " ";
		s.push(i); 
	}
}


int main(int argc, char const *argv[])
{
	int arr[] = {60, 10, 20, 15, 35, 50};
	int n = sizeof(arr)/ sizeof(int);

	print_Span(arr, n);

	return 0;
}
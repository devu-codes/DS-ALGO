// More than n/k occurence 

#include <iostream>
#include <unordered_map>

using namespace std; 

void printEle(int arr[], int n, int k){
	int x = n/k;
	unordered_map <int, int > HashMap;

	for(int i=0; i<n; i++){
		HashMap[arr[i]]++;
	}


	for(auto it : HashMap){
		if(it.second > x){
			cout << it.first << " ";
		}
	}

}

int main(int argc, char const *argv[])
{
	/* code */
	int arr[]=  {10,10,10,10,2,2,2,3,3,3,4,5};
	int n = sizeof(arr) / sizeof(int);
	int k = 2;

	printEle(arr, n, k);
	return 0;
}
// Frequencies of Array Elements

# include <iostream>
# include <unordered_map>
using namespace std;


 // Efficient Solution

void freq(int arr[], int n){
	unordered_map<int, int > HashMap;
	for(int x=0; x < n; x++){
		HashMap[arr[x]]++;
	}
	for(auto e: HashMap){
		cout << e.first << " " << e.second << endl; 
	}
}

int main(int argc, char const *argv[])
{
		
	int arr[] = {1,1,2,2,3,4,1,2,3,4,2,1};
	int n = sizeof(arr)/sizeof(int);

	freq(arr, n);

	return 0;
}
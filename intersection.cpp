
#include <iostream> 
#include <set>

using namespace std;

// Instersection
void printIntersection(int arr1[], int arr2[], int n1, int n2){
	set <int> HashSet;
	
	for(int i=0; i<n1; ++i){
		HashSet.insert(arr1[i]);
	}

	for(int i=0; i<n2; i++){
		if(HashSet.find(arr2[i]) != HashSet.end()){
			cout << arr2[i] <<  " "; 
		}
	}
	cout << endl;
}
// When array elements is not distinct
// both array must be sorted 
void intersection(int arr1[], int arr2[], int n1, int n2){
	int i = 0, j=0; 
	while (i < n1 and j < n2) {
		if (arr1[i] > arr2[j]){
			j++;
		}
		else if(arr2[j] > arr1[i])
			i++;
		else {
			cout << arr1[1] << " ";
			i++;
			j++;
		}
	}
}


// Union 
// void printUnion(int arr1[], int arr2[], int n1, int n2){
// 	set <int> HashSet;

// 	for(int i=0; i<n1; ++i){
// 		HashSet.insert(arr1[i]);
// 	}
// 	for(int i=0; i<n2; i++){
// 		HashSet.insert(arr2[i]);
// 	}

// 	for(auto x : HashSet){
// 		cout << x << " ";
// 	}
// 	cout << endl;
// }

int main(int argc, char const *argv[])
{
	int arr1[] = {1,2,2,3,3,4,4,5,5,6,6};
	int arr2[] = {4,5,5,6,6,7,7,8,8,9,9};

	int n1 = sizeof(arr1)/sizeof(int);
	int n2 = sizeof(arr2)/ sizeof(int);

	// printUnion(arr1, arr2, n1, n2);
	printIntersection(arr1, arr2, n1, n2);
 	
	return 0;
}
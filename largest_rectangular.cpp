// Largest Rectangular Area 
#include <iostream>
#include <stack>

using namespace std;

int getMaxArea(int ar[], int n){
	int ans = 0;
	for(int i= 0; i<n; i++){
		int curr = ar[i];
		for(int j = i-1; j>=0; j--){
			if(ar[j] >= ar[i])
				curr += ar[i];
			else
				break;
		}
		for(int j= i+1; j<n; j++){
			if(ar[j] >= ar[i])
				curr += ar[i];
			else 
				break;
		}
		ans = max(ans, curr);
	}
	return ans;
}


int main(int argc, char const *argv[])
{
	int ar[] = {6, 2, 5, 4, 1, 5, 6};
	int n = sizeof(ar)/ sizeof(int);

	cout << getMaxArea(ar, n);

	return 0;
}

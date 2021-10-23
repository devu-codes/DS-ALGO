// Genrate number with given digits 

//  5 6 55 56 65 66
#include <iostream>
#include <queue>
#include <string> 
using namespace std;


// Efficient solution - O(N)

void printFirst(int n){
	queue<string> q;
	q.push("5");
	q.push("6");

	for(int i=0; i<n; i++){
		string curr = q.front();
		cout << curr << " ";
		q.pop();
		q.push(curr + "5");
		q.push(curr + "6");

	}

}


int main(int argc, char const *argv[])
{

	printFirst(5);
	
	return 0;
}
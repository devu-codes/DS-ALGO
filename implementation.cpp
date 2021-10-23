// operation 
/* 
	Enqueue 
	Dequeue
	size 
	getfront 
	getrear
	isFull
	isEmpty
*/

// #include <iostream>

// using namespace std;

// struct Queue{
// 	int *arr, size, cap;
// 	Queue(int c){
// 		cap = c;
// 		arr = new int[cap];
// 		size = 0;
// 	}
// 	bool isFull(){
// 		return (size == cap);
// 	}
// 	bool isEmpty(){
// 		return size == 0;
// 	}

// 	void enqueue(int x){
// 		if(isFull())
// 			return;
// 		arr[size] = x;
// 		size++;
// 	}
// 	void dequeue(){
// 		if(isEmpty())
// 			return;
// 		for(int i=0; i<n; i++){
// 			arr[i] = arr[i+1];
// 		}
// 		size--; 
// 	}
// }


// implement C++ STL 
// FIFO 

#include <iostream>
#include <queue>

using namespace std; 

int main(int argc, char const *argv[])
{
		
	queue<int > q; 
	q.push(10);
	q.push(20);
	q.push(30);

	// cout << q.front() << "  " << q.back() << endl;
	// q.pop();
	// cout << q.front() << "  " << q.back() << endl;

	while(!q.empty()){
		cout << q.front() << " " << q.back() <<  endl;
		q.pop();
	}


	return 0;
}


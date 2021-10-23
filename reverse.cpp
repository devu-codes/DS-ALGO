// Reverse a queue 
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverse(queue<int> &q){

	stack <int> s;
	while(!q.empty()){
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
	
	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
	}
}

// Recursive
void Reverse(queue<int > &q){
	if(q.empty()){
		return;
	}

	int x= q.front();
	q.pop();
	reverse(q);
	q.push(x);

}


int main(int argc, char const *argv[])
{
	queue <int> q;
	q.push(1);
	q.push(2);
	q.push(3);

	reverse(q);	

	

	return 0;
}
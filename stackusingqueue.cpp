#include <iostream>
#include <queue>

using namespace std;

struct stack{

	queue <int > q1, q2;

	int top(){
		return q1.front();
	}
	int size(){
		return q1.size();
	}
	int pop(){
		return q1.front();
	}

	void push(int x){
		while(!q1.empty()) {
			int items = q1.pop();
			q2.push(items);
		}
		q1.push(x);
		while(!q2.empty()){
			int items = q2.pop();
			q1.push(items);
		}
	}

};
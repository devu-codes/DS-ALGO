// Introduction to stack

#include <iostream>
#include <vector>
using namespace std;

struct MyStack
{
	int *arr;
	int cap; 
	int top;
	MyStack(int c){
		cap = c;
		arr = new int[cap];
		top = -1;
	}
	void push(int x){
		top++;
		arr[top] = x;
	}
	int pop(){
		int res = arr[top];
		top--;
		return res;
	}
	int peek(){
		return arr[top];
	}
	int size(){
		return (top+1);
	}
	bool isEmpty(){
		return (top == -1);
	}

};

struct myStack{
	vector <int> V;
	void push(int x){
		V.push_back(int x);
	}
	int pop(){
		int res = V.back();
		V.pop_back();
		return res;
	}
	int size(){
		return V.size();
	}
	bool isEmpty(){
		return v.empty();
	}
};

int main(int argc, char const *argv[])
{
	MyStack st(5);
	st.push(5);
	st.push(10);
	st.push(20);
	cout << st.pop() << endl;

	cout << st.size() << endl;
	cout << st.peek() << endl;
	cout << st.isEmpty() << endl;

	return 0;
}
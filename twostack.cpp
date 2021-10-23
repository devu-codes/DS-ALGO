// Two stacks in array 

// top1->  2 3 4 5 6 7 8 9  <-top2


#include <iostream>
#include <stack>
#include <climits>

using namespace std;

struct TwoStack
{
	int *arr, cap, top1, top2;
	TwoStack(int n){
		cap = n;
		top1 = -1;
		top2 = cap;
		arr = new int[n];
	} 
	void push1(int x){
		if(top1<top2-1){
			top1++;
			arr[top1] = x;
		}
	}
	void push2(int x){
		if(top1<top2-1){
			top2--;
			arr[top2]= x;
		}
	}
	int pop1(){
		if(top1>=0){
			int x = arr[top1];
			top1--;
			return x;
		}
	}
	int pop2(){
		if(top2 < cap){
			int x = arr[top2];
			top2++;
			return x;
		}
		return INT_MAX;

	}
};



int main(int argc, char const *argv[])
{
	TwoStack s(5);
	s.push1(10);
	s.push2(20);
	s.push1(1);
	s.push2(2);

	cout << s.pop2() << endl;


	return 0;
}
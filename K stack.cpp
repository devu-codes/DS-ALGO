// Implement K stacks in an array 

#include <iostream>
#include <stack>

using namespace std;
// K stack

/*
	push(value, stack number)
	pop(stack number)
	isempty(stack number)
	size (stack number)
	top(stack number)
*/

struct K_stack
{
	int *arr, *top, *next;
	int k, freeTop, cap;
	K_stack(int k1, int n){
		k = k1;
		cap = n;
		arr = new int[cap];
		top = new int[k];
		next = new int[cap];
		for(int i=0; i<k; i++){
			top[i] = -1;
		}
		freeTop = 0;
		for(int i=0; i<cap-1; i++){
			next[i] = i+1;
		}
		next[cap-1] = -1;
	}
 };


int main(int argc, char const *argv[])
{
	
	

	return 0;
}
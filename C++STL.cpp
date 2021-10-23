// Stack in C++ STL 

#include <iostream>
#include <stack>

using namespace std; 

int main(int argc, char const *argv[])
{
	stack<int > s;
	s.push(10);
	s.push(20);
	s.push(30);

	cout << s.size() << endl;
	cout << s.top() << endl;
	// s.pop();
	// cout << s.top() << endl;

	while(!s.empty()){
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}
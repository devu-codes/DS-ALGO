// Balance paranthesis 

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// bool is_balance(string &s){
// 	stack<char> S;
// 	for(int i=0; i<s.length(); i++){
// 		if(s[i] == '(' )
// 			S.push(s[i]);
// 		if(s[i] == ')')
// 			S.pop();
// 	}
// 	if(S.empty())
// 		return true;
// 	return false;
// }


// Mathcing functions for balancing 
bool matching(char a, char b){
	return ((a=='(' and b ==')')
			or (a=='{' and b =='}')
			or (a=='[' and b ==']'));
}

bool isBalanced(string str){
	stack<char > st;
	for(int i=0; i<str.length(); i++){
		if(str[i]=='(' or str[i] == '{' or str[i] =='[')
			st.push(str[i]);
		else{
			if(st.empty())
				return false;
			else if (matching(st.top(), str[i])== false)
				return false;
			else 
				st.pop();
		}
	}
	return (st.empty() == true);
}



int main(int argc, char const *argv[])
{
	
	string s = "{{}}((()))";
	cout << isBalanced(s);

	return 0;
}
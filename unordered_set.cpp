
// C++ STL

// set is a self balancing tree - Red Black Tree 
// unordered_set is hashing

// functions - 
// insert()
// begin(), end()
// size()
// clear()
// find()

// Applications - 
// 	search, insert, delete  O(1)

#include <iostream>
#include <unordered_set>

using namespace std; 

int main(int argc, char const *argv[])
{
	unordered_set<int> s;
	s.insert(10);
	s.insert(5);
	s.insert(15);
	s.insert(20);

	// find element
	if(s.find(15) == s.end()){
		cout << "Not Found";
	}else{
		cout << "Found" << *(s.find(15));
	}

	// count 
	if(s.count(15)){
		cout << "Found";
	}else{
		cout << "Not Found";
	}
	cout << endl;

	// erase 

	s.erase(s.begin(), s.end());

	cout << s.size() << " ";
	s.erase(15);
	cout << endl;
	cout << s.size() << " ";
	auto it = s.find(10);
	s.erase(it);
	cout << s.size()<< endl;

	// loop
	for(int x:s)
		cout << x << " ";
	cout << endl;
	for(auto it = s.begin(); it != s.end(); it++){
		cout << (*it) << " ";
	}

	// size 
	cout << endl;
	cout << s.size() << " ";
	cout << endl;
	s.clear();
	cout << s.size()<< " ";

	return 0;
}
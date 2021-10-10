/*
Unordered Map C++ STL
  - Used to store key, value pair
  - uses Hashing 
  - No order of keys

Time compexities -

begin(), end(), size(), empty() - O(1) in worst 

count(), find(), erase(key), insert(), [], at - O(1) average 


 */ 
#include <iostream>
#include <unordered_map>

using namespace std;

// int main(int argc, char const *argv[])
// {
// 	unordered_map<string, int > HashMap;
// 	HashMap["gfg"] = 20;
// 	HashMap["ide"] = 30;
// 	HashMap.insert({"courses", 15});

// 	for(auto x : HashMap){
// 		cout << x.first << " " << x.second << endl;
// 	}

// 	return 0;
// }

// Another method 

int main(int argc, char const *argv[])
{
	unordered_map <string, int > HashMap;
	HashMap["gfg"] = 10;
	HashMap["ide"] = 15;
	HashMap["courses"] = 30;

	// find key
	if(HashMap.find("gfg") != HashMap.end()){
		cout << "Found";
	}else{
		cout << "Not Found";
	}
	cout << endl;

	// find corresponding value if key is found
	auto it = HashMap.find("ide");
	if(it != HashMap.end())
		cout << (it->second) << " ";
	cout << endl;
	// iterate
	for(auto it = HashMap.begin(); it != HashMap.end(); ++it){
		cout << (it->first) << " " << (it->second) << endl;
	}

	// Count function
	if(HashMap.count("courses") > 0)
		cout << "Found";
	else
		cout << "Not Found";

	// size and erase function
	cout << HashMap.size() << " ";
	HashMap.erase("ide");
	HashMap.erase(HashMap.begin(), HashMap.end());
	cout << HashMap.size() << endl;

	return 0;
}
// map STL 

#include <iostream>
#include <map>
#include <string>
// sorted data
using namespace std;

int main(int argc, char const *argv[])
{
	
	// map<int, int > m;
	// m.insert({10, 20});
	// m[5] = 100;
	// m.insert({3, 300});
	// m.insert({3, 400});

	// // for each 
	// for(auto &x: m)
	// 	cout << x.first << " " << x.second << endl;


	// cout << m.size() << " ";
	// cout << endl;
	// cout << m[20] << " ";
	// cout << endl;
	// cout << m.size() << " ";
	// cout << endl;

	// // if key not present, then it'll throw range out of exception
	// // m.at(210) = 300;

	// for(std::map<int, int>::iterator it = m.begin(); it != m.end(); it++){
	// 	cout << (*it).first << " " << (*it).second << endl;
	// }
	// m.clear

	// more functions
	std::map<int, string> map;
	map.insert({5, "gfg"});
	map.insert({2, "ide"});
	map.insert({1, "practice"});

	// find 
	if(map.find(1) != map.end()){
		cout << "Found" << endl;
	}
	else 
		cout << "Not Found" << endl;

	for(auto it=map.find(2); it!=map.end(); it++)
		cout << (*it).first << " " <<(*it).second << "\n"; 

	// cout << m.size();
	// for(auto it=map.find(2); it!=map.end(); it++){
	// 	cout << (*it).first << " " << (*it).second <<"\n";
	// }

	auto it = map.lower_bound(2);
	if(it!=map.end())
		cout << (*it).first;
	else
		cout << "No ";
	map.erase(5);
	map.erase(m.find(2), m.end());

	cout << m.size() << " ";
	return 0;
}
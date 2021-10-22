# include <iostream>
# include <set>

using namespace std;

int main(){
	set<int, greater<int > > s;
	s.insert(10);
	s.insert(5);
	s.insert(20);
	s.insert(10);
	s.insert(5);
	for(auto it = s.begin(); it != s.end(); it++){
		cout << (*it) << " ";
	} 
	cout << endl;
	// reverse iterator 
	for(auto it = s.rbegin(); it!=s.rend(); it++){
		cout << (*it) << " ";
	}
	cout << endl;

	for(int x:s)
		cout << x << " ";


	// find 
	auto it = s.find(10);
	if(it == s.end())
		cout << "Not Found\n";
	else
		cout << "Found\n";

	while(it!=s.end()){
		// cout << *it << " ";
	}
	// clear 
	s.clear();
	cout << s.size();

	// count 
	if(s.count(10))
		cout << "Found";
	else 
		cout << "Not found";

	// erase 
	auto it = s.find(7);
	s.erase(it);
	s.erase(it, s.end());

	// lower bound 
	auto it = s.lower_bound(5);
	if(it!=s.end())
		cout << (*it) << endl;
	else 
		cout << "Given element is greater than largest";

	auto it = s.upper_bound(25);
	if(it != s.end())
		cout << (*it) << " ";
	else 
		cout << "Given element is greater than the largest ";

	return 0;
}
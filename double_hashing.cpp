

/*
void doubleHashingInsert(key)
{
	if(table is full)
		return error
	probe = h1(key), offset = h2(key)

	while(table[probe] is occupied)
		probe = (probe + offfset) % m
	table[probe] = m
}

Implementaiton of Open Addressing 

*/

#include <iostream>
using namespace std;

struct MyHash {
	int *arr;
	int cap, size;
	MyHash(int c){
		cap = c;
		size = 0;
		for(int i=0; i<cap; ++i){
			arr[i] = -1;
		}
	}
	// Hash Fn
	int hash(int key){
		return key % cap;
	}
	// search 
	bool search(int key){
		int h = hash(key);
		int i = h;
		while(arr[i] != -1){
			if(arr[i] == key){
				return true;
			}
			i = (i+1)%cap;
			if(i==h){
				return false;
			}
		} 
		return false;
	}
	// insert
	bool insert(int key){
		if(size == cap)
			return false;
		int i = hash(key);
		while(arr[i] != -1 and arr[i] != -2 and arr[i] != key){
			i = (i+1)%cap;	
		}
		if(arr[i] == key)
			return false;
		else{
			arr[i] = key;
			size++;
			return true;
		}
	}
	// erase 
	bool erase(int key){
		int h = hash(key);
		int i = h;
		while(arr[i] != -1){
			if(arr[i] == key){
				arr[i] = -2;
				return true;
			}
			i = (i+1)%cap;
			if(i == h)
				return false;
		}
		return false;
	}
}
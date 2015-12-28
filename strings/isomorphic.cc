/*
Find if two strings are iso-morphic. 
Two words are called isomorphic if the letters in one word 
can be remapped to get the second word. Remapping a letter 
means replacing all occurrences of it with another letter. 
The ordering of the letters remains unchanged. No two letters 
may map to the same letter, but a letter may map to itself.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1("hello"), s2("bbffa");
	int l1 = s1.length();
	int l2 = s2.length();
	int i;

	if (l1 != l2) {
		cout << "Strings are not isomorphic " << endl;
		return -1;
	}

	char map[256];
	bool marked[256];
	memset(map, 0, 256);
	
	for (i = 0; i < 256; i++) {
		marked[i] = false;
	}

	string::iterator it1, it2;
	for (it1 = s1.begin(), it2 = s2.begin(); it1 != s1.end(); it1++, it2++) {
		char c1 = *it1;
		char c2 = *it2;
		if (map[c1 - 'A'] == 0) {
			if (marked[c2 - 'A'] == true) {
				/* 'ab' , 'cc' - When processing for
				b, map['b'] wil be 0, but 'c' is already
				mapped to a. Hence 'b' cannot be mapped
				to a
				*/
				cout << "Not isomorphic" << endl;
				return -1;
			}
			map[c1 - 'A'] = c2;
			marked[c2 - 'A'] = true;	
		} else {
			if (map[c1 - 'A'] != c2) {
				/* 'aa' , 'bc' - A was mapped to 'a'.
				In the next lopp, map[a] != 0, but
				equal to b. Now, for the second 'a',
				map[a] will be be c which is different
				from thr previous mapping.
				*/
				cout << "Strings are not isomorphic" << endl;
				return -1;
			}
		}
	}
	cout << "Strings are isomorphic" << endl;
	return 0;
}

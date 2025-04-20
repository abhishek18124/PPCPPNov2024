#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<set>
#include<unordered_set>

using namespace std;

// time : on. avg. O(n)

bool isDuplicatePresent(const vector<int>& v) {

	unordered_map<int, int> freqMap;
	for (int x : v) {
		freqMap[x]++;
		if (freqMap[x] > 1) {
			// you've found a duplicate
			return true;
		}
	}

	// no duplicates found
	return false;

	// for (pair<int, int> p : freqMap) {
	// 	cout << p.first << " " << p.second << endl;
	// }

}

// time : worst case O(n.logn)

bool isDuplicatePresent2(const vector<int>& v) {

	map<int, int> freqMap;
	for (int x : v) {
		freqMap[x]++;
		if (freqMap[x] > 1) {
			// you've found a duplicate
			return true;
		}
	}

	// no duplicates found
	return false;

	// for (pair<int, int> p : freqMap) {
	// 	cout << p.first << " " << p.second << endl;
	// }

}

// time : worst case O(n.logn)

bool isDuplicatePresent3(const vector<int>& v) {

	set<int> s;
	for (int x : v) {
		if (s.find(x) != s.end()) {
			// x is already present in the set<>
			// therefore you've found duplicates
			return true;
		} else {
			s.insert(x);
		}
	}

	// no duplicates found
	return false;
}

// time : on avg O(n)

bool isDuplicatePresent4(const vector<int>& v) {

	unordered_set<int> s;
	for (int x : v) {
		if (s.find(x) != s.end()) {
			// x is already present in the set<>
			// therefore you've found duplicates
			return true;
		} else {
			s.insert(x);
		}
	}

	// no duplicates found
	return false;

}

int main() {

	vector<int> v = {1, 2, 3};

	isDuplicatePresent(v) ? cout << "true" << endl :
	                             cout << "false" << endl;

	isDuplicatePresent2(v) ? cout << "true" << endl :
	                              cout << "false" << endl;

	isDuplicatePresent3(v) ? cout << "true" << endl :
	                              cout << "false" << endl;

	isDuplicatePresent4(v) ? cout << "true" << endl :
	                              cout << "false" << endl;


	return 0;
}
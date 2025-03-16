/*

	https://cplusplus.com/reference/set/set/?kw=set
	https://cplusplus.com/reference/set/multiset/?kw=multiset

	> insert/erase/find is logarithmic i.e. O(logn)
	> values are inserted in the sorted order
	> set contains only distinct values
	> multiset allows duplicate values

*/

#include<iostream>
#include<set>

using namespace std;

int main() {

	set<int> s; // use multiset<int> s; if you want to store duplicates

	// use set<int, greater<int>> s; if you want to data be present in dec. order
	// you can also create custom compartor

	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(1); // no effect since 1 is already present in the set<>

	cout << "size : " << s.size() << endl; // 5 {1, 2, 3, 4, 5}

	s.erase(5);

	cout << "size : " << s.size() << endl; // 4 {1, 2, 3, 4}

	for (auto it = s.begin(), end = s.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	cout << *s.begin() << endl;

	for (auto x : s) {
		cout << x << " ";
	}

	cout << endl;

	// auto it = s.begin();
	// it++;
	// s.erase(it);

	s.erase(s.begin()); // make sure iterator passed to erase is valid otherwise it will lead to error

	if (s.find(1) != s.end()) {
		cout << "1 is present" << endl;
	} else {
		cout << "1 is absent" << endl;
	}

	for (auto x : s) {
		cout << x << " ";
	}

	cout << endl;

	if (s.find(3) != s.end()) {
		cout << "3 is present" << endl;
	} else {
		cout << "3 is absent" << endl;
	}

	if (s.find(5) != s.end()) {
		cout << "5 is present" << endl;
	} else {
		cout << "5 is absent" << endl;
	}

	if (s.count(3)) {
		cout << "3 is present" << endl;
	} else {
		cout << "3 is absent" << endl;
	}

	if (s.count(5)) {
		cout << "5 is present" << endl;
	} else {
		cout << "5 is absent" << endl;
	}

	s.empty() ? cout << "empty" << endl : cout << "non-empty" << endl;

	s.clear();

	cout << "size : " << s.size() << endl;

	s.empty() ? cout << "empty" << endl : cout << "non-empty" << endl;

	return 0;
}
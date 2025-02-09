#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1 = "def";
	string s2 = "def";

	if (s1 == s2) {
		cout << s1 << " is equal to " << s2 << endl;
	} else if (s1 > s2) {
		cout << s1 << " > " << s2 << endl;
	} else {
		cout << s1 << " < " << s2 << endl;
	}

	string s4 = "azc";
	string s5 = "zbc";

	cout << s4.compare(s5) << endl;

	return 0;
}
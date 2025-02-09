#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abcdef";

	string ss = s.substr(2, 3);
	cout << ss << endl;

	cout << s.substr(1, 4) << endl;

	cout << s.substr(3) << endl; // 2nd arg. is optional

	// cout << s.substr(2, 10) << endl;

	return 0;
}
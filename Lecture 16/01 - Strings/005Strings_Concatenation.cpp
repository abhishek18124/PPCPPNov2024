#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1 = "abc";
	string s2 = "def";

	cout << s1 + s2 << endl;

	string s3 = s1 + s2;
	cout << s3 << endl;

	string s4 = "abc";
	s4.push_back('d');
	cout << s4 << endl;

	s4.pop_back();
	cout << s4 << endl;

	string s5 = "xyz";
	s5 = s5 + "abc"; // s5.append("abc");
	cout << s5 << endl;

	string s6 = "hello";
	cout << s6.back() << endl;
	cout << s6[0] << endl;
	cout << s6.front() << endl;

	return 0;
}
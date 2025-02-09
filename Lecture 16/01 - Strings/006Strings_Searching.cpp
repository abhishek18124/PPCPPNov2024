#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abcabcdefabcdefabc";

	cout << s.find("abcdef") << endl;
	cout << s.rfind("abcdef") << endl;

	cout << s.find("xyz") << endl;
	cout << string::npos << endl;

	return 0;
}
#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1 = "abc";
	cout << s1 << endl;

	string s2 = s1; // creates a copy of s1
	cout << s2 << endl;

	s2[0] = 'd';

	cout << s2 << endl;
	cout << s1 << endl;

	string& s3 = s1; // s3 is a reference i.e. new name for s1
	cout << s3 << endl; // abc

	s3[0] = 'x';

	cout << s3 << endl; // xbc
	cout << s1 << endl; // xbc

	string s4;
	s4 = s1; // creates a copy of s1


	return 0;
}
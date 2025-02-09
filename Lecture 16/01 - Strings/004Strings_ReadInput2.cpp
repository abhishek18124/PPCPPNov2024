#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main() {

	string str;
	getline(cin >> ws, str);
	// ws is an input manip. that can be used to ignore leading whitespaces
	cout << str << endl;

	return 0;
}
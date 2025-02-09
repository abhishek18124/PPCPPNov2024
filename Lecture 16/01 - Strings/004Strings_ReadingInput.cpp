#include<iostream>
#include<string>

using namespace std;

int main() {

	string str;
	// cin >> str;
	getline(cin, str);

	cout << str << endl;

	string str2;
	getline(cin, str2, '$');
	cout << str2 << endl;

	return 0;
}
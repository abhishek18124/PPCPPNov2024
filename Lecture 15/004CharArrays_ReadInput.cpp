// n <= 100

#include<iostream>

using namespace std;

int main() {

	char str[101]; // based on constraints

	cin >> str; // cin >> it ignores leading whitespaces

	cout << str << endl;

	char str2[101];

	cin >> str2; // cin >> stops reading i/p as soon as it encounters a non-leading whitespace

	cout << str2 << endl;

	return 0;
}
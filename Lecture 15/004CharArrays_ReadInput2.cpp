// n <= 100

#include<iostream>

using namespace std;

int main() {

	// char str[101]; // based on constraints

	// cin.getline(str, 101); // cin.getline() doesn't ignore leading whitespaces and it doesn't stop when you encounter non-leading whitespace

	// cin.getline(str, 101, '$'); // cin.getline() doesn't ignore leading whitespaces and it doesn't stop when you encounter non-leading whitespace

	// cout << str << endl; // '$' delimiting char

	char str2[101]; // based on constraints

	cin.getline(str2, 5, '$'); // '\n' is the default delimiting char.

	cout << str2 << endl;

	return 0;
}
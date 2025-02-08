#include<iostream>

using namespace std;

int main() {

	char str[] = {'a', 'b', 'c', 'd', 'e', '\0'};
	cout << str << endl;

	for (int i = 0; str[i] != '\0'; i++) {
		cout << str[i] << " ";
	}
	cout << endl;

	char str2[] = "coding"; // '\0' is added automatically when you init a string using a string literal

	cout << str2 << endl;

	for (int i = 0; str2[i] != '\0'; i++) {
		cout << str2[i] << " ";
	}
	cout << endl;

	return 0;
}
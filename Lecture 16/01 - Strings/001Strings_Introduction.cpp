#include<iostream>
#include<string>

using namespace std;

int main() {

	string str;

	str = "hello"; // '\0' is added automatically at the end of the string

	cout << str << endl;

	for (int i = 0; str[i] != '\0'; i++) {
		cout << str[i] << endl;
	}

	return 0;
}
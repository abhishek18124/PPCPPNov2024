#include<iostream>

using namespace std;

int stringToInteger(string str, int n) {

	// base case

	if (str == "") { // n == 0 // str.empty()
		return 0;
	}

	// recursive case

	string subString = str.substr(0, n - 1);
	int integerFromMyFriend = stringToInteger(subString, n - 1);
	int lastDigit = str[n - 1] - '0';
	return integerFromMyFriend * 10 + lastDigit;

}

int main() {

	string str = "12345";
	int n = str.size();

	cout << stringToInteger(str, n) << endl;

	return 0;
}
#include<iostream>
#include<string>

using namespace std;

bool isGoodString(string str) {

	// for (int i = 0; str[i] != '\0'; i++) {
	// 	char ch = str[i];
	// 	if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
	// 		// ch is consonant, not a vowel therefore str is not good string
	// 		return false;
	// 	}
	// }

	// return true;


	for (char ch : str) {
		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// ch is consonant, not a vowel therefore str is not good string
			return false;
		}
	}

	return true;

}

int main() {

	string str = "uoxea";

	isGoodString(str) ? cout << "good" << endl : cout << "not good" << endl;

	return 0;

}
#include<iostream>
#include<string>

using namespace std;

bool isGoodString(string str) { // time : O(n)

	for (char ch : str) {
		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// ch is consonant, not a vowel therefore str is not good string
			return false;
		}
	}

	return true;

}

// time : O(n^3)

int longestGoodSubstring(string str) {

	int maxSoFar = 0;
	int n = str.size();

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			string subString = str.substr(i, j - i + 1);
			if (isGoodString(subString)) {
				maxSoFar = max(maxSoFar, j - i + 1);
			}
		}
	}

	return maxSoFar;

}

int main() {

	string str = "cbaeicdeiou";

	cout << longestGoodSubstring(str) << endl;

	return 0;
}
#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(string str) { // time : O(n)

	int i = 0;
	int j = str.size() - 1;

	while (i < j) {

		if (str[i] != str[j]) {
			// str is not a palindrome
			return false;
		}

		i++;
		j--;

	}

	// str is a palindrome
	return true;

}

// time : O(n^3)

int countPalindromicSubstrings(string s) {

	int cnt = 0; // to track the no. of palindromic substrings in the given string
	int n = s.size();

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			string subString = s.substr(i, j - i + 1);
			if (isPalindrome(subString)) {
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {

	string s = "abaaba";

	cout << countPalindromicSubstrings(s) << endl;

	return 0;
}
#include<iostream>
#include<string>

using namespace std;

int countPalindromicSubstrings(string s) {

	int cnt = 0; // to track the no. of palindromic substrings in the given string
	int n = s.size();

	// 1. find out no. of odd len palindromic substrings

	for (int i = 0; i < n; i++) {

		// find out no. of odd len palindromic substring with s[i] as the center

		int j = 0;
		while (i - j >= 0 and i + j <= n - 1 and s[i - j] == s[i + j]) {
			cnt++;
			j++;
		}

	}

	// 2. find out no. of even len palindromic substrings

	for (double i = 0.5; i < n; i++) {

		// find out no. of odd len palindromic substring with s[i] as the center

		double j = 0.5;

		while (i - j >= 0 and i + j <= n - 1 and s[(int)(i - j)] == s[(int)(i + j)]) {
			cnt++;
			j++;
		}

	}

	return cnt;

}

int main() {

	string s = "abaaba";

	cout << countPalindromicSubstrings(s) << endl;

	return 0;
}
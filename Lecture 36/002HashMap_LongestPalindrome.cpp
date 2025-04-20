#include<iostream>
#include<vector>
#include<set>

using namespace std;

// time : O(nlogn)
// space: O(n) to set<>

int longestPalindrome(const string& str) {

	int ans = 0; // to track the length of the longest palindrome we can form using char. of str
	set<char> s;

	for (char ch : str) {

		if (s.find(ch) != s.end()) {
			ans += 2;
			s.erase(ch);
		} else {
			s.insert(ch);
		}

	}

	if (s.size() > 0) {
		ans++;
	}

	return ans;

}

int main() {

	string str = "abccccdd";

	cout << longestPalindrome(str) << endl;

	return 0;
}
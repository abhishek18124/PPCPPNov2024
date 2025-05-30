#include<iostream>
#include<cstring>

using namespace std;

bool isPalindrome(char str[]) {

	int i = 0;
	int j = strlen(str) - 1;

	while (i < j) {

		if (str[i] != str[j]) {
			// str[] is not a palindrome
			return false;
		}

		i++;
		j--;

	}

	// str[] is a palindrome
	return true;

}

int main() {

	char str[] = "racecar";

	isPalindrome(str) ? cout << "palindrome" << endl : cout << "not palindrome" << endl;

	return 0;
}
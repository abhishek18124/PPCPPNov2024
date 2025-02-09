#include<iostream>
#include<string>

using namespace std;

void generateSubstrings(string str, int n) {

	for (int i = 0; i < n; i++) {

		for (int j = i; j < n; j++) {

			// extract the substring of str
			// that starts at index i
			// & ends at index j

			cout << str.substr(i, j - i + 1) << endl;

		}

		cout << endl;

	}

}

int main() {

	string str = "abcde";
	int n = str.size();

	generateSubstrings(str, n);

	return 0;
}
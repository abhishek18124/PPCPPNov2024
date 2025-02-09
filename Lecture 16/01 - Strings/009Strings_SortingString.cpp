#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b otherwise return false

bool comp(char a, char b) {

	// if (a > b) {
	// 	return true;
	// }

	// return false;

	return a > b;

}

int main() {

	string s = "xabzc";

	sort(s.begin(), s.end());

	cout << s << endl;

	string t = "axbcz";

	// sort(t.rbegin(), t.rend());
	// sort(t.begin(), t.end(), greater<char>());
	sort(t.begin(), t.end(), comp);

	cout << t << endl;

	return 0;
}
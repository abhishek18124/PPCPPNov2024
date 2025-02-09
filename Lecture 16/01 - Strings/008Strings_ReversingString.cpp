#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	string s = "abc";

	reverse(s.begin(), s.end());

	cout << s << endl;

	string t = "wxyz";

	reverse(t.begin() + 1, t.begin() + 3); // [1, 3)

	cout << t << endl;

	return 0;
}
#include<iostream>

using namespace std;

bool isEven(int n) {
	return n % 2 == 0;
}

int main() {

	// a fn call that returns a value can be treated like an expr

	bool ans = isEven(2);
	cout << ans << endl;

	cout << isEven(5) << endl;

	if (isEven(6)) {
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}

	isEven(7) ? cout << "even" << endl : cout << "odd" << endl;

	return 0;

}
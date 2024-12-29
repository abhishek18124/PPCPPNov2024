#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 1, j = n; i < j; i++, j--) { // if you declare multiple loop variables then their type should be same
		cout << i << " " << j << endl;
	}

	return 0;

}
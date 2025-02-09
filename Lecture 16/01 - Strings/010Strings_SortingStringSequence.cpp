#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b

bool lengthCmp(string a, string b) {

	if (a.size() < b.size()) {
		return true;
	}

	return false;

}

int main() {

	string arr[] = {"abc", "z", "cd", "aaaa"};
	int n = 4;

	sort(arr, arr + n); // lexicographically inc. order

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	sort(arr, arr + n, lengthCmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}
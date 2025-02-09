// strlen <= 100

#include<iostream>
#include<cstring>

using namespace std;

int main() {

	int n;
	cin >> n;

	char inp[101]; // based on constraints
	cin >> inp;

	char msf[101]; // based on constraints, to track lexicographically largest string
	strcpy(msf, inp);

	for (int i = 1; i <= n - 1; i++) {
		cin >> inp;
		if (strcmp(inp, msf) > 0) {
			strcpy(msf, inp);
		}
	}

	cout << msf << endl;

	return 0;
}
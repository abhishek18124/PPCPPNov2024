// n <= 8

#include<iostream>

using namespace std;

void f(char out[], int n, int i, int oc, int cc) {
	// base case
	if (i == 2 * n) { // oc == n and cc == n
		out[i] = '\0';
		cout << out << endl;
		return;
	}

	// recursive case

	// f(i, oc, cc) : take decisions for the remaining positions
	// from i to 2n-1 such that so far we've used oc open brackets
	// cc close brackets

	// decide for ith pos

	// option 1 : use '('
	if (oc < n) {
		out[i] = '(';
		f(out, n, i + 1, oc + 1, cc);
	}

	// option 2 : use ')'
	if (cc < oc) {
		out[i] = ')';
		f(out, n, i + 1, oc, cc + 1);
	}

}

int main() {

	int n = 3;

	char out[17]; // based on constraints

	f(out, n, 0, 0, 0);

	return 0;
}
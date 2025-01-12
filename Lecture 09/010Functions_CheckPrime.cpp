#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n) {

	int rn = sqrt(n);

	for (int i = 2; i <= rn; i++) { // to optimise iterate from 2 to sqrt(n)
		if (n % i == 0) {
			// n is not a prime no.
			return false;
		}
	}

	// n is a prime
	return true;

}

int main() {

	int n;
	cin >> n;

	isPrime(n) ? cout << "prime" << endl : cout << "not prime" << endl;

	if (isPrime(n)) {
		cout << "prime" << endl;
	} else {
		cout << "not prime" << endl;
	}

	bool res = isPrime(n);

	if (res) {
		cout << "prime" << endl;
	} else {
		cout << "not prime" << endl;
	}

	return 0;
}
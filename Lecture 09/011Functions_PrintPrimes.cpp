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

// readabilty
// modularity
// resusability

void printPrimes(int m) {

	for (int n = 2; n <= m; n++) {

		// check if n is a prime no. or not

		if (isPrime(n)) {
			cout << n << " ";
		}

	}

}

int main() {

	int m;
	cin >> m;

	printPrimes(m);

	return 0;
}
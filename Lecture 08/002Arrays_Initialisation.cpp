#include<iostream>
#include<cstring>

using namespace std;

int main() {

	int A[5] = {10, 20, 30, 40, 50};
	int n = sizeof(A) / sizeof(int);

	for (int i = 0; i < n; i++) {
		cout << "A[" << i << "] = " << A[i] << endl;
	}

	int B[] = {100, 200, 300, 400};
	int m = sizeof(B) / sizeof(int);

	for (int i = 0; i < m; i++) {
		cout << "B[" << i << "] = " << B[i] << endl;
	}

	int C[5] = {1000, 2000, 3000};
	for (int i = 0; i < 5; i++) {
		cout << "C[" << i << "] = " << C[i] << endl;
	}

	int D[10] = {};
	for (int i = 0; i < 10; i++) {
		cout << D[i] << " ";
	}

	cout << endl;

	int E[10] = {0};
	for (int i = 0; i < 10; i++) {
		cout << E[i] << " ";
	}

	cout << endl;

	int F[10];

	memset(F, 0, sizeof(F));

	for (int i = 0; i < 10; i++) {
		cout << F[i] << " ";
	}

	cout << endl;

	return 0;
}
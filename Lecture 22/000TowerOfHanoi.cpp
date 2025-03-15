#include<iostream>

using namespace std;

// param : no. of disks / param2 : from / param3 : to / param4 : using

void f(int n, char src, char dst, char hlp) { // src to dst using hlp
	// base case
	if (n == 0) {
		return;
	}

	// recursive case

	// move n disks from src(A) to dst(C) using hlp(B)

	// 1. ask your friend to move n-1 disks from A(src) to B(hlp) using C(dst)

	f(n - 1, src, hlp, dst);

	// 2. move the largest disk from A(src) to C(dst)

	cout << "move disk from " << src << " to " << dst << endl;

	// 3. ask your friend to move n-1 disks from B(hlp) to C(dst) using A(src)

	f(n - 1, hlp, dst, src);

}


int main() {

	// for n disks, there will 2^n - 1 moves

	int n = 5;

	f(n, 'A', 'C', 'B');

	return 0;
}
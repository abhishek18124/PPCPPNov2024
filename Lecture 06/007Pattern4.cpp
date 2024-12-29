#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	// iterate over the rows

	int i = 1;

	while (i <= n) {

		// print i nos. for the ith row

		// int num;
		// if (i % 2 == 0) {
		// 	// we are in even row
		// 	num = 0;
		// } else {
		// 	// we are in odd row
		// 	num = 1;
		// }

		int num = i % 2 == 0 ? 0 : 1;

		int j = 1;

		while (j <= i) {
			cout << num << " ";

			// if(num == 1) {
			// 	num = 0;
			// } else {
			// 	num = 1;
			// }

			// num = !num;

			num = 1 - num;

			j++;
		}

		cout << endl;

		i++;

	}

	return 0;
}
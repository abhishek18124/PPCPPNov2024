/*

Given a string (sequence of characters) of length n, generate all of its permutations.

Example

	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>
#include<cstring>

using namespace std;

void generatePermutations(char inp[], int n, int i) {

	// base case

	if (i == n) {
		cout << inp << endl;
		return;
	}

	// recursive case

	// f(i) = take decisions for remaining positions from i to n-1

	// decide which char. is assigned to the ith index

	for (int j = i; j < n; j++) {
		swap(inp[i], inp[j]);
		generatePermutations(inp, n, i + 1);
		swap(inp[i], inp[j]); // backtracking
	}

}

int main() {

	char inp[] = "abc";
	int n = strlen(inp);

	generatePermutations(inp, n, 0);

	return 0;
}

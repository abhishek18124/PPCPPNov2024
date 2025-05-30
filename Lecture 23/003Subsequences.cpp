/*

Given a string of length n, generate all of its subsequences.

A subsequence of a given string (sequence) is a string (sequence) that is generated by
removing zero or more characters from the given string (sequence) without changing its
order.

Example

	Input : inp[] = "abc"
	Output: ["", "c", "b", "bc", "a", "ac", "ab", "abc"]

Constraints

  1 < n < 10

*/

#include<iostream>

using namespace std;

void generateSubseq(char inp[], char out[], int i, int j) {
	// base case
	if (inp[i] == '\0') { // i == n
		out[j] = '\0'; // you've taken n decisions that means you've built a subseq, so print it and return
		cout << out << endl;
		return;
	}

	// recursive case

	// f(i, j) = take decisions for chars i to n-1 such that next free index in out[] is j
	// f(i, j) = generate subsequences for inp[i...n-1] such that next free index in out[] is j

	// take a decision for inp[i]

	// option 1 : include inp[i] to the out[]
	out[j] = inp[i];
	generateSubseq(inp, out, i + 1, j + 1);

	// option 2 : exclude inp[i] from the out[]
	generateSubseq(inp, out, i + 1, j);

}

int main() {

	char inp[] = "abc";
	char out[10]; // based on constraints

	generateSubseq(inp, out, 0, 0);

	return 0;
}

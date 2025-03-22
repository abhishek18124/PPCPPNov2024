#include<iostream>

using namespace std;

void generateSubsequences(string& inp, string& out, int i) {

	// base case
	if (inp[i] == '\0') {
		cout << out << endl;
		return;
	}

	// recursive case

	// f(i) = take decisions for remaining positions i to n-1

	// decide for inp[i]

	// option 1 : include inp[i] to the out[]
	out.push_back(inp[i]);
	generateSubsequences(inp, out, i + 1);
	out.pop_back(); // backtracking

	// option 2 : exclude inp[i] from the out[]
	generateSubsequences(inp, out, i + 1);

}

int main() {

	string inp = "abc";
	string out = "";

	generateSubsequences(inp, out, 0);

	return 0;
}
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void revString(char str[]) {
	int i = 0;
	int j = strlen(str) - 1;
	while (i < j) {
		swap(str[i], str[j]);
		i++;
		j--;
	}
}

int main() {

	char str[] = "hello";

	cout << str << endl;

	// revString(str);

	// strrev(str);

	int n = strlen(str);

	reverse(str, str + n);

	cout << str << endl;

	return 0;
}
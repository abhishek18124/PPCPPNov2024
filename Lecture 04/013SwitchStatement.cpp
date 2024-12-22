#include<iostream>

using namespace std;

int main() {

	char grade;
	cin >> grade;

	// if (grade == 'A') {
	// 	cout << "very good" << endl;
	// } else if (grade == 'B') {
	// 	cout << "good" << endl;
	// } else if (grade == 'C') {
	// 	cout << "average" << endl;
	// } else if (grade == 'D') {
	// 	cout << "poor" << endl;
	// } else if (grade == 'E') {
	// 	cout << "very poor" << endl;
	// } else {
	// 	cout << "fail" << endl;
	// }


	switch (grade) { // char / int

	case 'A': cout << "very good" << endl; break;
	case 'B': cout << "good" << endl; break;
	case 'C': cout << "average" << endl; break;
	case 'D': cout << "poor" << endl; break;
	case 'E': cout << "very poor" << endl; break;
	default: cout << "fail" << endl; break; // optional

	}

	return 0;
}
#include<iostream>

using namespace std;

int main() {

	int p;
	cin >> p;

	int r;
	cin >> r;

	int t;
	cin >> t;

	cout << p * r * t / 100 << endl;
	cout << (p * r * t) / 100 << endl;
	cout << (p * r * t * 1.0) / 100 << endl;
	cout << (p * r * t) / 100.0 << endl;
	cout << (p * r * t) / (float)100 << endl; // explicit type-casting
	cout << (p * r * t) / float(100) << endl;
	cout << (p * r * t) / static_cast<float>(100) << endl;
	cout << (float)p * r * t / 100 << endl;

	float si = (p * r * t) / 100.0;
	cout << si << endl;

	return 0;
}
#include<iostream>

using namespace std;

void greet() {

	cout << "hello world" << endl;

	return; // optional

}

int main() {

	cout << "I am inside the main(), before greet()" << endl;

	greet(); // fn call / fn invocation

	cout << "I am inside the main(), after greet()" << endl;

	return 0;
}
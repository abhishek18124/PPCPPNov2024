#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

	customer(string n, int a, char g, double c) {
		cout << "I am inside the parameterised constructor of the customer class" << endl;
		name = n;
		age = a;
		gender = g;
		credits = c;
	}

	customer() {
		cout << "I am inside the default constructor of the customer class" << endl;
	}

	void print() {
		cout << "name = " << name << endl;
		cout << "age = " << age << endl;
		cout << "gender = " << gender << endl;
		cout << "credits = " << credits << endl;
	}
};



int main() {

	customer c1("Ramanujan", 32, 'M', 1729);

	c1.print();

	customer c2;

	customer c3("Aryabhata", 74, 'M', 0);

	c3.print();

	return 0;
}
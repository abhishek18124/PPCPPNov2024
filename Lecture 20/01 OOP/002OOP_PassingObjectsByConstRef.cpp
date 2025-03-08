#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

};

void print(const customer& ref) { // here, customer obj. are passed by ref
	cout << "name = " << ref.name << endl;
	cout << "age = " << ref.age << endl;
	cout << "gender = " << ref.gender << endl;
	cout << "credits = " << ref.credits << endl << endl;
}

int main() {

	customer c1;

	c1.name = "Ramanujan";
	c1.age = 32;
	c1.gender = 'M';
	c1.credits = 1729;

	print(c1);

	cout << "inside main() after print() age = " << c1.age << endl << endl;

	customer c2;

	c2.name = "Aryabhata";
	c2.age = 74;
	c2.gender = 'M';
	c2.credits = 0;

	print(c2);

	cout << "inside main() after print() age = " << c2.age << endl << endl;

	return 0;
}
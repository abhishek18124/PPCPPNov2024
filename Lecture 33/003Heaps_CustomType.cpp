/*

	STL implementation of the min_heap data structure.


*/

#include<iostream>
#include<queue>

using namespace std;

class customer {
public:
	string name;
	int age;
	customer(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

class ageCmp { // obj. of this class is callable
public:

	// return true if you want a to be ordered before b
	// otherwise return false

	// return false if you want a to be given more prio
	// otherwise return true;

	bool operator()(customer a, customer b) {
		if (a.age < b.age) {
			return false;
		}
		return true;
	}

};

int main() {

	priority_queue<customer, vector<customer>, ageCmp> m;

	// we are building minHeap on customer age

	m.push(customer("archita", 20));
	m.push(customer("bhavya", 19));
	m.push(customer("aditi", 21));
	m.push(customer("umang", 22));
	m.push(customer("aryan", 18));

	cout << m.size() << endl; // 5

	while (!m.empty()) {
		customer c = m.top();
		cout << c.name << " " << c.age << endl;
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl;

	return 0;
}
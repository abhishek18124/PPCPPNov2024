#include<iostream>

using namespace std;

#include<iostream>

using namespace std;

void increment(int* ptr) {
  (*ptr)++;
}

int main() {
  int a = 0;
  increment(&a);
  cout << a << endl;
  return 0;
}
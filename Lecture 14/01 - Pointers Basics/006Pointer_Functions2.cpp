#include<iostream>

using namespace std;

#include<iostream>

using namespace std;

void increment(int* const & ptrRef) {
  (*ptrRef)++;
}

int main() {
  int a = 0;
  // int* ptr = &a;
  // increment(ptr);
  increment(&a);
  cout << a << endl;
  return 0;
}
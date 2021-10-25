#include <iostream>

using namespace std;

struct base1 {
  char c;
};

struct base2 {
  char d;
};

struct derived : public base2, public base1 {};


int main () {
  derived d;
  cout << (unsigned int)&d << endl;
  cout << (unsigned int)(base1 *)&d << endl;
  cout << (unsigned int)(base2 *)&d << endl;
}

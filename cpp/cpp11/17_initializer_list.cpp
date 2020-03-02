#include <iostream>
#include <initializer_list>

struct X {
  X() = default;
  X(const X&) = default;
};

struct Q {
  Q() = default;
  Q(Q const&) = default;
  Q(std::initializer_list<int> arg) 
  {
    for (auto a: arg)
      std::cout <<  a << "\n";
  }
};

int main() {
  X x;
  X x2 { x }; 
//  Q q1 ( 1);
  Q q2 { 2 };
  Q q3 { 3, 4 , 5};
}




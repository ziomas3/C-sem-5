#include<iostream>
#include<initializer_list>

struct X {
  X()         {std::cout << __PRETTY_FUNCTION__ << "\n";}
  X(X const&) {std::cout << __PRETTY_FUNCTION__ << "\n";}  
  X(int n   ) {std::cout << __PRETTY_FUNCTION__ << "\n";}  
};

struct Q {
  Q()         {std::cout << __PRETTY_FUNCTION__ << "\n";}
  Q(Q const&) {std::cout << __PRETTY_FUNCTION__ << "\n";} 
  Q(std::initializer_list<int> arg) 
  {
    std::cout << __PRETTY_FUNCTION__ << "\n";
    for (auto a: arg)
      std::cout <<  a << "\n";
  }
  Q(int n) {std::cout << __PRETTY_FUNCTION__ << "\n";}
};

int main() {
  X x;
  X x2 = X {x};
  X x3 {3};
  X x4 (4);
//  X x5 {2, 3}

  Q q1 = Q {1};
  Q q2 = 2;
  Q q3 (2);
  Q q4 {4};
  Q q5 {4, 5};
  Q q6 = {6, 7};
}

#include <iostream>

int print(int const& a)
{
  std::cout << a << "\n";
  std::cout << __FUNCTION__ << "\n";
  std::cout << __PRETTY_FUNCTION__ << "\n";
}

int main()
{
  print(0);
}



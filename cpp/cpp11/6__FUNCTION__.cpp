#include <iostream>

int main()
{
  decltype('a' + 2) x = 7;
  std::cout << x << "\n";
}



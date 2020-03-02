#include <iostream>

auto minimum(int a, int b) -> int
{
  return a < b ? a : b;
}

int main()
{
  std::cout <<  minimum(2, 5) << "\n";
}



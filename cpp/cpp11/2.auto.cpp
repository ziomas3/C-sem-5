#include <iostream>

// błąd w c++11, w c++14 jest OK
auto minimum(int a, int b) 
{
  return a < b ? a : b;
}

int main()
{
  std::cout <<  minimum(2, 5) << "\n";
}



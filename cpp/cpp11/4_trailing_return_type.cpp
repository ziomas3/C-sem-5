#include <iostream>

template <typename T1, typename T2>
auto suma(T1 a, T2 b) -> decltype(a + b)
{
  return a + b;
}

int main()
{
  std::cout << suma(2, 5) << "\n";
  std::cout << suma(2, 5.5) << "\n";
  std::cout << suma('a', 5) << "\n";
}



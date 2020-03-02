#include <iostream>

constexpr int silnia(int n)
{
  return n <= 1 ? 1 : n*silnia(n-1);
}

int main()
{
  constexpr int N = 100;
  int a[N]; // OK
  int b[silnia(5)]; // OK
  std::cout << sizeof(b)/sizeof(b[0]) << "\n";
  int n;
  std::cin >> n;
  std::cout << silnia(n) << "\t" << &N << "\n";
} 



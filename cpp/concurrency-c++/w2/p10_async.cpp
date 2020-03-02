#include <iostream>
#include <string>
#include <future>
#include <chrono>

double my_fun(int n)
{
  double s = 0.0;
  for (int i = 1; i <= n; i += 2)
    s += 1.0/i - 1.0/(i+1);
  return s; 
}

int main()
{
  constexpr int n = 100000000;
  auto fut = std::async(my_fun, n);
  std::cout << "Czekam na wynik...\n";
  auto value = fut.get();
  std::cout << value << "\n";
}



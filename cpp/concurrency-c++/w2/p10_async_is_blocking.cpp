#include <iostream>
#include <string>
#include <future>
#include <chrono>

double my_fun(int n)
{
  std::cout << "hello from thread\n";  
  double s = 0.0;
  for (int i = 1; i <= n; i += 2)
    s += 1.0/i - 1.0/(i+1);
  std::cout << "bye from thread\n";  
  return s; 
}

int main()
{
  constexpr int n = 300000000;
  auto f0 = std::async(my_fun, n);
  auto f1 = std::async(my_fun, n);
  for (volatile int i = 0; i < 100000000; i++)
  {
  }
  std::cout << "Czekam na wynik...\n";
//  auto value = fut.get();
  std::cout << f0.get() << " " << f1.get() << "bye\n";
}



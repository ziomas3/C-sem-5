#include <iostream>
#include <string>
#include <future>
#include <chrono>
#include <cmath>

template <typename T>
T my_fun(int n)
{
  T s = 0.0;
  for (int i = (n/2)*2; i >= 2; i -= 2)
    s += 1.0/(i-1) - 1.0/i;
  return s; 
}

int main(int argc, const char* argv[])
{
  int n = (argc == 1) ? 1000000 : std::stoi(argv[1]);
  std::cout << "Tworzę świat równoległy\n";
  auto fut1 = std::async(my_fun<double>, n);
  auto fut2 = std::async(my_fun<float>,  n);
  auto value1 = fut1.get();
  auto value2 = fut2.get();
  std::cout << value1 - log(2.0) << "\n";
  std::cout << value2 - log(2.0) << "\n";
}



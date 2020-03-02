#include <iostream>
#include <future>

double f()
{
  std::cout << "hello!" << std::endl;
  double s = 0.0;
  for (int i = 0; i < 1000000000; i++)
    s += 1.0/(i + 1); 
  std::cout << "good bye!" << std::endl;
  return s;
}

int main()
{
  std::cout << "uruchamiam drugi wątek\n";
  auto fut = std::async(f);
  double s = 0.0;
  for (int i = 0; i < 1000000000; i++)
    s += 1.0/(i + 1); 
  std::cout << "główny: " << s << "\n";
  std::cout << "czekam\n";
  auto value = fut.get();
  std::cout << value << "\n";
}


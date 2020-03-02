#include <iostream>
#include <thread>

void my_fun(char c, int n)
{
  for (int i = 0; i < n; i++)
    std::cout << c << std::flush;
  std::cout << "\n";
}

int main()
{
  std::thread th(&my_fun, 'x', 20);
  my_fun('o', 20);
  th.join();
}



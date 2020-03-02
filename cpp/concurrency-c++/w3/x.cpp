#include <iostream>
#include <thread>
#include <mutex>

std::mutex mut;

void my_fun(char c, int n)
{
  ::mut.lock();
  for (int i = 0; i < n; i++)
    std::cout << c;
  std::cout << "\n";
  mut.unlock();
}

int main()
{
  std::thread th(&my_fun, 'w', 200);
  my_fun('m', 200);
  th.join();
}



#include <iostream>
#include <thread>
#include <vector>

constexpr int N = 10;

void th_fun(int i)
{
  std::cout << "Witaj, świecie nr " << i << "\n"; 
}

int main()
{
  std::vector<std::thread> workers;
  for (int i = 0; i < N; i++)
  {
    std::thread th (&th_fun, i);
    workers.push_back(std::move(th));
  }
  std::cout << "Hello, world!\n";
  for (auto & w: workers)
    w.join();
}
   


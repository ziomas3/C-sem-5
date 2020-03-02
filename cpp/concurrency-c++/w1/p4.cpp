#include <iostream>
#include <thread>
#include <vector>

const int N = 10;

int main()
{
  std::vector<std::thread> workers;
  for (int i = 0; i < N; i++)
  {
    workers.push_back(std::thread ([i]() 
    {
      std::cout << "Witaj, świecie nr " << i << "\n"; 
    }));
  }
  std::cout << "Hello, world!\n";
  for (auto & w: workers)
    w.join();
}
   


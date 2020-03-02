#include <iostream>
#include <thread>
#include <vector>
#include <cassert>

const int N = 10;

int main()
{
  std::vector<std::thread> workers;
  for (int i = 0; i < N; i++)
  {
    std::thread th ([i]() 
    {
      std::cout << "Witaj, świecie nr " << i << "\n"; 
    });
    workers.push_back(std::move(th));
    assert (!th.joinable());
  }
  std::cout << "Hello, world!\n";
  for (auto & w: workers)
  {
    assert (w.joinable());
    w.join();
  }
}
   


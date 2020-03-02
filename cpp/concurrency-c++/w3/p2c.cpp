#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void my_fun(char c, int n)
{
  try{
    std::unique_lock<std::mutex> lg(mtx);
    for (int i = 0; i < n; i++)
      std::cout << c << std::flush;
    std::cout << "\n";
    throw std::runtime_error("O jej!");
  }
  catch(std::exception const& e)
  {
    std::cout << e.what() << "\n";
  }
}

int main()
{
  std::thread th(&my_fun, 'x', 20);
  my_fun('o', 20);
  th.join();
}



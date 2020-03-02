#include <iostream>
#include <thread>

void my_fun_pl()
{
  std::cout << u8"Witaj, świecie!\n";
}

int main()
{
  std::thread th(&my_fun_pl);
  std::cout << "Hello, world!\n";
  th.join();
}



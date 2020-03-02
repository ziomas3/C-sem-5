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
  auto th2 (std::move(th));
  if (th.joinable())
    th.join();
  if (th2.joinable())
    th2.join();
}



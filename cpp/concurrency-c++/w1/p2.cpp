#include <iostream>
#include <thread>

int main()
{
  std::thread th([]() 
  {
    std::cout << u8"Witaj, świecie!\n"; 
  });
  std::cout << "Hello, world!\n";
  th.join();
}



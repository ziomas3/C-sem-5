#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

std::atomic<bool> is_ready(false);

void test()
{
  std::this_thread::sleep_for(std::chrono::seconds(5));
  is_ready.store(true);
}

int main()
{
  std::thread th(test);
  while (!is_ready.load())
    std::this_thread::sleep_for(std::chrono::seconds(0));
  th.join();
}



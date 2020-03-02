#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>

bool is_ready(false);
std::mutex m;
std::condition_variable cv;

void test()
{
  std::this_thread::sleep_for(std::chrono::seconds(5));
  std::unique_lock<std::mutex> lk(m);
  is_ready = true;
  cv.notify_one();
}

int main()
{
  std::thread t(test);
  std::unique_lock<std::mutex> lk(m);
  while (!is_ready)
  {
    cv.wait(lk);
    if (!is_ready)
      std::cout << "To niemożliwe!\n";
  }
  t.join();
}


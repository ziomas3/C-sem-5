#include <iostream>       // std::cout
#include <atomic>         // std::atomic
#include <thread>         // std::thread
#include <vector>         // std::vector

std::atomic<bool> ready (false);
std::atomic<bool> winner (false);

void count1m (int id) {
  while (!ready) 
  { }                  // zekaj na sygnał "ready"
  for (volatile int i=0; i<1000000; ++i) 
  { }   // licz do miliona
  if (!winner.exchange(true)) 
    std::cout << "wątek #" << id << " wygrał!\n"; 
};

int main ()
{
  std::vector<std::thread> threads;
  std::cout << "tworzę 10 wątków które liczą do miliona...\n";
  for (int i=1; i<=10; ++i) 
    threads.push_back(std::thread(count1m,i));
  ready = true;
  for (auto& th : threads) 
    th.join();

  return 0;
}

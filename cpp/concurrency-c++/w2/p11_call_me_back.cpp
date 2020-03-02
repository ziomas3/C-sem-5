#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <future>

void th_fun(std::shared_future<void> sfut, int id)
{
  std::ofstream F("parallel.txt", std::ios::app);
  while(sfut.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
  {
    for (volatile long int i = 0; i < id*1'000'000'000L+ 390'005'000; i++)
      continue;
    F << std::to_string(id) + "\n" << std::flush;
  };
  std::cout << "bye from " + std::to_string(id) + "\n";
}

int main()
{
  constexpr int N = 4; 
  std::promise<void> prms;
  std::shared_future<void> sf = prms.get_future().share();
  std::vector<std::thread> v; 
  for (int i = 0; i < 4; i++)
    v.emplace_back(th_fun, sf, i+1);
  std::cout << "all is up and running\nNow waiting for q...\n";
  char c;
  while (std::cin >> c)
  {
    std::cout << c << "\n";
    if (c == 'q')
    {  
      prms.set_value();
      break;
    }
  }
  for (auto & th: v)
    th.join();
}



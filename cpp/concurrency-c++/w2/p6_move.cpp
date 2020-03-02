#include <iostream>
#include <thread>
#include <vector>


std::vector<int> set_seq(std::vector<int> v, int n)
{
  v.resize(0);
  v.reserve(n);
  std::cout << "starting " << __FUNCTION__ << " for vector at " << v.data() << "\n";
  for (int i = 0; i < n; i++)
    v.push_back(i);
  std::cout << "completed " << __FUNCTION__ << " for vector at " << v.data() << "\n";
  return v;
}

int main()
{
  constexpr int N = 200000000;
  std::cout << "Hello, world!\n";
  std::vector<int> v, w;
  std::thread th (&set_seq, std::move(v), N);
  w = set_seq(std::move(v), N);
  std::cout << "data for w at " << w.data() << "\n";
  th.join();
  for (auto i = 0; i < 5; i++)
    std::cout << "\t" << w[i];
  std::cout << "\nBye, world!\n";
}
   


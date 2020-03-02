#include <iostream>
#include <cstdlib>
#include <vector>
#include <thread>
#include <algorithm>
#include <atomic>

class Counter
{
  std::atomic<int> _counter;
public:
  Counter()
  :_counter(0)
  { }
  void operator++() { _counter++; }
  void operator--() { _counter--; }
  int get() const   { return _counter; }
};

void test(Counter & c, std::vector<int> const& v, int i0, int n)
{
  for (int i = i0; i < i0 + n; i++)
    if (v[i] % 2 == 0)
      ++c;
    else
      --c;
}

int main()
{
  constexpr int N = 50000000;
  constexpr int M = 4;
  Counter c;
  std::vector<int> dane(N);
  std::vector<std::thread> v;
  std::generate(dane.begin(), dane.end(), std::rand);
  for (int i = 0; i < M; i++)
    v.emplace_back(&test, std::ref(c), std::cref(dane), i*N/M, N/M);
  for (auto & th : v)
    th.join();
  std::cout << "przewaga parzystych: " << c.get() << std::endl;
}



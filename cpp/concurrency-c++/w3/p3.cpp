#include <iostream>
#include <thread>
#include <mutex>


class Monitor
{
  int _n;
  std::mutex & _mut;
public:
  Monitor (std::mutex & m)
  :_n(0), _mut(m) 
  { }

  void set(int k)
  {
    _mut.lock();
    _n = k;
    _mut.unlock();
  }

  int get() const
  {
    _mut.lock();
    int k = _n;
    _mut.unlock();
    return k; 
  }
  
  void inc()
  {
    _mut.lock();
    _n++;
    _mut.unlock();
  }
};


void my_fun(Monitor & mon, int n)
{
  for (int i = 0; i < n; i++)
  {  
    mon.inc();
  }
}

int main()
{
  constexpr int N = 10000000;
  std::mutex mut;
  Monitor mon(mut);
  std::thread th(&my_fun, std::ref(mon), N);
  my_fun(mon, N);
  th.join();
  std::cout << mon.get() << "\n";
}



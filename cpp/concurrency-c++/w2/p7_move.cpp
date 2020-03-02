#include <iostream>
#include <thread>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>

constexpr int N = 10;
constexpr int M = 10000;

void th_fun(std::map<int,int> && map, std::vector<int> const& v, 
            int start, int len)
{
  for (int i = start; i < len + start; ++i)
    map[v[i]]++;
  std::cout << start << " " << map[0] << "\n";
} 

int main()
{
  srand(0);
  std::vector<int> v(M);
  std::generate(v.begin(), v.end(), [](){return rand() % N; });
  std::map<int,int> mapa;
  std::thread th (&th_fun, std::move(mapa), std::cref(v), 0, M/2);
  th_fun (std::move(mapa), v, M/2, M/2);
  th.join();
  for (auto x: mapa)
    std::cout <<  x.second << " ";
  std::cout << "\n";
}
   


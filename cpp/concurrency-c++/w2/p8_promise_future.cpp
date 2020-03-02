#include <iostream>
#include <string>
#include <thread>
#include <future>

void my_fun(std::promise<std::string> & prms)
{
  prms.set_value(std::string("Ja bez żadnego trybu...\n"));
}

int main()
{
  std::promise<std::string> prms;
  std::thread th (&my_fun, std::ref(prms));
  std::future<std::string> fut = prms.get_future();
  std::string str = fut.get();
  std::cout << str << "\n";
  th.join();
}



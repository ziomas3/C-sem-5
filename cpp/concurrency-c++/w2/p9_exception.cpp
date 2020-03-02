#include <iostream>
#include <string>
#include <thread>
#include <future>
#include <chrono>

void my_fun(std::promise<std::string> prms)
{
  try{
    std::string str("Witajcie w przyszłości!");
    throw std::runtime_error("robotnik zgłasza wyjątek");
    prms.set_value(str); // nigdy nie uruchamiany
  }
  catch(std::exception &)
  {
//    prms.set_exception(std::current_exception());
  }
}

int main(int argc, const char* argv[])
{
  std::thread th;
  try{
    int x = 3;
    int y = x / (argc - 1);
    std::cout << y << "\n";
    std::promise<std::string> prms;
    std::future<std::string> fut = prms.get_future();
    th = std::thread (&my_fun, std::move(prms));
    std::string str = fut.get();
    std::cout << str << "\n";
  }
  catch(std::exception & e)
  {
     std::cout << "wyjątek: "<< e.what() << "\n";
  }
  if (th.joinable())
     th.join();
}



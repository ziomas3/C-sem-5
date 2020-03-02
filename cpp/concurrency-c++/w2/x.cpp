#include <iostream>
#include <string>
#include <thread>
#include <future>

void my_fun(std::promise<std::string> & prms)
{
  try{
  std::string str("Witajcie w przyszłości!\n");
//  prms.set_value(str);
// prms.set_value(str);
  throw std::runtime_error("ala ma kota");
  }
  catch(std::exception & e)
  {
    std::cout << "catching " << e.what() << "\n";
    prms.set_exception(std::current_exception());
    std::cout << "still catching " << e.what() << "\n";
  }
}

int main()
{
  std::thread th;
  try{
    std::promise<std::string> prms;
    std::future<std::string> fut = prms.get_future();
    th = std::thread (&my_fun, std::ref(prms));
    std::string str;
    str = fut.get();
    std::cout << str << "\n";
    th.join();
  }
  catch(std::exception & e)
  {
     std::cout << e.what() << "\n";
     th.join();
  }
}



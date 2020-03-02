#include <iostream>

class A final
{
  public:
    int a;
};

class B : A
{
  public:
    int f() { return a; }
};

int main()
{

}


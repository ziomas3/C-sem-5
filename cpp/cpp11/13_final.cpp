#include <iostream>

class A
{
  public:
    virtual int f() = 0;
};

class B : A
{
  public:
    int f() override final {return 2;}
    int g() { return 2 + f(); }
};

int main()
{

}


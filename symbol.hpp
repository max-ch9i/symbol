#pragma once
#include <iostream>

template <class T>
class Symbol
{
  private:
    T num;
    T den;
  public:
    Symbol(T num, T den):num(num),den(den) {};
    ~Symbol() {};
    T getNum() const {return num;};
    T getDen() const {return den;};

    // COPY
    Symbol(const Symbol& x):num(x.getNum()),den(x.getDen())
    {
      std::cout << "COPY CONST" << std::endl;
    }
    Symbol& operator=(const Symbol& x)
    {
      std::cout << "COPY ASSIGN" << std::endl;
      num = x.getNum();
      den = x.getDen();
      return *this;
    }

    // Move
    Symbol(Symbol&& x):num(x.getDen()),den(x.getDen())
    {
      std::cout << "MOVE CONST" << std::endl;
    }
    Symbol& operator=(Symbol&& x)
    {
      std::cout << "MOVE ASSGN" << std::endl;
      if (this != &x)
      {
        num = x.getNum();
        den = x.getDen();
      }
      return *this;
    }
};

#pragma once
#include <iostream>

template <class T>
class Symbol
{
  private:
    T num;
    T den;
  public:
    Symbol():num(0),den(0) {};
    Symbol(T num, T den):num(num),den(den) {
    };
    ~Symbol() {};
    T getNum() const {return num;};
    T getDen() const {return den;};

    // COPY
    Symbol(const Symbol& x):num(x.getNum()),den(x.getDen())
    {
      // std::cout << "COPY CONST" << std::endl;
    }
    Symbol& operator=(const Symbol& x)
    {
      // std::cout << "COPY ASSIGN" << std::endl;
      num = x.getNum();
      den = x.getDen();
      return *this;
    }

    // Move
    Symbol(Symbol&& x):num(x.getNum()),den(x.getDen())
    {
      // std::cout << "MOVE CONST" << std::endl;
    }
    Symbol& operator=(Symbol&& x)
    {
      // std::cout << "MOVE ASSGN" << std::endl;
      if (this != &x)
      {
        num = x.getNum();
        den = x.getDen();
      }
      return *this;
    }

    double sim()
    {
      return (double)num / (double)den;
    }

    void operator*=(const T& x)
    {
      num *= x;
    }

    void operator*=(const Symbol& x)
    {
      num *= x.getNum();
      den *= x.getDen();
    }
    void operator-=(const Symbol& x)
    {
      num = (num * x.getDen() - x.getNum()*den);
      den = (den * x.getDen());
    }

    friend std::ostream& operator<<(std::ostream& os, const Symbol<T>& m)
    {
      os << m.getNum() << " / " << m.getDen();
      return os;
    };

    // MULTIPLICATION
    friend Symbol operator*(const Symbol& a, const Symbol& b)
    {
      Symbol x(a.getNum() * b.getNum(), a.getDen() * b.getDen());
      return x;
    };

    friend Symbol operator*(const Symbol& a, Symbol&& b)
    {
      Symbol x(a.getNum() * b.getNum(), a.getDen() * b.getDen());
      return x;
    };

    friend Symbol operator*(Symbol&& a, const Symbol& b)
    {
      Symbol x(a.getNum() * b.getNum(), a.getDen() * b.getDen());
      return x;
    };

    friend Symbol operator*(Symbol&& a, Symbol&& b)
    {
      Symbol x(a.getNum() * b.getNum(), a.getDen() * b.getDen());
      return x;
    };

    // ADDITION
    friend Symbol operator+(const Symbol& a, const Symbol& b)
    {
      Symbol x(a.getNum()*b.getDen() + b.getNum()*a.getDen(), a.getDen() * b.getDen());
      return x;
    };

    friend Symbol operator+(const Symbol& a, Symbol&& b)
    {
      Symbol x(a.getNum()*b.getDen() + b.getNum()*a.getDen(), a.getDen() * b.getDen());
      return x;
    };

    friend Symbol operator+(Symbol&& a, const Symbol& b)
    {
      Symbol x(a.getNum()*b.getDen() + b.getNum()*a.getDen(), a.getDen() * b.getDen());
      return x;
    };

    friend Symbol operator+(Symbol&& a, Symbol&& b)
    {
      Symbol x(a.getNum()*b.getDen() + b.getNum()*a.getDen(), a.getDen() * b.getDen());
      return x;
    };

    // SUBTRACTION
    friend Symbol operator-(const Symbol& a, const Symbol& b)
    {
      Symbol x(a.getNum()*b.getDen() - b.getNum()*a.getDen(), a.getDen() * b.getDen());
      return x;
    };

    friend Symbol operator-(const Symbol& a, Symbol&& b)
    {
      Symbol x(a.getNum()*b.getDen() - b.getNum()*a.getDen(), a.getDen() * b.getDen());
      return x;
    };

    friend Symbol operator-(Symbol&& a, const Symbol& b)
    {
      Symbol x(a.getNum()*b.getDen() - b.getNum()*a.getDen(), a.getDen() * b.getDen());
      return x;
    };

    friend Symbol operator-(Symbol&& a, Symbol&& b)
    {
      Symbol x(a.getNum()*b.getDen() - b.getNum()*a.getDen(), a.getDen() * b.getDen());
      return x;
    };


    // DIVISION
    friend Symbol operator/(const Symbol& a, const Symbol& b)
    {
      Symbol x(a.getNum()*b.getDen(), a.getDen() * b.getNum());
      return x;
    };

    friend Symbol operator/(const Symbol& a, Symbol&& b)
    {
      Symbol x(a.getNum()*b.getDen(), a.getDen() * b.getNum());
      return x;
    };

    friend Symbol operator/(Symbol&& a, const Symbol& b)
    {
      Symbol x(a.getNum()*b.getDen(), a.getDen() * b.getNum());
      return x;
    };

    friend Symbol operator/(Symbol&& a, Symbol&& b)
    {
      Symbol x(a.getNum()*b.getDen(), a.getDen() * b.getNum());
      return x;
    };

    friend bool operator!=(const Symbol& a, const Symbol& b)
    {
      return (a - b).getNum() != 0;
    }
};

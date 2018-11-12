#include <iostream>
#include <vector>
#include "symbol.hpp"
#include "simplify.hpp"

char test_failed[] = "Test failed: ";

using namespace std;

template <class T>
Symbol<T> genSymbol(T num, T den)
{
  Symbol<T> a(num, den);
  return a;
}

void test_2x2()
{
  Symbol<long> x1(10,5);
  Symbol<long> x2(x1);
}

void test_mult()
{
  Symbol<long> y2 = genSymbol((long)10, (long)5) * genSymbol((long)5, (long)1);

  if (y2.getNum() != 50 || y2.getDen() != 5)
  {
    cout << test_failed << __FUNCTION__ << endl;
    cout << y2 << endl;
  }

  Symbol<long> y1 = Symbol<long>(10, 5) * y2;

  if (y1.getNum() != 500 || y1.getDen() != 25)
  {
    cout << test_failed << __FUNCTION__ << endl;
    cout << y1 << endl;
  }
}

void test_add()
{

  Symbol<long> y1 = Symbol<long>(10, 5) + Symbol<long>(10, 5);

  if (y1.getNum() != 100 || y1.getDen() != 25)
  {
    cout << test_failed << __FUNCTION__ << endl;
    cout << y1 << endl;
  }

  Symbol<long> y2 = genSymbol((long)2, (long)2) + y1;

  if (y2.getNum() != 250 || y2.getDen() != 50)
  {
    cout << test_failed << __FUNCTION__ << endl;
    cout << y2 << endl;
  }
}

void test_sub()
{

  Symbol<long> y1 = Symbol<long>(10, 5) - Symbol<long>(10, 5);

  if (y1.getNum() != 0 || y1.getDen() != 25)
  {
    cout << test_failed << __FUNCTION__ << endl;
    cout << y1 << endl;
  }

  Symbol<long> y2 = y1 - genSymbol((long)2, (long)2);

  if (y2.getNum() != -50 || y2.getDen() != 50)
  {
    cout << test_failed << __FUNCTION__ << endl;
    cout << y2 << endl;
  }
}

void test_div()
{
  Symbol<long> y2 = genSymbol((long)10, (long)5) / genSymbol((long)5, (long)2);

  if (y2.getNum() != 20 || y2.getDen() != 25)
  {
    cout << test_failed << __FUNCTION__ << endl;
    cout << y2 << endl;
  }

  Symbol<long> y1 = Symbol<long>(10, 5) / y2;

  if (y1.getNum() != 250 || y1.getDen() != 100)
  {
    cout << test_failed << __FUNCTION__ << endl;
    cout << y1 << endl;
  }
}

void test_simplify()
{
  Symbol<long> x(81,3);
  // Simplify::getInstance().sim(x);

  Simplify<long> simplify;
  Symbol<long> x1 = simplify.sim(x);
  cout << x1 << endl;
}

void run_tests()
{
  test_2x2();
  test_mult();
  test_add();
  test_sub();
  test_div();
  test_simplify();
}

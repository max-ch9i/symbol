#include <iostream>
#include "symbol.hpp"

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
  Symbol<long> x3 = x2;

  Symbol<long> y1(genSymbol((long)20, (long)30));
  Symbol<long> y2 = genSymbol((long)20, (long)30);
}

void run_tests()
{
  test_2x2();
}

#pragma once
#include "symbol.hpp"
#include <map>
#include <vector>
#include <cmath>

template<class T> 
class Simplify
{
    public:
        Symbol<T> sim(Symbol<T> x)
        {
          T num = x.getNum();
          T den = x.getDen();

          T gcd = getGreatestCommonDivisor(num, den);

          return Symbol<T>(num / gcd, den / gcd);
        }
        T getGreatestCommonDivisor(T num, T den)
        {
          if (gcds.find(num) != gcds.end() && gcds[num].find(den) != gcds[num].end())
          {
            return gcds[num][den];
          }

          if (num % den == 0)
          {
            return den;
          }

          std::vector<T> a = getDivisors(num);
          std::vector<T> b = getDivisors(den);

          typename std::vector<T>::iterator a_it = a.begin();
          typename std::vector<T>::iterator a_end = a.end();
          typename std::vector<T>::iterator b_it = b.begin();
          typename std::vector<T>::iterator b_end = b.end();
          T res = (T)1;

          for (;a_it != a_end;++a_it)
          {
            for (;b_it != b_end;++b_it)
            {
              if (*a_it == *b_it)
              {
                res = (T)*a_it;
              }
            }
          }

          if (gcds.find(num) == gcds.end())
          {
            gcds[num] = { {den, res} };
          }
          else
          {
            gcds[num][den] = res;
          }
          
          return res;
        }
        std::vector<T> getDivisors(T a)
        {
          T a_abs = std::abs(a);
          
          if (divisors.find(a) != divisors.end())
          {
            return divisors[a];
          }

          T i = a_abs - 1;
          std::vector<T> res;
          for (;i > 2; i--)
          {
            if(a_abs % i == 0)
            {
              res.push_back(i);
            }
          }
          divisors[a] = res;
          return res;
        }
    private:
        std::map<T, std::vector<T>> divisors;
        std::map<T, std::map<T,T>> gcds;
};

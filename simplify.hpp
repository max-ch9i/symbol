#pragma once
#include <map>
#include <vector>
#include <cmath>
#include <utility>
#include <iostream>

enum CACHE{FOUND, NOT_FOUND};

template<class T> 
class Simplify
{
    public:
        T getGreatestCommonDivisorBrute(T x, T y)
        {
          if (x == 0)
          {
            return y;
          }

          T _num = std::abs(x);
          T _den = std::abs(y);

          T num = _num > _den ? _num : _den;
          T den = _num > _den ? _den : _num;

          std::pair<T, CACHE> c = get_from_cache(num, den);

          if (std::get<1>(c) != CACHE::NOT_FOUND)
            return std::get<0>(c);

          if (den != 0 && num % den == 0)
          {
            add_to_cache(num, den, den);
            return den;
          }

          std::vector<T> a = getDivisors(num);
          std::vector<T> b = getDivisors(den);

          T res = (T)1;

          typename std::vector<T>::iterator a_it = a.begin();
          typename std::vector<T>::iterator a_end = a.end();

          for (;a_it != a_end;++a_it)
          {
            typename std::vector<T>::iterator b_it = b.begin();
            typename std::vector<T>::iterator b_end = b.end();

            for (;b_it != b_end;++b_it)
            {
              if (*a_it == *b_it)
              {
                res = (T)*a_it;
                a_it = a_end - 1;
                b_it = b_end - 1;
              }
            }
          }

          add_to_cache(num, den, res);
          
          return res;
        }
        T getGreatestCommonDivisor(T _num, T _den)
        {
          if (_num == 0 && _den != 0)
          {
            return _den;
          }

          _num = std::abs(_num);
          _den = std::abs(_den);

          T x = _num > _den ? _num : _den;
          T y = _num > _den ? _den : _num;

          std::pair<T, CACHE> c = get_from_cache(x, y);

          if (std::get<1>(c) != CACHE::NOT_FOUND)
            return std::get<0>(c);

          T cache_x = x;
          T cache_y = y;

          // Euclids
          // x > y, x > 0, y > 0
          // x = k*y + l

          T remainder = y + x;
          T remainder_prev = x;

          while (remainder != 0)
          {
            x = y;
            y = remainder;
            remainder_prev = remainder;

            remainder = x % y;
          }

          add_to_cache(cache_x, cache_y, remainder_prev);

          return remainder_prev;
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
        std::pair<T, CACHE> get_from_cache(T num, T den)
        {
          if (gcds.find(num) != gcds.end() && gcds[num].find(den) != gcds[num].end())
          {
            return std::pair<T, CACHE>(gcds[num][den], CACHE::FOUND);
          }
          return std::pair<T, CACHE>((T)0, CACHE::NOT_FOUND);
        }
        void add_to_cache(T num, T den, T res)
        {
          if (gcds.find(num) == gcds.end())
          {
            gcds[num] = { {den, res} };
          }
          else
          {
            gcds[num][den] = res;
          }
        }
        std::map<T, std::vector<T>> divisors;
        std::map<T, std::map<T,T>> gcds;
};

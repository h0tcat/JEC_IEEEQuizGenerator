#ifndef __ERATOSTHENES_H__
#define __ERATOSTHENES_H__

#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>

namespace nori{
  class Eratosthenes{
    private:
      int N=1;
      std::vector<int>* numberList,*removedList;

    public:
      Eratosthenes();
      Eratosthenes(int N);
      void setN(int N);
      ~Eratosthenes();
      void Start();
      std::vector<int> getPrimeList();
  };
};

#endif

#include "Eratosthenes.h"

nori::Eratosthenes::Eratosthenes(){
  this->N=10000;
}

nori::Eratosthenes::Eratosthenes(int N){
  this->N=N;
}

nori::Eratosthenes::~Eratosthenes(){
  delete this->numberList;
  delete this->removedList;
}

void nori::Eratosthenes::Start(){
  this->numberList=new std::vector<int>(N);
  this->removedList=new std::vector<int>(N);

  std::iota(this->numberList->begin(),this->numberList->end(),1);
  this->numberList->erase(std::remove_if(
        this->numberList->begin(),
        this->numberList->end(),
        [](int x){return x==1;}));

  this->numberList->erase(std::remove_if(
        this->numberList->begin(),
        this->numberList->end(),
        [](int x) { return x % 2 == 0; }),
      this->numberList->end());

  this->numberList->push_back(2);
  for(int i=3;i<=this->N;i+=2){
    //もしiが未探索の数字なら...
    if(std::find(this->removedList->begin(),this->removedList->end(),i)==this->removedList->end()){

      std::copy_if(this->numberList->begin(),this->numberList->end(),std::back_inserter(*this->removedList),[=](int x){return x % i==0;});

      this->numberList->erase(std::remove_if(
            this->numberList->begin(),
            this->numberList->end(),
            [=](int x){return x % i==0;}),
          this->numberList->end()
          );
      this->numberList->push_back(i);
      std::cout << "生成中です... そのままでお待ちください..." << i << "/" << N << "　\r";
    }
  }
}

std::vector<int> nori::Eratosthenes::getPrimeList(){
  return *this->numberList;
};

void nori::Eratosthenes::setN(int N){
  this->N=N;
}

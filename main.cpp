#include <iostream>
#include <random>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include "Eratosthenes.h"

void generateQuiz(size_t* amount,std::string saveFilePath){
  std::ofstream outputFileStream(saveFilePath);

  char quizBody[1024];

  std::random_device seedGen;
  std::mt19937 engine(seedGen());

  std::uniform_real_distribution<> dist(-30.0	,30.0);

  outputFileStream << "*** IEEE 変換練習問題 *** \n\n\n";
  
  double rndDouble;
  bool isMinus;

  nori::Eratosthenes primeChecker;
  std::vector<int> primes;
  int denominator;

  for(unsigned int i=1;i<=*amount;i++){

    while(true){
      rndDouble=dist(engine);
      if(rndDouble<0){
        rndDouble=-rndDouble;
        isMinus=true;
      }
      denominator=((rndDouble-(int)rndDouble)*std::pow(10,std::to_string(rndDouble).length()-2));
      denominator=static_cast<int>(denominator);
      denominator/=100;

      primeChecker.setN(denominator);
      primeChecker.Start();
      primes=primeChecker.getPrimeList();

      std::erase_if(primes,[=](int p){return p==2 || p==5;});
      if(primes.size()==0){// もし2か5以外のものがなけらばループをぬける。
        break;
      }
    }
    if(isMinus){
      rndDouble=-rndDouble;
      isMinus=false;
    }
    std::sprintf(
        quizBody,
        "\nQuiz %d: %lfを変換してください。\n\n\n		",
        i,
        rndDouble);
    outputFileStream << quizBody;
  }
  outputFileStream.close();
}
int main(int argc,char** argv){

  std::cout << "*** IEEE 変換練習問題生成ツール ***" << std::endl;
  std::cout << "***           by h0tcat         ***" << std::endl;

  if(argc==1){
    size_t amountQuiz;

    std::cout << "いくつ問題を生成しますか? 半角数字で入力してください>>";
    std::cin >>amountQuiz;

    std::string saveFilePath;
    std::cout << "保存するファイル名を入力>>";
    std::cin >> saveFilePath;
    generateQuiz(&amountQuiz,saveFilePath);

    std::cout << "生成が終了しました" << std::endl;
  }else{
    size_t amountQuiz=std::stoi(argv[1]);
    generateQuiz(&amountQuiz,argv[2]);
  }
}

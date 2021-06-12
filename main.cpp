#include <iostream>
#include <random>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>

#include "Fraction.h"

void generateQuiz(size_t* amount,std::string saveFilePath){

    std::ofstream outputFileStream(saveFilePath);

    std::random_device seedGen;
    std::mt19937 engine(seedGen());
    std::uniform_real_distribution<> dist(-10.0	,10.0);

    nori::Fraction fraction;
    double rndDouble;
    char quizBody[1024];
    bool isMinus;

    outputFileStream << "*** IEEE 変換練習問題 *** \n\n\n";
    

    double logDouble;
    bool isInfinitieDouble=true;

    for(unsigned int i=1;i<=*amount;i++){


        while(isInfinitieDouble){
            rndDouble=dist(engine);

            isMinus = rndDouble < 0;
            if(isMinus){
                rndDouble = -rndDouble;
            }

            //分母と分子を分数クラスにセットする
            fraction.setDenominator(std::pow(10, std::to_string(rndDouble).length() - 3));
            fraction.setNumerator(rndDouble * fraction.getDenominator());


            fraction.reduce();
            logDouble = std::log2(fraction.getDenominator());
            isInfinitieDouble = (bool)logDouble - std::floor(logDouble);
        }
        isInfinitieDouble=true;

        //負の値に復元
        if(isMinus){
            rndDouble = -rndDouble;
        }
        //生成された有限桁の問題を表示
        std::sprintf(
                quizBody,
                "\nQuiz %d: %.2fを変換してください。\n\n\n		",
                i,
                rndDouble);
        outputFileStream << quizBody;
    }
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

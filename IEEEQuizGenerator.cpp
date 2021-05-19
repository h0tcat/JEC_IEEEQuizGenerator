#include <iostream>
#include <random>
#include <fstream>
#include <cstring>
#include <cstdlib>

void generateQuiz(size_t* amount,std::string saveFilePath){
	std::ofstream outputFileStream(saveFilePath);
	
	char quizBody[1024];

	std::random_device seedGen;
	std::mt19937 engine(seedGen());
	
	std::normal_distribution<double> dist(-30.0	,30.0);

	outputFileStream << "*** IEEE 変換練習問題 *** \n\n\n";
	for(unsigned int i=1;i<=*amount;i++){
		std::sprintf(
				quizBody,
				"\nQuiz %d: %.2fを変換してください。\n\n\n		",
				i,
				dist(engine)+5);
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

#pragma once
#include "save.h"

void save(std::string fname)
{
	// fname을 읽기 모드로 연다
	std::ifstream in(fname);
	if (!in) // 이름이 잘못됬을 경우
	{
		return;
	}

	// 기록할 파일을 덧붙여쓰기 모드로 연다
	std::ofstream out("STL_05_20190321.txt", std::ios::app);


	// 실행된 시간을 기록한다
	// 시간기원에서 몇tic이 흘렀나?
	auto tic = std::chrono::system_clock::now();

	// 이 값을 time_t로 변환
	auto time = std::chrono::system_clock::to_time_t(tic);

	// 이 값을 글자로 변환
	std::string date = ctime(&time);

	out << std::endl << std::endl;
	out << "==================" << std::endl;
	out << date << std::endl;
	out << "==================" << std::endl;


	// fname의 모든 내용을 덧붙여 쓴다
	std::copy(std::istreambuf_iterator<char>(in),
		std::istreambuf_iterator<char>(),
		std::ostreambuf_iterator<char>(out));//copy(어디부터, 어디까지, 어디로)

}
/* 시간을 재는 코드
using namespace std::chrono;
auto b = chrono::steady_clock::now();
cout << duration_cast<milliseconds>(steady_clock::now() - b).count() << endl;
*/
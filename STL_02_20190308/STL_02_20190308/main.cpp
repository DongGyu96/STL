#include <iostream>
#include <algorithm>
#include <random>
#include "save.h"
using namespace std; // namespace는 대규모 프로그래밍을 가정하고 사용하는것

//bool how(int a, int b)
//{
//	static int count = 0;
//	return a > b;
//}

int a[1000000]{ 1 };

int main()
{
	// 정수 10개를 정렬해보자
	//int a[] {1, 3, 5, 7, 9, 2, 4, 6, 8, 10}; // 초기화자 목록 Initialization List
	//Uniform Initialization

	//정수 1000개를 정렬해보자
	default_random_engine dre;
	uniform_int_distribution<> uid(0, 1000000);
	for (int& d : a)
	{
				//분포(엔진) pseudo랜덤(인위적인랜덤)
		d = uid(dre);
	}

	//ascending order : 오름차순 / descending order : 내림차순 정렬
	sort(begin(a), end(a), [](int a, int b) { return a < b; });//디폴트는 오름차순
	
	for (int d : a)
		cout << d << " ";
	cout << endl;

	save("main.cpp");
}
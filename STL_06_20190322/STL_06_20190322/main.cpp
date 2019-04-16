// Smart Pointer
//==============================================================
#include <iostream>
#include <random>
#include <algorithm>
#include <memory>
#include <string>
#include <list>
#include <iterator>
#include "save.h"
#include "String.h"
using namespace std;

// 62p 연습문제 1
// std::string 객체로 된 배열을 정의하고, 자신이 선택한 단어들로 
// 초기화 한 후에 반복자를 사용해 배열의 내용을 한줄에 하나씩 
// 출력하는 프로그램을 작성하라

// 62p 연습문제 2
// 각 원소에 transform() 알고리즈을 적용해 단어의 모든 소문자 모음을 
// '*'로 대체하고 표준 출력 스트림으로 한 줄에 하나씩 출력하는 프로그램을 
// 작성하라 문자열에 있는 모음을 대체하는 함수를 반복자를 사용하는 람다 표현식으로 정의하라

// 1. unique_ptr	- 자원을 독점한다
// 2. shared_ptr	- 자원을 공유한다 (비싼 자원)
void UniquePointer();
void Practice1();
void Practice2();

int main()
{
	// UniquePointer();
	// Practice1();
	Practice2();
	save("main.cpp");
}

void UniquePointer()
{
	// unique_ptr<String> a{ new String{20} };
	auto a = make_unique<String>(20);
	// unique_ptr<String> b{ new String{30} };
	unique_ptr<String>b = make_unique<String>(30);
	// a = b; // 자원을 독점하기 때문에 실행x
	cout << *a << endl;
	cout << *b << endl;

	cout << "몇 개나 만들까요 : ";
	int num;
	cin >> num;
	// unique_ptr<String[]> str{ new String[num] };
	auto str = make_unique<String[]>(num);

	default_random_engine dre;
	uniform_int_distribution<> uid(1, 80);

	for (int i = 0; i < num; ++i)
	{
		str[i].set(uid(dre));
	}

	sort(&str[0], &str[0] + num, [](const String& a, const String& b) {
		return a.getNum() > b.getNum();
	});

	for (int i = 0; i < num; ++i)
	{
		cout << str[i] << endl;
	}
}
void Practice1()
{
	// string s[5] { "3월", "22일", "미세먼지없음", "신기", "STL" };		// RAII (초기화 동작)
	list<string> s { "3월", "22일", "미세먼지없음", "신기", "STL" };

	auto p = begin(s);
	// *p : 역참조
	
	while (p != end(s))
		cout << *p++ << endl;
}
void Practice2()
{
	list<string> s{ "spring", "summner", "winter", "and", "fall" };

	// transform(어디서부터, 어디까지를, 어디로, 어떻게변형해서);
	transform(begin(s), end(s), ostream_iterator<string>(cout, "\n"),
		[](string& str) {
		for (char& c : str) {
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				c = '*';
		}
		return str;
	});
}
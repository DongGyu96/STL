// ====================================================
// 2장 순차 컨테이너 ( STL Sequence Container )
// - array			- 
// - vector			- 물리적으로 인접한 메모리공간 ( Contiguous )
// - deque			- 
// - list			-
// - forward_list	-
// ====================================================
#include<iostream>

//Practice2~3-----------
#include<string>
#include<set>
#include<algorithm>
#include<iterator>
//----------------------

//Array-----------------
#include<array>
//----------------------

#include "String.h"
#include "save.h"
using namespace std;


void Practice2();
void Practice3();
void Array();

int main()
{
	//Practice2();
	//Practice3();
	Array();
	save("main.cpp");
}

void Practice2()
{
	string s[5] { "spring", "summer", "winter", "and", "fall" };
	// set<string> s { "spring", "summer", "winter", "and", "fall" };
	// 자료구조가 달라져도 첫 원소가 무엇인지 받을 수 있다면 유효한 코드가 된다.
	//auto p = begin(s);
	//while (p != end(s))
	//{
	//	// *p : 역참조연산자
	//	cout << *p++ << endl;
	//}

	transform(begin(s), end(s), ostream_iterator<string>(cout, "\n"),
		[](string& str) {
		for (auto p = begin(str); p != end(str); ++p)
			if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u')
				*p = '*';
		return str;
	});

	for (int i = 0; i < 5; ++i)
		cout << s[i] << endl;

}

void Practice3()
{
	// string s[5]{ "spring", "summer", "winter", "and", "fall" };
	String s[5]{ 10, 20, 30, 40, 50 };

	// transform(어디서부터, 어디까지, 어디로, 어떻게);
	transform(begin(s), end(s), ostream_iterator<String>(cout, "\n"),
		[](String& str) {
		transform(str.getP(), str.getP() + str.getNum(), str.getP(), [](char c) {
			c = toupper(c);
			return c;
		});
		return str;
	});
}

void Array()
{
	// 모든 STL컨테이너는 반복자를 통해 원소에 접근한다
	// 컨테이너 Array는 어디에 사용하는게 좋은가?
	// int a[5];
	array<int, 5> a { 1, 2, 3, 4, 5 };
	// 만약 생성자의 인자가 2개이상일 경우 {}로 한번더 묶어준다
	// array<int, 3> a { { 1 , 2 }, { 3, 4 }, { 5, 6 } };

	// STL은 검사를 하지 않기 때문에 범위를 벗어나도 오류가 발생하지 않는다
	while (false) {
		cout << "몇번째 값 : ";
		int num;
		cin >> num;
		// cout << a[num] << endl;
		// 만약 검사가 필요하다면 at(index)를 사용한다.
		// cout << a.at(num) << endl;
		try {
			cout << a.at(num) << endl;
		}
		// 예외를 받아서 처리하는 부분
		catch (exception& e) {
			cout << e.what() << endl;
		} // 그러나 잘 사용하지 않는다
	}

	// array는 크기가 변경되지 않는다.
	//array<int, 5> b;
	//array<int, 6> c{ 3 };
	//b = c;

	array<String, 5> b{ 55, 60, 65, 70, 75 };

	for (auto i = b.begin(); i != b.end(); ++i) // 반드시 ++i여야만 함
		cout << *i << endl; // i의 역참조로 접근해야한다
	cout << endl << endl;
	// a를 사전순으로 정렬하라
	for (int i = 0; i < b.size(); ++i)
	{
		sort(b[i].getP(), b[i].getP() + b[i].getNum());
	}

	for (auto i = b.begin(); i != b.end(); ++i)
		cout << *i << endl;
}
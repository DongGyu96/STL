// =========================================================
// 2장 순차 컨테이너
//   array
//   vector
//   deque
//   list : 여기서부터 원소 하나 보다 더 큰 메모리가 필요하다
//   forward_list : 뒤로 다시 돌아갈 일이 없는 리스트에서 사용
//						반복자 어댑터
// =========================================================
#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <string>
#include "save.h"
#include "String.h"
using namespace std;

// list에 String 객체 10, 20, 30을 추가하자
// 길이가 20의 배수인 객체를 삭제하라
// 길이가 홀수인 객체를 삭제하라
// 화면에 list의 원소 전체를 출력하라
void List();

// "소스.cpp"의 단어를 읽어라
// 길이 순으로 정렬하라 따로 말이 없다면 오름차순 정렬을 의미
// 길이가 4인 단어를 따로 빼서 "길이4.txt"에 저장하라
void List2();

void print(list<int>::iterator a, list<int>::iterator b);
void print(list<String>::iterator a, list<String>::iterator b);
// copy() 알고리즘을 만들어보자

int main()
{
	// 반복자 어댑터

	list<String> data{ 1,2,3,4,5 };

	print(data.begin(), data.end()); // 화면에 한줄에 하나씩 1, 2, 3, 4, 5씩 출력함

	save("main.cpp");
}

void print(list<int>::iterator a, list<int>::iterator b)
{
	//copy(a, b, ostream_iterator<int>(cout, "\n"));
	//for (auto& p = a; p != b; ++p)
	//	cout << *p << endl;
	while (a != b)
		cout << *a++ << endl;
}
void print(list<String>::iterator a, list<String>::iterator b)
{
	while (a != b)
		cout << *a++ << endl;
}

void List()
{
	//list<String> strings{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//
	////auto p = remove_if(strings.begin(), strings.end(), [](const String& str){
	////	// str.getNum()%1 == 1; 이면 홀수 / 비트의 오른쪽값이 1이다
	////	return str.getNum() % 2 == 1;
	////});
	////strings.erase(p, strings.end());
	//// 위와 같은 경우는 해당 메모리의 값을 삭제후 뒤의 값을 앞으로 이동시키는 연산을 함
	//// 그러나 list에서는 그런 연산을 할 필요가 없음 list만의 장점을 이용하지 않는 경우
	//
	//strings.remove_if([](const String& str) {return str.getNum() & 1; });
	//
	//for (const String& d : strings)
	//	cout << d << endl;


	// 리스트에 특화된 경우
	// 서로 다른 리스트 합치기 ( 중복 계산 )
	list<String> str1{ 3,1,7,8,3,2 };
	list<String> str2{ 2,9,1,1,6,4,5,3,3 };

	// merge는 정렬한 list에 사용하는 것이다.
	str1.sort();
	str2.sort();
	// sort또한 < 연산자를 이용한다

	// str1에 str2를 merge하라 ( 합치기 )
	// 조건을 위해서는 operator< 가 정의되있어야함
	str1.merge(str2);
	// str2의 내용은 지워짐

	// 그러나 중복된 내용이 많은데 하나씩 남기는 방법은 unique 함수가 있다
	str1.unique();
	// == 연산자가 필요하다

	cout << " ------------------------ " << endl;
	for (const String& d : str1)
		cout << d << endl;
	cout << " ------------------------ " << endl;
	for (const String& d : str2)
		cout << d << endl;
	cout << " ------------------------ " << endl;
}

void List2()
{
	ifstream in("main.cpp");

	//list<string> strings{ istream_iterator<string>(in), istream_iterator<string>() };
	istream_iterator<string> p(in);
	list<string> words;
	list<string> words_4;

	while (p != istream_iterator<string>())
	{
		words.emplace(words.end(), *p++);
	}
	words.sort([](const string& a, const string& b) {return a.length() < b.length(); });


	auto pos4 = find_if(words.begin(), words.end(), [](const string& str) {
		return str.length() == 4;
	});
	// auto pos4 == list<string>::iterator pos4
	if (pos4 == words.end()) {
		cout << "길이4가 없음" << endl;
	}
	auto pos5 = find_if(words.begin(), words.end(), [](const string& str) {
		return str.length() == 5;
	});

	// [pos4, pos5]는 우리가 원하는 구간이다
	// list의 splice를 사용하여 옮겨보자
	words_4.splice(words_4.begin(), words, pos4, pos5);

	copy(words.begin(), words.end(), ostream_iterator<string>(cout, "\n"));

	ofstream out("길이4.txt");
	out << "<";
	copy(words_4.begin(), words_4.end(), ostream_iterator<string>(out, ">\n<"));

	out.close();
	in.close();
}
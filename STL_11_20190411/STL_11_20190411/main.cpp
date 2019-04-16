// =====================================================
// 2장 순차 컨테이너
// - deque : 편리하려고 속도를 아주 조금 희생하였다.
//
// - list : 여기부터는 원소 하나 보다 더 큰 메모리가 필요하다 편리함을 위해서
// - forward_list
// =====================================================
#include <iostream>
#include "save.h"
#include "String.h"

#include <list>

#include <algorithm>
#include <fstream>
#include <deque>
#include <vector>
using namespace std;

// 소스파일을 뒤에서 부터 출력하라
void createcpp();
void printcpp();

// list에 String 객체 10, 20, 30을 추가하자

// 길이가 20의 배수인 객체를 삭제하라

// 화면에 list의 원소 전체를 출력하라

int main()
{
	list<String> strings;
	//strings.emplace_back(30);
	//strings.emplace_back(20);
	//strings.emplace_back(10);

	auto p = strings.emplace(strings.begin(), 10);
	p = strings.emplace(strings.begin(), 20);
	p = strings.emplace(strings.begin(), 30);

	cout << endl;
	//for (auto i = strings.begin(); i != strings.end(); ++i)
	//	cout << *i << endl;
	//for (auto& d : strings) // 가독성이 떨어짐 auto&& 도 복사방지 기능
	//	cout << d << endl;
	for (const String& d : strings)
		cout << d << endl;
	cout << endl;


	save("main.cpp");
}

void createcpp()
{
	ifstream in("main.cpp");
	if (!in)
		return;

	vector<char> v{ istreambuf_iterator<char>(in), istreambuf_iterator<char>() };
	// 특정 글자를 지운다
	/*auto p = remove_if(v.begin(), v.end(), [](const char e) {
	return e == 'e';
	});
	v.erase(p, v.end());*/ 


	ofstream out("거꾸로소스.cpp");
	copy(v.rbegin(), v.rend(), ostreambuf_iterator<char>(out));

	out.close();
	in.close();
}
void printcpp()
{
	ifstream in("main.cpp");
	deque<char> d;

	copy(istreambuf_iterator<char>(in), istreambuf_iterator<char>(),
		// 덱의 앞쪽에 insert, copy가 넣는게 아닌 삽입 반복자 어댑터를 통해 덱이 직접 집어넣도록
		front_inserter(d)
	);

	copy(d.begin(), d.end(), ostreambuf_iterator<char>(cout));
}
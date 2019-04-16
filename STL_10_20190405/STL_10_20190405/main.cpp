// =========================================================
//	2장 순차 컨테이너
//   array
//   vector			STL 대표 선수
// - deque			
// - list
// - forward_list
//
// 반복자 어댑터 설명이 필요하다
// ==========================================================
#include <iostream>
#include <deque>
#include "save.h"
#include "String.h"
using namespace std;

// "소스.cpp"에서 e를 제거한 결과를 "e없는소스.cpp"에 저장하라
// remove_if 로 e를 제거한다
// 공백까지 처리하기 위해 istreambuf_iterator, ostreambuf_iterator를 사용

// "소스.cpp"를 거꾸로 기록한 "거꾸로소스.cpp"에 저장하라

// 입력 : 소스.cpp
// 출력 : 단어역순.cpp
// 단어의 글자를 역순으로


// "덱"의 앞쪽에 String자료형 10, 20, 30을 넣고 출력해보시오
int main()
{
	/*ifstream in("main.cpp");
	if (!in)
		return 1;

	vector<char> v{ istreambuf_iterator<char>(in), istreambuf_iterator<char>() };
	auto p = remove_if(v.begin(), v.end(), [](const char e) {
		return e == 'e';
	});
	v.erase(p, v.end());

	ofstream out("e없는소스.cpp");
	copy(v.begin(), v.end(), ostreambuf_iterator<char>(out));

	out.close();
	in.close();*/

	deque<String> d;
	// sizeof(d)는 40바이트

	d.emplace_back(10);
	d.emplace_back(20);
	d.emplace_back(30);
	d.emplace_back(40);
	d.emplace_back(50);
	d.emplace_back(60);
	d.emplace_back(70);
	d.emplace_back(80);
	d.emplace_back(90);
	// 넣은 값들의 메모리 주소는 vector와 달리 붙어있지 않음
	// 메모리를 한블록씩 여러개를 이어붙인 형식
	//for (auto i = d.begin(); i < d.end(); ++i)
	//	cout << *i << endl;
	// 메모리가 연속적으로 이어져있지 않고 조각조각 나뉘어있기 때문에 위와 같은 포문은 해선안됨
	// ++i를 할경우 d의 메모리주소를 계산해야 하기때문에 불필요한 연산 발생


	for (auto& i : d)
	cout << i << endl;

	save("main.cpp");
}

/*vector<String> v;
v.reserve(10);

v.emplace_back(10);
v.emplace_back(20);
v.emplace_back(30);

cout << "--------------------------" << endl << endl << endl;
// 중간에 길이가 20인 String을 추가하자. 메모리는 어떻게 사용될까?
// v.emplace(v.begin() + 1, 20);

// 길이가 20인 String을 삭제하라. 메모리는 어떻게 바뀔까?
// v.erase();
// vector는 자료를 담는 자료구조이므로 메모리를 관리하는데에 치중하고
// 알고리즘은 다른곳에서 다룬다
// auto p = remove(v.begin(), v.end(), 20);
//		== remove(v.begin(), v.end(), String(20))
//					어디부터 어디까지 무엇을

// 20은 지워졌으나 v의 사이즈는 줄어들지 않았음
// 자신의 size값을 변경해주는 것은 자기 자신만 가능하도록
// 따라서 remove()에는 return값이 존재해서 자료구조에게 알려줄 수 있음
// v.erase(p, v.end());

// 즉
// erase-remove idiom
v.erase(remove(v.begin(), v.end(), String(20)), v.end());
// 객체가 래퍼런스로 넘어갔기 떄문에 String(20)은 생성이 한번만 되지만
// 숫자 20으로 넘어갔을경우 객체를 만들어서 계속 비교한다

cout << endl << endl << "--------------------------" << endl;

for (int i = 0; i < v.size(); ++i)
cout << v[i] << endl;*/
// =================================================================================
// 2장 순차 컨테이너 ( Sequence Container  - homogeneous data type 동일 자료형)
// - array			: 유일하게 자료의 갯수가 고정됨
// - vector			: dynamic array
// - deque			:
// - list			:
// - forward_list	:
// =================================================================================
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "save.h"
#include "String.h"
using namespace std;

// 잘짠 프로그램은 요구사항이 변경되도 최소한의 코드수정으로 가능해야 한다
// array같은 stl을 사용하면 일반 배열을 사용한것보다 최소한의 코드 수정이 가능
// 프로그램의 유연성

// 비어있는 v에 String 20 개를 추가하라
// String의 값은 uid(10, 70)으로 초기화하라
// String의 문자를 오름차순으로 정렬하라
// v를 String의 길이 오름차순으로 정렬하라
// 결과를 화면 출력하라

int main()
{
	// vector<자료형> 변수명; (n)갯수 {n}초기화
	// vector<> 자체도 하나의 자료형
	// vecotr < vector < vector < vector<String> > > > v;
	// vector<int> b; // sizeof(vertor<int>) : 12바이트
	vector<String> v; // 마찬가지로 12바이트 포인터이기 때문

	// v.push_back(String{40});
	// v.push_back(40);

	while (false)
	{
		cout << "벡터의 원소 갯수			: " << v.size() << endl;
		cout << "재할당 없이 담을 수 있는 원소의 갯수	: " << v.capacity() << endl;
		cout << "원소가 저장되어 있는 위치		: " << v.data() << endl;; // 메모리 포인터
		// 첫번째 원소의 주소값

		int prev = v.capacity();
		char c;
		cin >> c;
		v.push_back(10);
		if (v.capacity() - prev != 0) {
			// 재할당 없이 담을수 있는 원소의 개수는 이전 원소의 갯수보다 1.5배 증가한다
			cout << endl << endl << "차이 : " << v.capacity() - prev << endl << endl << endl;
		}

	}

	// String *p = v.data(); // v.data() 첫번째 원소의 주소값
	// ++p;
	// ++p;
	// cout << *p << endl; // v[2];

	default_random_engine dre;
	uniform_int_distribution<> uid(10, 70);

	// 메모리의 공간을 미리 확보하는 방법
	// v.capacity()를 확보하는 방법
	v.reserve(20);
	for (int i = 0; i < 20; ++i) {
		// vector<String> v; 일경우 매 반복마다 메모리를 다시 확보하기 떄문에 쓰레기 알고리즘
		//v.push_back(uid(dre)); // v,push_back(String{uid(dre)}; 로 들어감
		v.push_back(String{ uid(dre) });
	}

	// for(auto& d : v) ==
	//for (String *p = v.data(); p < v.data() + v.size(); ++p) {
	//	sort(p->getP(), p->getP() + p->getNum());
	//} ==
	for (auto i = v.begin(); i != v.end(); ++i) {
		sort(i->getP(), i->getP() + i->getNum());
	}

	sort(v.begin(), v.end(), [](const String& a, const String& b) { return a.getNum() < b.getNum(); });

	//for (int i = 0; i < v.size(); ++i) {
	//	cout << v[i] << endl;
	//}
	// 범위기반의 for루프 for(auto& d : v)
	for (const String& d : v)
		cout << d << endl;

	save("main.cpp");
}
// ==================================================
//
// Associative Containers			(연관 컨테이너)
// - map : dictionary, <key, Value>쌍이 한개의 원소가 됨 (탐색 : O(log n))
// - set : Key가 원소
//
// Unordered Associative Containers	(순서없는 연관 컨테이너) ex) Hash
// 메모리를 대량으로 희생해서 속도를 비약적으로 늘림 (탐색 : O(1))
// - unordered_map
// - unordered_set
//
// ==================================================
#include <iostream>
#include <map>
#include <iomanip>
#include <algorithm>

#include <fstream>
#include <iterator>

#include "String.h"
#include "save.h"
using namespace std;

// 아이돌그룹과 멤버 수
// map<key, value>
// default는 오름차순으로 정렬
// map<string, int, operator<()> idols;
map<string, int> idols;

// main.cpp에 사용된 알파벳과 사용횟수를 출력하라
map<char, int> alphaNum;

int main()
{
	//pair<string, int> p{ "C++", 17 };
	//cout << p.first << ", " << p.second << endl;

	// 트리구조이기 때문에 insert나 emplace로만 넣을 수 있음
	//idols.insert(pair<string, int>("방탄소년단", 7));
	idols.insert(make_pair("방탄소년단", 7));
	idols.insert(make_pair("있지", 5));
	idols.insert(make_pair("아이즈원", 12));
	idols.insert(make_pair("워너원", 11));
	idols.insert(make_pair("모모랜드", 9));
	idols.insert(make_pair("블랙핑크", 4));
	idols.insert(make_pair("트와이스", 9));
	idols.insert(make_pair("에프엑스", 4));
	// 출력해보자
//	for (auto i = idols.begin(); i != idols.end(); ++i)
//		cout << setw(20) << left << i->first << "의 멤버 수는 " << (*i).second << endl;

	// range based for loop
//	for (const pair<string, int>& d : idols) // 매번 복사하는 문제를 발생시키지 않도록 &(번지)를 가져옴
//	{ // 그러나 &만 붙인다면 키값을 변경이 될 가능성이 있어 트리가 깨지기 때문에 const를 반드시 작성
//		cout << setw(20) << left << d.first << "의 멤버 수는 " << d.second << endl;
//	}
//	cout << endl << endl;

	// 맵에서 원하는 자료를 찾아보자
//	auto p = idols.find("방탄소년단");
//	if (p != idols.end())
//		cout << p->first << ", " << p->second << endl;

	// 사용자가 입력한 그룹의 인원수를 출력해보자
	// 없으면 인원수를 받아서 추가한다
	while (0)
	{
		cout << "입력할 그룹의 이름 : ";
		string name;
		cin >> name;
		auto p = idols.find(name);
		if (p != idols.end())
			cout << setw(20) << left << p->first << "의 인원 수 " << p->second << endl << endl;
		else
		{
			cout << name << "의 멤버 수 : ";
			int num;
			cin >> num;

			//idols.insert(make_pair(name, num));
			idols[name] = num; // 연관 배열 존재 하지 않는다면 원소를 삽입하는 용도로 사용

			cout << endl;
		}
	}



	ifstream in("main.cpp");
	for (auto i = istream_iterator<char>(in); i != istream_iterator<char>(); ++i)
		if(isalpha(*i)) alphaNum[islower(*i)]++;

	for (const auto& d : alphaNum)
		cout << "[" << d.first << "] -> " << d.second << endl;

	save("main.cpp");
}
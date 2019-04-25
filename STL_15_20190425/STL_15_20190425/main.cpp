// ====================================================
// 연관 컨테이너 ( 원소를 빨리 찾기 위한 컨테이너 )
//
//
// ====================================================
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include "save.h"
#include "String.h"
using namespace std;

map<char, int> alphaNum;
void CountNum(); // 문자 빈도수 측정

// "이상한 나라의 앨리스"에 사용된 단어와 사용횟수를 출력하라
// 사용된 단어를 사용 횟수 오름차순으로 출력하라

int main()
{
	map<string, int> words;

	// multimap<int, string> count; // 동일 키값 중복 허용
	// 그러나 vector를 쓰는게 훨씬 빠르다 ( 집어넣을때마다 정렬을 한다 )
	// 벡터에 한번에 넣은 후 정렬이 효율적
	/*for (const pair<string, int>& d : words)
	{
	count.emplace(d.second, d.first);

	}
	for (const auto& d: count)
	cout << d.second << " --> " << d.first << endl;*/

	ifstream inOld("alice.txt"); // 그러나 앨리스라는 책에는 기호가 많이 사용됨
	// replaceif 라는 것을 사용한다면 ( 알파벳으로 이루어진 단어만 처리하도록 입력 파일 가공 )
	// 입력 파일에서 알파벳이 아닌 문자는 공백으로 대체한다
	ofstream out("New_Alice.txt");

	// 두가지 방법	replace_if, transform
	//vector<char> word{ istreambuf_iterator<char>(inOld), istreambuf_iterator<char>() };
	//replace_if(word.begin(), word.end(), [](char c) {
	//	return !isalpha(c);
	//}, ' ');
	//copy(word.begin(), word.end(), ostreambuf_iterator<char>(out));

	//transform(입력시작, 입력끝, 목적지, 변신방법);
	transform(istreambuf_iterator<char>(inOld), istreambuf_iterator<char>(), ostream_iterator<char>(out), [](const char& c) {
		if (!isalpha(c) && c != '\n') return ' ';
		return c;
	});

	inOld.close();
	out.close();
	ifstream inNew("New_Alice.txt");
	for (auto i = istream_iterator<string>(inNew); i != istream_iterator<string>(); ++i)
	{
		words[*i]++;
	} // 단어 횟수 체크

	vector<pair<string, int>> v{ words.begin(), words.end() }; // 처음부터 끝까지 삽입

	sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b){
		return a.second > b.second;
	}); // 정렬

	for (int i = 0; i < 20; ++i)
	{
		cout << v[i].first << " --> " << v[i].second << endl;
	}

	cout << "전체 단어 수 " << words.size() << endl;
	// cout << "횟수로 정렬한 맵의 원소 수 " << count.size() << endl;
	cout << "횟수로 정렬한 벡터의 원소 수 " << v.size() << endl << endl;

	inNew.close();



	// "알파벳만 남긴 앨리스.txt"에 사용된 단어와 횟수를 알고 있다.
	// 사용자가 입력한 단어가 몇번 사용되었는가 출력하라
	while (0)
	{
		string input;
		cout << "검색하려는 단어 : ";
		cin >> input;

		//auto p = find_if(words.begin(), words.end(), [&input](const pair<string, int>& d) {
		//	return input == d.first;
		//});
		auto p = words.find(input);
		if (p != words.end())
			cout << input << "의 사용 횟수 : " << p->second << endl;
		else
			cout << input << "는 앨리스에 없는 단어입니다" << endl;

		// cout << "검색하려는 단어 : " << input << " --> " << words[input] << endl;
	}

	// "알파벳만 남긴 앨리스.txt"에 사용된 단어를 오름차순으로 컨테이너에 저장하자
	ifstream in ("New_Alice.txt");
	map<string, int> chars;

	for (auto i = istream_iterator<string>(in); i != istream_iterator<string>(); ++i)
		chars.emplace(*i, 1);

	// 정렬된 단어를 파일에 기록하자
	ofstream fout("단어 오름차순 정렬한 앨리스.txt");

	for (const pair<string, int>& d : chars)
		fout << d.first << endl;

	in.close();
	fout.close();
	// 단어가 정렬되어 있다 a로 시작하는 단어는 몇개인가?

	save("main.cpp");
}

void CountNum()
{
	ifstream in("main.cpp");
	for (auto i = istream_iterator<char>(in); i != istream_iterator<char>(); ++i)
	{
		alphaNum[*i]++;
	}
	for (const auto& d : alphaNum)
		cout << "[" << d.first << "] --> " << d.second << endl;
}
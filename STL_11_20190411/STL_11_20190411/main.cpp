// =====================================================
// 2�� ���� �����̳�
// - deque : ���Ϸ��� �ӵ��� ���� ���� ����Ͽ���.
//
// - list : ������ʹ� ���� �ϳ� ���� �� ū �޸𸮰� �ʿ��ϴ� ������ ���ؼ�
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

// �ҽ������� �ڿ��� ���� ����϶�
void createcpp();
void printcpp();

// list�� String ��ü 10, 20, 30�� �߰�����

// ���̰� 20�� ����� ��ü�� �����϶�

// ȭ�鿡 list�� ���� ��ü�� ����϶�

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
	//for (auto& d : strings) // �������� ������ auto&& �� ������� ���
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
	// Ư�� ���ڸ� �����
	/*auto p = remove_if(v.begin(), v.end(), [](const char e) {
	return e == 'e';
	});
	v.erase(p, v.end());*/ 


	ofstream out("�Ųٷμҽ�.cpp");
	copy(v.rbegin(), v.rend(), ostreambuf_iterator<char>(out));

	out.close();
	in.close();
}
void printcpp()
{
	ifstream in("main.cpp");
	deque<char> d;

	copy(istreambuf_iterator<char>(in), istreambuf_iterator<char>(),
		// ���� ���ʿ� insert, copy�� �ִ°� �ƴ� ���� �ݺ��� ����͸� ���� ���� ���� ����ֵ���
		front_inserter(d)
	);

	copy(d.begin(), d.end(), ostreambuf_iterator<char>(cout));
}
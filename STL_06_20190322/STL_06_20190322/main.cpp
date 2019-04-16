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

// 62p �������� 1
// std::string ��ü�� �� �迭�� �����ϰ�, �ڽ��� ������ �ܾ��� 
// �ʱ�ȭ �� �Ŀ� �ݺ��ڸ� ����� �迭�� ������ ���ٿ� �ϳ��� 
// ����ϴ� ���α׷��� �ۼ��϶�

// 62p �������� 2
// �� ���ҿ� transform() �˰����� ������ �ܾ��� ��� �ҹ��� ������ 
// '*'�� ��ü�ϰ� ǥ�� ��� ��Ʈ������ �� �ٿ� �ϳ��� ����ϴ� ���α׷��� 
// �ۼ��϶� ���ڿ��� �ִ� ������ ��ü�ϴ� �Լ��� �ݺ��ڸ� ����ϴ� ���� ǥ�������� �����϶�

// 1. unique_ptr	- �ڿ��� �����Ѵ�
// 2. shared_ptr	- �ڿ��� �����Ѵ� (��� �ڿ�)
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
	// a = b; // �ڿ��� �����ϱ� ������ ����x
	cout << *a << endl;
	cout << *b << endl;

	cout << "�� ���� ������ : ";
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
	// string s[5] { "3��", "22��", "�̼���������", "�ű�", "STL" };		// RAII (�ʱ�ȭ ����)
	list<string> s { "3��", "22��", "�̼���������", "�ű�", "STL" };

	auto p = begin(s);
	// *p : ������
	
	while (p != end(s))
		cout << *p++ << endl;
}
void Practice2()
{
	list<string> s{ "spring", "summner", "winter", "and", "fall" };

	// transform(��𼭺���, ��������, ����, ��Ժ����ؼ�);
	transform(begin(s), end(s), ostream_iterator<string>(cout, "\n"),
		[](string& str) {
		for (char& c : str) {
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				c = '*';
		}
		return str;
	});
}
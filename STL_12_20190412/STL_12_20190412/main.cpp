// =========================================================
// 2�� ���� �����̳�
//   array
//   vector
//   deque
//   list : ���⼭���� ���� �ϳ� ���� �� ū �޸𸮰� �ʿ��ϴ�
//   forward_list : �ڷ� �ٽ� ���ư� ���� ���� ����Ʈ���� ���
//						�ݺ��� �����
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

// list�� String ��ü 10, 20, 30�� �߰�����
// ���̰� 20�� ����� ��ü�� �����϶�
// ���̰� Ȧ���� ��ü�� �����϶�
// ȭ�鿡 list�� ���� ��ü�� ����϶�
void List();

// "�ҽ�.cpp"�� �ܾ �о��
// ���� ������ �����϶� ���� ���� ���ٸ� �������� ������ �ǹ�
// ���̰� 4�� �ܾ ���� ���� "����4.txt"�� �����϶�
void List2();

void print(list<int>::iterator a, list<int>::iterator b);
void print(list<String>::iterator a, list<String>::iterator b);
// copy() �˰����� ������

int main()
{
	// �ݺ��� �����

	list<String> data{ 1,2,3,4,5 };

	print(data.begin(), data.end()); // ȭ�鿡 ���ٿ� �ϳ��� 1, 2, 3, 4, 5�� �����

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
	////	// str.getNum()%1 == 1; �̸� Ȧ�� / ��Ʈ�� �����ʰ��� 1�̴�
	////	return str.getNum() % 2 == 1;
	////});
	////strings.erase(p, strings.end());
	//// ���� ���� ���� �ش� �޸��� ���� ������ ���� ���� ������ �̵���Ű�� ������ ��
	//// �׷��� list������ �׷� ������ �� �ʿ䰡 ���� list���� ������ �̿����� �ʴ� ���
	//
	//strings.remove_if([](const String& str) {return str.getNum() & 1; });
	//
	//for (const String& d : strings)
	//	cout << d << endl;


	// ����Ʈ�� Ưȭ�� ���
	// ���� �ٸ� ����Ʈ ��ġ�� ( �ߺ� ��� )
	list<String> str1{ 3,1,7,8,3,2 };
	list<String> str2{ 2,9,1,1,6,4,5,3,3 };

	// merge�� ������ list�� ����ϴ� ���̴�.
	str1.sort();
	str2.sort();
	// sort���� < �����ڸ� �̿��Ѵ�

	// str1�� str2�� merge�϶� ( ��ġ�� )
	// ������ ���ؼ��� operator< �� ���ǵ��־����
	str1.merge(str2);
	// str2�� ������ ������

	// �׷��� �ߺ��� ������ ������ �ϳ��� ����� ����� unique �Լ��� �ִ�
	str1.unique();
	// == �����ڰ� �ʿ��ϴ�

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
		cout << "����4�� ����" << endl;
	}
	auto pos5 = find_if(words.begin(), words.end(), [](const string& str) {
		return str.length() == 5;
	});

	// [pos4, pos5]�� �츮�� ���ϴ� �����̴�
	// list�� splice�� ����Ͽ� �Űܺ���
	words_4.splice(words_4.begin(), words, pos4, pos5);

	copy(words.begin(), words.end(), ostream_iterator<string>(cout, "\n"));

	ofstream out("����4.txt");
	out << "<";
	copy(words_4.begin(), words_4.end(), ostream_iterator<string>(out, ">\n<"));

	out.close();
	in.close();
}
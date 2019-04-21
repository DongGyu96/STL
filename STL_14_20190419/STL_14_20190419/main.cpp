// ==================================================
//
// Associative Containers			(���� �����̳�)
// - map : dictionary, <key, Value>���� �Ѱ��� ���Ұ� �� (Ž�� : O(log n))
// - set : Key�� ����
//
// Unordered Associative Containers	(�������� ���� �����̳�) ex) Hash
// �޸𸮸� �뷮���� ����ؼ� �ӵ��� ��������� �ø� (Ž�� : O(1))
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

// ���̵��׷�� ��� ��
// map<key, value>
// default�� ������������ ����
// map<string, int, operator<()> idols;
map<string, int> idols;

// main.cpp�� ���� ���ĺ��� ���Ƚ���� ����϶�
map<char, int> alphaNum;

int main()
{
	//pair<string, int> p{ "C++", 17 };
	//cout << p.first << ", " << p.second << endl;

	// Ʈ�������̱� ������ insert�� emplace�θ� ���� �� ����
	//idols.insert(pair<string, int>("��ź�ҳ��", 7));
	idols.insert(make_pair("��ź�ҳ��", 7));
	idols.insert(make_pair("����", 5));
	idols.insert(make_pair("�������", 12));
	idols.insert(make_pair("���ʿ�", 11));
	idols.insert(make_pair("��𷣵�", 9));
	idols.insert(make_pair("����ũ", 4));
	idols.insert(make_pair("Ʈ���̽�", 9));
	idols.insert(make_pair("��������", 4));
	// ����غ���
//	for (auto i = idols.begin(); i != idols.end(); ++i)
//		cout << setw(20) << left << i->first << "�� ��� ���� " << (*i).second << endl;

	// range based for loop
//	for (const pair<string, int>& d : idols) // �Ź� �����ϴ� ������ �߻���Ű�� �ʵ��� &(����)�� ������
//	{ // �׷��� &�� ���δٸ� Ű���� ������ �� ���ɼ��� �־� Ʈ���� ������ ������ const�� �ݵ�� �ۼ�
//		cout << setw(20) << left << d.first << "�� ��� ���� " << d.second << endl;
//	}
//	cout << endl << endl;

	// �ʿ��� ���ϴ� �ڷḦ ã�ƺ���
//	auto p = idols.find("��ź�ҳ��");
//	if (p != idols.end())
//		cout << p->first << ", " << p->second << endl;

	// ����ڰ� �Է��� �׷��� �ο����� ����غ���
	// ������ �ο����� �޾Ƽ� �߰��Ѵ�
	while (0)
	{
		cout << "�Է��� �׷��� �̸� : ";
		string name;
		cin >> name;
		auto p = idols.find(name);
		if (p != idols.end())
			cout << setw(20) << left << p->first << "�� �ο� �� " << p->second << endl << endl;
		else
		{
			cout << name << "�� ��� �� : ";
			int num;
			cin >> num;

			//idols.insert(make_pair(name, num));
			idols[name] = num; // ���� �迭 ���� ���� �ʴ´ٸ� ���Ҹ� �����ϴ� �뵵�� ���

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
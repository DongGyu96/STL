// ====================================================
// ���� �����̳� ( ���Ҹ� ���� ã�� ���� �����̳� )
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
void CountNum(); // ���� �󵵼� ����

// "�̻��� ������ �ٸ���"�� ���� �ܾ�� ���Ƚ���� ����϶�
// ���� �ܾ ��� Ƚ�� ������������ ����϶�

int main()
{
	map<string, int> words;

	// multimap<int, string> count; // ���� Ű�� �ߺ� ���
	// �׷��� vector�� ���°� �ξ� ������ ( ������������� ������ �Ѵ� )
	// ���Ϳ� �ѹ��� ���� �� ������ ȿ����
	/*for (const pair<string, int>& d : words)
	{
	count.emplace(d.second, d.first);

	}
	for (const auto& d: count)
	cout << d.second << " --> " << d.first << endl;*/

	ifstream inOld("alice.txt"); // �׷��� �ٸ������ å���� ��ȣ�� ���� ����
	// replaceif ��� ���� ����Ѵٸ� ( ���ĺ����� �̷���� �ܾ ó���ϵ��� �Է� ���� ���� )
	// �Է� ���Ͽ��� ���ĺ��� �ƴ� ���ڴ� �������� ��ü�Ѵ�
	ofstream out("New_Alice.txt");

	// �ΰ��� ���	replace_if, transform
	//vector<char> word{ istreambuf_iterator<char>(inOld), istreambuf_iterator<char>() };
	//replace_if(word.begin(), word.end(), [](char c) {
	//	return !isalpha(c);
	//}, ' ');
	//copy(word.begin(), word.end(), ostreambuf_iterator<char>(out));

	//transform(�Է½���, �Է³�, ������, ���Ź��);
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
	} // �ܾ� Ƚ�� üũ

	vector<pair<string, int>> v{ words.begin(), words.end() }; // ó������ ������ ����

	sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b){
		return a.second > b.second;
	}); // ����

	for (int i = 0; i < 20; ++i)
	{
		cout << v[i].first << " --> " << v[i].second << endl;
	}

	cout << "��ü �ܾ� �� " << words.size() << endl;
	// cout << "Ƚ���� ������ ���� ���� �� " << count.size() << endl;
	cout << "Ƚ���� ������ ������ ���� �� " << v.size() << endl << endl;

	inNew.close();



	// "���ĺ��� ���� �ٸ���.txt"�� ���� �ܾ�� Ƚ���� �˰� �ִ�.
	// ����ڰ� �Է��� �ܾ ��� ���Ǿ��°� ����϶�
	while (0)
	{
		string input;
		cout << "�˻��Ϸ��� �ܾ� : ";
		cin >> input;

		//auto p = find_if(words.begin(), words.end(), [&input](const pair<string, int>& d) {
		//	return input == d.first;
		//});
		auto p = words.find(input);
		if (p != words.end())
			cout << input << "�� ��� Ƚ�� : " << p->second << endl;
		else
			cout << input << "�� �ٸ����� ���� �ܾ��Դϴ�" << endl;

		// cout << "�˻��Ϸ��� �ܾ� : " << input << " --> " << words[input] << endl;
	}

	// "���ĺ��� ���� �ٸ���.txt"�� ���� �ܾ ������������ �����̳ʿ� ��������
	ifstream in ("New_Alice.txt");
	map<string, int> chars;

	for (auto i = istream_iterator<string>(in); i != istream_iterator<string>(); ++i)
		chars.emplace(*i, 1);

	// ���ĵ� �ܾ ���Ͽ� �������
	ofstream fout("�ܾ� �������� ������ �ٸ���.txt");

	for (const pair<string, int>& d : chars)
		fout << d.first << endl;

	in.close();
	fout.close();
	// �ܾ ���ĵǾ� �ִ� a�� �����ϴ� �ܾ�� ��ΰ�?

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
// =========================================================
//	2�� ���� �����̳�
//   array
//   vector			STL ��ǥ ����
// - deque			
// - list
// - forward_list
//
// �ݺ��� ����� ������ �ʿ��ϴ�
// ==========================================================
#include <iostream>
#include <deque>
#include "save.h"
#include "String.h"
using namespace std;

// "�ҽ�.cpp"���� e�� ������ ����� "e���¼ҽ�.cpp"�� �����϶�
// remove_if �� e�� �����Ѵ�
// ������� ó���ϱ� ���� istreambuf_iterator, ostreambuf_iterator�� ���

// "�ҽ�.cpp"�� �Ųٷ� ����� "�Ųٷμҽ�.cpp"�� �����϶�

// �Է� : �ҽ�.cpp
// ��� : �ܾ��.cpp
// �ܾ��� ���ڸ� ��������


// "��"�� ���ʿ� String�ڷ��� 10, 20, 30�� �ְ� ����غ��ÿ�
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

	ofstream out("e���¼ҽ�.cpp");
	copy(v.begin(), v.end(), ostreambuf_iterator<char>(out));

	out.close();
	in.close();*/

	deque<String> d;
	// sizeof(d)�� 40����Ʈ

	d.emplace_back(10);
	d.emplace_back(20);
	d.emplace_back(30);
	d.emplace_back(40);
	d.emplace_back(50);
	d.emplace_back(60);
	d.emplace_back(70);
	d.emplace_back(80);
	d.emplace_back(90);
	// ���� ������ �޸� �ּҴ� vector�� �޸� �پ����� ����
	// �޸𸮸� �Ѻ�Ͼ� �������� �̾���� ����
	//for (auto i = d.begin(); i < d.end(); ++i)
	//	cout << *i << endl;
	// �޸𸮰� ���������� �̾������� �ʰ� �������� �������ֱ� ������ ���� ���� ������ �ؼ��ȵ�
	// ++i�� �Ұ�� d�� �޸��ּҸ� ����ؾ� �ϱ⶧���� ���ʿ��� ���� �߻�


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
// �߰��� ���̰� 20�� String�� �߰�����. �޸𸮴� ��� ���ɱ�?
// v.emplace(v.begin() + 1, 20);

// ���̰� 20�� String�� �����϶�. �޸𸮴� ��� �ٲ��?
// v.erase();
// vector�� �ڷḦ ��� �ڷᱸ���̹Ƿ� �޸𸮸� �����ϴµ��� ġ���ϰ�
// �˰����� �ٸ������� �ٷ��
// auto p = remove(v.begin(), v.end(), 20);
//		== remove(v.begin(), v.end(), String(20))
//					������ ������ ������

// 20�� ���������� v�� ������� �پ���� �ʾ���
// �ڽ��� size���� �������ִ� ���� �ڱ� �ڽŸ� �����ϵ���
// ���� remove()���� return���� �����ؼ� �ڷᱸ������ �˷��� �� ����
// v.erase(p, v.end());

// ��
// erase-remove idiom
v.erase(remove(v.begin(), v.end(), String(20)), v.end());
// ��ü�� ���۷����� �Ѿ�� ������ String(20)�� ������ �ѹ��� ������
// ���� 20���� �Ѿ����� ��ü�� ���� ��� ���Ѵ�

cout << endl << endl << "--------------------------" << endl;

for (int i = 0; i < v.size(); ++i)
cout << v[i] << endl;*/
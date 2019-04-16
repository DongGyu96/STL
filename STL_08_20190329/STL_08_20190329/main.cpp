// =================================================================================
// 2�� ���� �����̳� ( Sequence Container  - homogeneous data type ���� �ڷ���)
// - array			: �����ϰ� �ڷ��� ������ ������
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

// ��§ ���α׷��� �䱸������ ����ǵ� �ּ����� �ڵ�������� �����ؾ� �Ѵ�
// array���� stl�� ����ϸ� �Ϲ� �迭�� ����Ѱͺ��� �ּ����� �ڵ� ������ ����
// ���α׷��� ������

// ����ִ� v�� String 20 ���� �߰��϶�
// String�� ���� uid(10, 70)���� �ʱ�ȭ�϶�
// String�� ���ڸ� ������������ �����϶�
// v�� String�� ���� ������������ �����϶�
// ����� ȭ�� ����϶�

int main()
{
	// vector<�ڷ���> ������; (n)���� {n}�ʱ�ȭ
	// vector<> ��ü�� �ϳ��� �ڷ���
	// vecotr < vector < vector < vector<String> > > > v;
	// vector<int> b; // sizeof(vertor<int>) : 12����Ʈ
	vector<String> v; // ���������� 12����Ʈ �������̱� ����

	// v.push_back(String{40});
	// v.push_back(40);

	while (false)
	{
		cout << "������ ���� ����			: " << v.size() << endl;
		cout << "���Ҵ� ���� ���� �� �ִ� ������ ����	: " << v.capacity() << endl;
		cout << "���Ұ� ����Ǿ� �ִ� ��ġ		: " << v.data() << endl;; // �޸� ������
		// ù��° ������ �ּҰ�

		int prev = v.capacity();
		char c;
		cin >> c;
		v.push_back(10);
		if (v.capacity() - prev != 0) {
			// ���Ҵ� ���� ������ �ִ� ������ ������ ���� ������ �������� 1.5�� �����Ѵ�
			cout << endl << endl << "���� : " << v.capacity() - prev << endl << endl << endl;
		}

	}

	// String *p = v.data(); // v.data() ù��° ������ �ּҰ�
	// ++p;
	// ++p;
	// cout << *p << endl; // v[2];

	default_random_engine dre;
	uniform_int_distribution<> uid(10, 70);

	// �޸��� ������ �̸� Ȯ���ϴ� ���
	// v.capacity()�� Ȯ���ϴ� ���
	v.reserve(20);
	for (int i = 0; i < 20; ++i) {
		// vector<String> v; �ϰ�� �� �ݺ����� �޸𸮸� �ٽ� Ȯ���ϱ� ������ ������ �˰���
		//v.push_back(uid(dre)); // v,push_back(String{uid(dre)}; �� ��
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
	// ��������� for���� for(auto& d : v)
	for (const String& d : v)
		cout << d << endl;

	save("main.cpp");
}
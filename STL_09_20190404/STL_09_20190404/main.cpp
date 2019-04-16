// ======================================================
// 2�� ���� �����̳�
//   array
// - vector
// - deque
// - list
// - forward_list
//
// 2019. 4. 4 �̵��� �����ϴ� Ŭ������ �Ǿ���
// 5. �̵�����			( �̵������ڿ��� �ڿ��� �����´� )
// 6. �̵��Ҵ翬����
// ======================================================
#include <iostream>
#include <vector>
#include <string>
#include <istream>
#include <algorithm>
#include <fstream>
#include "save.h"
#include "String.h"
using namespace std;

// �Է��ڷ� - Ű����
// ����ڷ� - ȭ��
// Ű���忡�� char�� �Է¹޾� ���� �� ȭ�� ����϶�
// ������ - ũ�Ⱑ ���ΰ�?


int main()
{
	//vector<String> v;
	
	// �޸� ũ�⸦ �̸� ��Ƶ��� ������ �߰��Ҷ����� ��� �޸𸮸� ���� ���
	// ���� ������ �ݺ��� ( ������ �̵� ������ �ؾ� �� )
	// �̸� ������ �����̶� �����Ҽ��ִٸ� array�� ������ ������ ����
	// �� ũ�Ⱑ �����Ǵ� ��쿡�� array�� ���°� �� ����
	//v.reserve(10);

	//v.push_back(String{ 30 });	// String(30)�� ���� �����ǰ� push_back���� v�� ���������
									// �� �� ������ ���� String(30)�� �Ҹ��ϰ� v�� �Ҹ���
									// �׷��� 30�� �޾� HEAP���� 30���� ���ڿ��� �����ϰ� �ٸ� �޸𸮿�
									// ���� ���� ���� �ٽ� v�� �ű�� ������ �߻���
									// �׷��� �׳� �ڿ��� �̵��ϴ� ����� ������?

	// �ӽ÷� ���ÿ� ������ ����� �װ��� �ٽ� ���Ϳ� ����־ƾ� �ϴ� ���ŷο�
	// ���� ���Ϳ��� ���� ����� �� �� �ִ� ��ɾ �ִٸ�
	// v.emplace_back(String{ 30 });
	// ������ ���� �ʴ´� ��ü�� ���� �Ѱ�� ����
	// ���� ���ڰ��� �ִ´�
	//v.emplace_back(30);


	// ���ڿ��� ũ�⸦ �𸦶� �޴� ���
	// vector<string> v	(������, ������);
	//					(Ű�������, Ű���峡);
	// vector<string> v(istream_iterator<string>(cin), istream_iterator<string>());
	// �� ������ ����v�� ����� ������ �ƴ� �Լ� ����
	
	vector<char> v{ istream_iterator<char>(cin), istream_iterator<char>() };

	// ���Ͽ��� string�� �Է¹޾� ���� �� ȭ�鿡 ����϶�
	//ifstream in("main.cpp");
	//vector<string> v{ istream_iterator<string>(in), istream_iterator<string>() };


	sort(v.begin(), v.end());

	for (auto& d: v)
		cout << d;
	//copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\t"));
	cout << endl;

	save("main.cpp");
}
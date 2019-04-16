#include <iostream>
#include <algorithm>
#include <random>
#include "save.h"
using namespace std; // namespace�� ��Ը� ���α׷����� �����ϰ� ����ϴ°�

//bool how(int a, int b)
//{
//	static int count = 0;
//	return a > b;
//}

int a[1000000]{ 1 };

int main()
{
	// ���� 10���� �����غ���
	//int a[] {1, 3, 5, 7, 9, 2, 4, 6, 8, 10}; // �ʱ�ȭ�� ��� Initialization List
	//Uniform Initialization

	//���� 1000���� �����غ���
	default_random_engine dre;
	uniform_int_distribution<> uid(0, 1000000);
	for (int& d : a)
	{
				//����(����) pseudo����(�������η���)
		d = uid(dre);
	}

	//ascending order : �������� / descending order : �������� ����
	sort(begin(a), end(a), [](int a, int b) { return a < b; });//����Ʈ�� ��������
	
	for (int d : a)
		cout << d << " ";
	cout << endl;

	save("main.cpp");
}
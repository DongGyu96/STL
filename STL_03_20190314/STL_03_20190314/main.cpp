// ������ �а� ����
#include <iostream>
#include <algorithm>
#include <random>
#include <fstream>
//#include <iomanip> // �ٸ���
#include "save.h"
using namespace std;

// ���� �����ʹ� ����������(���)(���) ��ϵǴ°�?
// -> ���α׷��� ���۵� ������ ���� ������ �޸𸮿� ������ũ�⸸ŭ �߰��ȴ�.
// int a[100];
// int a[100]{ 1 };
// �� �� ����� �������� ������ ����

// ����ڰ� ���ϴ� ��ŭ ������ �Է¹޴´�.
// ������ ������ ä���, uid(dre)�̿�
// �������� ���� �� 100�� ���
//while (true)
//{
//	int num;
//	cout << "���ϴ� ������ ������ �Է��ϼ��� : ";
//	cin >> num;

//	default_random_engine dre;
//	uniform_int_distribution<> uid;

//	int* a = new int[num]; // �����迭 ���� new[]

//	for (int i = 0; i < num; ++i)
//		a[i] = uid(dre);

//	cout << "���� �� 100��" << endl;
//	for (int i = 0; i < 100; ++i)
//	{
//		cout << setw(12) << a[i] << " ";
//		if (i % 6 == 5)
//			cout << endl;
//	}
//	cout << endl << endl;

//	sort(a, a + num);

//	cout << "���� �� 100��" << endl;
//	for (int i = 0; i < 100; ++i)
//	{
//		cout << setw(12) << a[i] << " ";
//		if (i % 6 == 5)
//			cout << endl;
//	}
//	cout << endl << endl;

//	delete[] a; // �����迭 ����
//}




// ���� 10000���� �����ϰ� �������� �����ϰ� ������ ��
// ���� "��������.dat"�� ����϶�
// ���������� ����Ϸ��� �� ����Ʈ�� �ʿ��Ѱ�?
// 40000byte�� �ʿ��ϴ�.
// ������ default text��� ���� binary���� ����� �Ѵ�.
// - binary��尡 �����ΰ�? (Windows, Apple, Unix) ���� �ٸ�


// ���� "��������.dat"���� ���� ������ ������������ ���ĵǾ��ִ�.
// �� ������ binary���� ��ϵǾ� �ִ�.
// [����] �о ȭ�鿡 ����϶�

int main()
{
	default_random_engine dre;
	uniform_int_distribution<> uid;

	// 0���� ������ ���۹�������, ��� 10000�� * sizeof(int);
	int *a = new int[10000]; // int : 4����Ʈ

	for (int i = 0; i < 10000; ++i)
	{
		a[i] = uid(dre);
	}

	sort(a, a + 10000);

	ofstream out("��������.dat", ios::binary); // binary ���� ����
	//ofstream out("��������.dat");

	//for (int i = 0; i < 10000; ++i)
	//{
	//	out << a[i] << " "; �������� ǥ���ϴ� �������� �޸�ũ�Ⱑ �þ�Ե�
	//} 103kb�Ҹ�

	//write(const char* _Str, streamsize Count);
	//char* ������ �ʿ��Ͽ� int* -> char*�� ��ȯ
	//out.write(const_cast<const char*>(reinterpret_cast<char*>(a)), 10000 * sizeof(int)); 
	// �� ���� �����

	out.write((char *)a, 10000 * sizeof(int)); // 40.185byte�Ҹ� 185byte����

	delete[] a;
	
	ifstream in("��������.dat", ios::binary);

	int d;
	for (int i = 0; i < 10000; ++i)
	{
		in.read((char *)&d, sizeof(int));
		cout << d << endl;
	}
	in.close();

	save("main.cpp");
}
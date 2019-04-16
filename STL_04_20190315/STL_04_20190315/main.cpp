// ���α׷� �ð��� ��� �ڵ�
// callable type�� ǥ���ϱ� ���� functional class
// smart pointer
// �ڿ��� Ȯ���ϴ� Ŭ���� ����� ����
#include <iostream>
#include <random>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>
#include "save.h"
using namespace std;

//default_random_engine dre;
//uniform_int_distribution<> uid(0, 20);
//uniform_int_distribution<> uidName('a', 'z');

//class Dog {
//	char name[11];	// �̸��� ������ �ҹ��� 10���ڷ� ����
//	int age;		// 0~20 ������ ���� ���´�
//public:
//	Dog() {
//		for (int i = 0; i < 10; ++i)
//		{
//			name[i] = uidName(dre);
//		}
//		name[10] = '\0';
//		age = uid(dre);
//	}
//	// const�Լ��� ��������� �����Ҽ������� mutable int���� �����ϸ� ������ ��������
//	string GetName() const { return string(name); }
//};

// Dog 1000������ ��������
// �̸��� ���̸� �����Ѵ�
// �̸� ������������ �����Ѵ�
// ���� "Dog�̸�������.dat"
// ������ ũ�Ⱑ sizeof(Dog) * 1000;

// "Dog�̸�������.dat"�� �о� ȭ�鿡 ����϶�.
// class Dog 1000���� ������ binary���� ��ϵǾ� �ִ�.
// �̸� : abcdasdfvb, ���� : 3��
//class Dog {
//	char name[11];
//	int age;
//
//	friend ostream& operator<<(ostream&, const Dog&);
//};
// char dog[16];
//ostream& operator<<(ostream& os, const Dog& dog)
//{
//	cout << "�̸� : " << dog.name << ", ���� : " << dog.age << "��";
//	return os;
//}

// ȣ�Ⱑ��Ÿ�� - callable type
// type - ������ �θ����մ°� (int void ���)
void jump() { cout << "JUMP" << endl; }
void slide() { cout << "SLIDE" << endl; }
class Dog {
public:
	int operator()(int a) { return a * a; }
};
int main()
{
	// ȣ�Ⱑ��Ÿ������
	// 1. �Ϲ��Լ�
	void(*f1)(void) = jump; // auto f1 = jump;
	f1();
	cout << "�Ϲ��Լ� : " << typeid(f1).name() << endl << endl;

	// 2. ����
	auto f2 = []() {cout << "���� �Լ� ����" << endl; };
	f2();
	cout << "���� : " << typeid(f2).name() << endl << endl;

	// 3. �Լ���ü - ()�����ڸ� overloading�� Ŭ������ ��ü
	Dog dog;
	auto f3 = dog;
	cout << f3(3) << endl;
	cout << "�Լ���ü : " << typeid(f3).name() << endl << endl;

	// 4. ����Լ�������
	// -------------------------------------------------------------------------

	/*Dog a[1000]; // ������ �Է�
	sort(begin(a), end(a), [](const Dog& a, const Dog& b) {
		return a.GetName() < b.GetName();
	});
	ofstream out("Dog�̸�������.dat", ios::binary);
	out.write((char*)a, sizeof(Dog) * 1000);*/

	/*ifstream in("Dog�̸�������.dat", ios::binary);
	for (int i = 0; i < 1000; ++i)
	{
		in.read(dog, 16);
		cout << dog << endl;
	}*/

	/*ifstream in("Dog�̸�������.dat", ios::binary); // ������ ���
	Dog dog;
	for (int i = 0; i < 1000; ++i)
	{
		in.read((char *)&dog, sizeof(Dog));
		cout << dog << endl;
	}*/

	// using namespace std::chrono;
	// �ð��� ���
	// auto b = chrono::steady_clock::now();
	// �ð��� �ɸ��� �ڵ�
	// this_thread::sleep_for(1s);
	// �ٽ� �ð��� ���
	// auto e = chrono::steady_clock::now();
	// ���̸� ����Ѵ�
	// // auto t = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - b); // ms������ ��ȯ
	// cout << duration_cast<milliseconds>(steady_clock::now() - b).count() << endl;


	save("main.cpp");
}

/* �ð��� ��� �ڵ�
	using namespace std::chrono;
	auto b = chrono::steady_clock::now();
	cout << duration_cast<milliseconds>(steady_clock::now() - b).count() << endl;
*/
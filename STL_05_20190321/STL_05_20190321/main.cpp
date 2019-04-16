// Smart Pointer
// �ڿ��� Ȯ���ϴ� Ŭ���� ����� ����
//
// ���� - class String�� ���� �и����� #include "String.h"
//		  1�� �о��
// ===================================================================
#include <iostream>
#include <functional>
#include <cmath>
#include <random>
#include "save.h"
using namespace std;

//				�ڿ��� Ȯ���ϴ� Ŭ���� �����
// ������ �������� ���ڷ� �޾� �� ���ڸ�ŭ HEAP���� �޸𸮸� �Ҵ��Ѵ�.
// �޸��� ������ 'a'~'z' ������ ������ �ҹ��ڷ� ä���.
// ���� main�� �������� ����ǵ��� ����
default_random_engine dre;
uniform_int_distribution<> uidChar('a', 'z');

// String�� �ڿ��� �Ҵ��ϴ� Ŭ�����̴�
// 1. ���� �� new�� �ڿ��Ҵ�
// 2. �Ҹ� �� delete�� �����Ѵ�.
// 3. ��������ڿ��� ���� ���縦 �Ѵ�.
// 4. �Ҵ翬���ڿ��� ���� ���縦 �Ѵ�.
// �ʼ������� �����ؾ� ��
class String {
	int num{ 0 };
	char *p{ nullptr }; // �������� �̸� �����صδ� ���
public:
	String() = default;
	String(int n) : num{n}
	{
		p = new char[num]; 
		for (int i = 0; i < num; ++i)
		{
			p[i] = uidChar(dre);
		}
	}
	
	// �ڿ��� �Ҵ��ϴ� Ŭ������ ������ ����� �ϴ� �� : ���������, �Ҵ翬���� ========
	// String(const String&) = default; // Default ���� ������ : �޸� ����
	String(const String& other) : num{ other.num }
	{
		p = new char[num];
		memcpy(p, other.p, num);
	}

	String& operator=(const String& other) // �Ҵ� ������
	{
		// a = a ���� �� �ڽſ��� �Ҵ� �ϴ� ��츦 ����ó���Ѵ�
		if (this == &other)
			return *this;
		delete[] p;
		num = other.num;
		p = new char[num];
		memcpy(p, other.p, num);
	} // ==============================================================================

	~String() { 
		delete[] p;
		p = NULL;
	}

	void set(int n)
	{
		num = n;
		if (!p) // �̹� �����Ǿ��ֱ� ������ ����ó��
		{
			delete[] p;
		}
		p = new char[num];
		for (int i = 0; i < num; ++i)
		{
			p[i] = uidChar(dre);
		}
	}
	int GetNum() const { return num; }
	friend ostream& operator<<(ostream& os, const String& a);
};

ostream& operator<<(ostream& os, const String& str)
{
	for (int i = 0; i < str.num; ++i)
	{
		os << str.p[i];
	}
	return os;
}

/*
class Dog { // ============= ���� ===================================
public:
	void operator()() {}

	void jump() 
	{ 
		cout << this << "����" << endl; 
	}
};

void f()// �Լ��� �ݵ�� �������� ��������
{
	cout << "�׳� �Լ�" << endl;
}

int main()
{
	// ȣ�� ������ Ÿ�� ==================
	// 1. �Ϲ��Լ�
	// double f1 = sin(3.14);
	// double (*f1)(double) = sin;
	// cout << f1(0) << endl;

	//function<double(double)> f1 = sin;
	function<void(void)> f1 = f;
	cout << typeid(f1).name() << endl;

	// 2. ���� ( �����Լ��� �������� ������ )
	// ���� �Լ��̱� ������ [](ĸ��)�� �ʿ�
	// auto f2 = []() { cout << "���� �Լ� ȣ��" << endl; };
	// f2();
	function<void(void)>f2 = []() { cout << "���� �Լ� ȣ��" << endl; };
	cout << typeid(f2).name() << endl;

	// 3. �Լ���ü
	Dog d;
	d();

	// 4. ��� �Լ�
	//Dog dog;
	//dog.jump();
	////auto f4 = &Dog::jump;
	//void (Dog::*f4)(void) = &Dog::jump;
	//cout << typeid(f4).name() << endl;
	//(dog.*f4)(); // jump�Լ� ȣ��

	//Dog* pd = new Dog;
	//void (Dog::*f4)(void) = &Dog::jump;
	//(pd->*f4)(); // jump�Լ� ȣ��
	
	Dog a;
	//a.jump(); // ���ڰ� ���°� ó�� �������� �ڱ� �ڽ��� �ּҸ� �Ѱ���
	function<void(Dog* const)> f4 = &Dog::jump; // ���� ���ڿ� Dog* const
	cout << typeid(f4).name() << endl;
	f4(&a);

	// ==================== ���� =========================================================
	save("main.cpp");
}
*/

int main()
{
	//String a{ 20 }; // ex) gkdlaldlslerpamxmals
	//String b = a; // ���� ������
	//cout << a << endl; // ȭ�� ��� : gkdlaldlslerpamxmals
	//cout << b << endl;

	String strings[100];
	// string�� ������ ���̷� �����϶�
	uniform_int_distribution<> uidNum(10, 70);
	for (String& d : strings)
		d.set(uidNum(dre));

	// ���� ������������ �����϶�
	sort(begin(strings), end(strings), [](const String& a, const String& b) {
		return a.GetNum() < b.GetNum(); 
	});

	// ����϶�
	for (String& d : strings)
		cout << d << endl;

	String a{ 20 };
	String b = move(a); // �̵��� ���������ʾ� ���� �����ڰ� ȣ���
	cout << a << endl;
	cout << b << endl;


	save("main.cpp");
}
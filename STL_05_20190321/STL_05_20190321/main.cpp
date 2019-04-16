// Smart Pointer
// 자원을 확보하는 클래스 만들어 놓기
//
// 과제 - class String을 파일 분리하자 #include "String.h"
//		  1장 읽어보기
// ===================================================================
#include <iostream>
#include <functional>
#include <cmath>
#include <random>
#include "save.h"
using namespace std;

//				자원을 확보하는 클래스 만들기
// 정수를 생성자의 인자로 받아 그 숫자만큼 HEAP에서 메모리를 할당한다.
// 메모리의 내용은 'a'~'z' 사이의 임의의 소문자로 채운다.
// 다음 main이 문제없이 실행되도록 하자
default_random_engine dre;
uniform_int_distribution<> uidChar('a', 'z');

// String은 자원을 할당하는 클래스이다
// 1. 생성 시 new로 자원할당
// 2. 소멸 시 delete로 해제한다.
// 3. 복사생성자에서 깊은 복사를 한다.
// 4. 할당연산자에서 깊은 복사를 한다.
// 필수적으로 수행해야 함
class String {
	int num{ 0 };
	char *p{ nullptr }; // 변수값을 미리 설정해두는 방법
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
	
	// 자원을 할당하는 클래스는 무조건 해줘야 하는 것 : 복사생성자, 할당연산자 ========
	// String(const String&) = default; // Default 복사 생성자 : 메모리 복사
	String(const String& other) : num{ other.num }
	{
		p = new char[num];
		memcpy(p, other.p, num);
	}

	String& operator=(const String& other) // 할당 연산자
	{
		// a = a 같은 나 자신에게 할당 하는 경우를 예외처리한다
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
		if (!p) // 이미 생성되어있기 때문에 예외처리
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
class Dog { // ============= 복습 ===================================
public:
	void operator()() {}

	void jump() 
	{ 
		cout << this << "점프" << endl; 
	}
};

void f()// 함수는 반드시 전역에서 만들어야함
{
	cout << "그냥 함수" << endl;
}

int main()
{
	// 호출 가능한 타입 ==================
	// 1. 일반함수
	// double f1 = sin(3.14);
	// double (*f1)(double) = sin;
	// cout << f1(0) << endl;

	//function<double(double)> f1 = sin;
	function<void(void)> f1 = f;
	cout << typeid(f1).name() << endl;

	// 2. 람다 ( 람다함수는 지역에서 정의함 )
	// 지역 함수이기 때문에 [](캡쳐)가 필요
	// auto f2 = []() { cout << "람다 함수 호출" << endl; };
	// f2();
	function<void(void)>f2 = []() { cout << "람다 함수 호출" << endl; };
	cout << typeid(f2).name() << endl;

	// 3. 함수객체
	Dog d;
	d();

	// 4. 멤버 함수
	//Dog dog;
	//dog.jump();
	////auto f4 = &Dog::jump;
	//void (Dog::*f4)(void) = &Dog::jump;
	//cout << typeid(f4).name() << endl;
	//(dog.*f4)(); // jump함수 호출

	//Dog* pd = new Dog;
	//void (Dog::*f4)(void) = &Dog::jump;
	//(pd->*f4)(); // jump함수 호출
	
	Dog a;
	//a.jump(); // 인자가 없는것 처럼 보이지만 자기 자신의 주소를 넘겨줌
	function<void(Dog* const)> f4 = &Dog::jump; // 따라서 인자에 Dog* const
	cout << typeid(f4).name() << endl;
	f4(&a);

	// ==================== 복습 =========================================================
	save("main.cpp");
}
*/

int main()
{
	//String a{ 20 }; // ex) gkdlaldlslerpamxmals
	//String b = a; // 복사 생성자
	//cout << a << endl; // 화면 출력 : gkdlaldlslerpamxmals
	//cout << b << endl;

	String strings[100];
	// string을 임의의 길이로 설정하라
	uniform_int_distribution<> uidNum(10, 70);
	for (String& d : strings)
		d.set(uidNum(dre));

	// 길이 오름차순으로 정렬하라
	sort(begin(strings), end(strings), [](const String& a, const String& b) {
		return a.GetNum() < b.GetNum(); 
	});

	// 출력하라
	for (String& d : strings)
		cout << d << endl;

	String a{ 20 };
	String b = move(a); // 이동을 구현하지않아 복사 생성자가 호출됨
	cout << a << endl;
	cout << b << endl;


	save("main.cpp");
}
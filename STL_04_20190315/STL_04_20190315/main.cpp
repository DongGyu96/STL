// 프로그램 시간을 재는 코드
// callable type을 표현하기 위한 functional class
// smart pointer
// 자원을 확보하는 클래스 만들어 놓기
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
//	char name[11];	// 이름은 임의의 소문자 10글자로 구성
//	int age;		// 0~20 사이의 값을 갖는다
//public:
//	Dog() {
//		for (int i = 0; i < 10; ++i)
//		{
//			name[i] = uidName(dre);
//		}
//		name[10] = '\0';
//		age = uid(dre);
//	}
//	// const함수는 멤버변수를 변경할수없지만 mutable int같이 선언하면 변경이 가능해짐
//	string GetName() const { return string(name); }
//};

// Dog 1000마리를 생성하자
// 이름과 나이를 설정한다
// 이름 오름차순으로 정렬한다
// 파일 "Dog이름순정렬.dat"
// 파일의 크기가 sizeof(Dog) * 1000;

// "Dog이름순정렬.dat"을 읽어 화면에 출력하라.
// class Dog 1000개의 정보가 binary모드로 기록되어 있다.
// 이름 : abcdasdfvb, 나이 : 3살
//class Dog {
//	char name[11];
//	int age;
//
//	friend ostream& operator<<(ostream&, const Dog&);
//};
// char dog[16];
//ostream& operator<<(ostream& os, const Dog& dog)
//{
//	cout << "이름 : " << dog.name << ", 나이 : " << dog.age << "살";
//	return os;
//}

// 호출가능타입 - callable type
// type - 변수를 부를수잇는것 (int void 등등)
void jump() { cout << "JUMP" << endl; }
void slide() { cout << "SLIDE" << endl; }
class Dog {
public:
	int operator()(int a) { return a * a; }
};
int main()
{
	// 호출가능타입정리
	// 1. 일반함수
	void(*f1)(void) = jump; // auto f1 = jump;
	f1();
	cout << "일반함수 : " << typeid(f1).name() << endl << endl;

	// 2. 람다
	auto f2 = []() {cout << "람다 함수 실행" << endl; };
	f2();
	cout << "람다 : " << typeid(f2).name() << endl << endl;

	// 3. 함수객체 - ()연산자를 overloading한 클래스의 객체
	Dog dog;
	auto f3 = dog;
	cout << f3(3) << endl;
	cout << "함수객체 : " << typeid(f3).name() << endl << endl;

	// 4. 멤버함수포인터
	// -------------------------------------------------------------------------

	/*Dog a[1000]; // 데이터 입력
	sort(begin(a), end(a), [](const Dog& a, const Dog& b) {
		return a.GetName() < b.GetName();
	});
	ofstream out("Dog이름순정렬.dat", ios::binary);
	out.write((char*)a, sizeof(Dog) * 1000);*/

	/*ifstream in("Dog이름순정렬.dat", ios::binary);
	for (int i = 0; i < 1000; ++i)
	{
		in.read(dog, 16);
		cout << dog << endl;
	}*/

	/*ifstream in("Dog이름순정렬.dat", ios::binary); // 데이터 출력
	Dog dog;
	for (int i = 0; i < 1000; ++i)
	{
		in.read((char *)&dog, sizeof(Dog));
		cout << dog << endl;
	}*/

	// using namespace std::chrono;
	// 시간을 잰다
	// auto b = chrono::steady_clock::now();
	// 시간이 걸리는 코드
	// this_thread::sleep_for(1s);
	// 다시 시간을 잰다
	// auto e = chrono::steady_clock::now();
	// 차이를 계산한다
	// // auto t = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - b); // ms단위로 변환
	// cout << duration_cast<milliseconds>(steady_clock::now() - b).count() << endl;


	save("main.cpp");
}

/* 시간을 재는 코드
	using namespace std::chrono;
	auto b = chrono::steady_clock::now();
	cout << duration_cast<milliseconds>(steady_clock::now() - b).count() << endl;
*/
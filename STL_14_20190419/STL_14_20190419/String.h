#pragma once
#include <iostream>
#include <random>
using namespace std;

class String {
	int num{ 0 };
	char* p{ nullptr };
public:
	String() = default;
	String(int n);
	String(const String& other);
	String& operator=(const String& other);
	~String();

	// 이동을 지원하는 클래스
	// 이동을 지원하기 위해서는 인자를 건드려야 함
	// 이동생성자
	String(String&& other);
	// 이동할당연산자
	String& operator=(String&& other);
	

	void set(int n);

	int getNum() const;
	char* getP() const;

	friend ostream& operator<<(ostream&, const String&);


	bool operator==(const String& other);
};
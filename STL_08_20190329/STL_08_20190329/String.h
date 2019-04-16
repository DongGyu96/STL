#pragma once
#include <iostream>
#include <random>
using namespace std;

class String {
	int num{ 0 };
	char* p{ nullptr };
public:
	String() = default;

	//explicit String(int n); 형변환이 일어나지 않도록 함
	String(int n);

	String(const String& other);

	String& operator=(const String& other);

	~String();

	void set(int n);

	int getNum() const;
	char* getP() const;

	friend ostream& operator<<(ostream&, const String&);
};
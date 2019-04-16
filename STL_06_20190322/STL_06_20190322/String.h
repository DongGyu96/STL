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

	void set(int n);

	int getNum() const;
	char getChar(int n) const;

	friend ostream& operator<<(ostream&, const String&);
};
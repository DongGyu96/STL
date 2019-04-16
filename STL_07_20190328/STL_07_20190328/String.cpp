#include "String.h"

default_random_engine dre;
uniform_int_distribution<> uid('a', 'z');

String::String(int n) : num{ n } {
	p = new char[num];
	for (int i = 0; i < num; ++i)
		p[i] = uid(dre);
}

String::String(const String& other) : num{ other.num }
{
	p = new char[num];
	memcpy(p, other.p, num);
}

String& String::operator=(const String& other) {
	if (this == &other)
		return *this;

	delete[] p;
	num = other.num;
	p = new char[num];
	memcpy(p, other.p, num);
}

String::~String() {
	delete[] p;
	p = NULL;
}

void String::set(int n) {
	num = n;
	if (!p)
		delete[] p;
	p = new char[num];
	for (int i = 0; i < num; ++i)
		p[i] = uid(dre);
}

int String::getNum() const {
	return num;
}

char* String::getP() const {
	return p;
}

ostream& operator<<(ostream& os, const String& str)
{
	for (int i = 0; i < str.num; ++i)
		os << str.p[i];
	return os;
}

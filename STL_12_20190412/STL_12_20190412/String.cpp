#include "String.h"

default_random_engine dre;
uniform_int_distribution<> uid('a', 'z');

String::String(int n) : num{ n } {
	p = new char[num];
	for (int i = 0; i < num; ++i)
		p[i] = uid(dre);
	cout << "String(" << n << ") 생성, 자신 : " << this << ", HEAP : " << (void*)p << endl;
}

String::String(const String& other) : num{ other.num }
{
	p = new char[num];
	memcpy(p, other.p, num);

	cout << this << "를 복사생성함, 원본 : " << &other << ", HEAP : " << (void*)p << endl;
}

String& String::operator=(const String& other) {
	if (this == &other)
		return *this;

	delete[] p;
	num = other.num;
	p = new char[num];
	memcpy(p, other.p, num);

	cout << "할당연산자" << endl;
}

String::~String() {
	cout << "소멸 : " << this << ", HEAP : " << (void*)p << endl;
	delete[] p;
	p = NULL;
}

// 이동생성자
String::String(String&& other) : num{other.num}, p{other.p}
{
	// 원본을 정리함
	other.num = 0;
	other.p = nullptr;
	cout << this << "를 이동생성함, 원본 : " << &other << ", HEAP : " << (void*)p << endl;
}
// 이동할당연산자
String& String::operator=(String&& other)
{
	// 가장 먼저 해줘야 함 ( 나 자신을 할당하게 되는 것을 방지 )
	if (this == &other)
		return *this;

	delete[] p;
	num = other.num;
	p = other.p;

	// 원본을 정리함
	other.num = 0;
	other.p = nullptr;

	cout << "이동할당연산자" << endl;
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


bool String::operator==(const String& other)
{
	if (num == other.getNum())
		return true;
	else
		return false;
}

bool String::operator<(const String& rhs)
{
	return num < rhs.num;
}
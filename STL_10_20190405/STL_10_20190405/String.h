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

	// �̵��� �����ϴ� Ŭ����
	// �̵��� �����ϱ� ���ؼ��� ���ڸ� �ǵ���� ��
	// �̵�������
	String(String&& other);
	// �̵��Ҵ翬����
	String& operator=(String&& other);
	

	void set(int n);

	int getNum() const;
	char* getP() const;

	friend ostream& operator<<(ostream&, const String&);


	bool operator==(const String& other);
};
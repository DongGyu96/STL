// ====================================================
// 4�� 26�� �߰����
//
// �ݺ���
// �ݺ��ڸ� �̿��� ���α׷�
// �ݺ����� Ư��
// �ݺ��� �����
//		1. ���Թݺ���
//		2. ������ݺ���
//		3. ��Ʈ���ݺ���
//		4. �̵��ݺ���
// ====================================================
#include <iostream>
#include <list>
#include <forward_list>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include "String.h"
#include "save.h"
using namespace std;

// ����� ���� �ݺ��� �ݵ�� Ŭ�������� �Ѵ�
class MyIter : public iterator<bidirectional_iterator_tag, int> {
	// *, ++ ������ �����ؾ��� ( ���� �ݺ��ڴ� * / - �� �� �� �־�� �� )

};
// Ư���� ����ؾ� �Ѵ� -> ����� �޴� ����� ����
//template <>
//struct iterator_traits<MyIter> {
//	using iterator_category = random_access_iterator_tag;
//};


//void print(vector<int>::iterator start, vector<int>::iterator end);
template <class T> // Generic Programming�� �ٽ� / Ÿ�Կ� ������� �۵��Ѵ�
void print(T a, T b);

template <class T>
T add(T, T);

// ���ø��� ���ڴ� �ڷ����ε� �� �ڷ����� Ư���� �˾ƺ� ����� ���°�
template <class T>
void f(const T);

template <class InIter, class OutIter>
void myCopy(InIter begin, InIter end, OutIter des);

int main()
{
	//vector<int> data{ 1,2,3,4,5 };
	//print(data.begin(), data.end());

	//cout << add(1, 2) << endl;
	//cout << add("Hello, ", "World!") << endl;
	//add<string>("Hello, ", "World!")

	//vector<int> v{ 1,2,3 };
	//f(v.begin()); // ȭ�鿡 ���ڷ� ���޵� �ݺ����� ������ ����Ѵ�
	//f(list<String>::const_iterator());
	//f(forward_list<int>::const_iterator()); // ���� �б⸸ �Ҷ�
	//f(ostream_iterator<int>(clog));
	//f(istream_iterator<int>());
	//f(MyIter());
	
	vector<int> v{ 1,2,3,4,5 };
	vector<int> w;
	//w.resize(5);

	//myCopy(v.begin(), v.end(), ostream_iterator<String>(cout, "\n"));
	myCopy(v.begin(), v.end(), back_inserter(w));
							  // iterator adaptor

	for (auto i = v.rbegin(); i < v.rend(); ++i)
	{
		cout << *i << endl;
	}

	save("main.cpp");
}

template <class T>
void print(T a, T b)
{
	while (a != b)
		cout << *a++ << endl;
}
//void print(vector<int>::iterator start, vector<int>::iterator end)
//{
//	while (start != end)
//		cout << *start++ << endl;
//	for (; start != end; ++start)
//		cout << *start << endl;
//}

template <class T>
T add(T a, T b)
{
	// type_traits Ÿ�� Ư��
	cout << boolalpha << is_arithmetic<T>() << endl;
	// SFINAE : ���ø����� ġȯ�ϴٰ� �����ϴ��� ������ ������� �� ��
	return a + b;
}

template <class T>
void f(const T iter)
{
	// T�� � ������ �ݺ����ΰ�?
	cout<< typeid(iterator_traits<T>::iterator_category).name() << endl;

	// T�� � �ڷ����� ����Ű�� �ִ°�?
	cout << typeid(iterator_traits<T>::value_type).name() << endl;
}

template <class InIter, class OutIter>
void myCopy(InIter begin, InIter end, OutIter des)
{
	//copy(begin, end, des);
	while (begin != end)
		*des++ = *begin++;
}
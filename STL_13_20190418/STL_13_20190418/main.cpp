// ====================================================
// 4월 26일 중간고사
//
// 반복자
// 반복자를 이용한 프로그램
// 반복자의 특성
// 반복자 어댑터
//		1. 삽입반복자
//		2. 역방향반복자
//		3. 스트림반복자
//		4. 이동반복자
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

// 사용자 정의 반복자 반드시 클래스여야 한다
class MyIter : public iterator<bidirectional_iterator_tag, int> {
	// *, ++ 동작이 가능해야함 ( 랜덤 반복자는 * / - 다 할 수 있어야 함 )

};
// 특성을 등록해야 한다 -> 상속을 받는 방법이 있음
//template <>
//struct iterator_traits<MyIter> {
//	using iterator_category = random_access_iterator_tag;
//};


//void print(vector<int>::iterator start, vector<int>::iterator end);
template <class T> // Generic Programming의 핵심 / 타입에 상관없이 작동한다
void print(T a, T b);

template <class T>
T add(T, T);

// 템플릿의 인자는 자료형인데 그 자료형의 특성을 알아볼 방법은 없는가
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
	//f(v.begin()); // 화면에 인자로 전달된 반복자의 종류를 출력한다
	//f(list<String>::const_iterator());
	//f(forward_list<int>::const_iterator()); // 값을 읽기만 할때
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
	// type_traits 타입 특성
	cout << boolalpha << is_arithmetic<T>() << endl;
	// SFINAE : 템플릿으로 치환하다가 실패하더라도 에러로 취급하지 말 것
	return a + b;
}

template <class T>
void f(const T iter)
{
	// T가 어떤 종류의 반복자인가?
	cout<< typeid(iterator_traits<T>::iterator_category).name() << endl;

	// T가 어떤 자료형을 가르키고 있는가?
	cout << typeid(iterator_traits<T>::value_type).name() << endl;
}

template <class InIter, class OutIter>
void myCopy(InIter begin, InIter end, OutIter des)
{
	//copy(begin, end, des);
	while (begin != end)
		*des++ = *begin++;
}
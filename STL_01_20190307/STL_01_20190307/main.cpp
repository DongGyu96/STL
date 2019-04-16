#include <iostream>
#include <string>
#include <algorithm>

//class X {
//	int n;
//public:
//	X(int n) : n{ n } {}
//	friend std::ostream& operator<<(std::ostream&, X&);
//};
//
//std::ostream& operator<<(std::ostream& os, X& x)
//{
//	os << x.n;
//	return os;
//}
//
//template<class T>
//void change(T&, T&);
//
//int main()
//{
//	X a{ 1 };
//	X b{ 2 };
//
//	change(a, b);
//
//	std::cout << a << ", " << b << std::endl;
//
//	std::string c{std::to_string(123)};
//	std::string d{std::to_string(456)};
//
//	change(c, d);
//
//	std::cout << c << ", " << d << std::endl;
//}
//
//template<class T>
//void change(T& a, T& b)
//{
//	T temp{ a };
//	a = b;
//	b = temp;
//}

int main()
{
	int a[]{ 1,3,5,7,9,2,4,6,8,10 };

	std::sort(std::begin(a), std::end(a));

	for (int d : a)
		std::cout << d << ", ";
	std::cout << std::endl;
}
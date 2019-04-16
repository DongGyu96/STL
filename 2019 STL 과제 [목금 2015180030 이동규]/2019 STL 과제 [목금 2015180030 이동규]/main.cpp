#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	while (true) {
		vector<int> v;
		string a, b;
		cout << "정수1 입력 : ";
		cin >> a;
		cout << "정수2 입력 : ";
		cin >> b;
		int size = a.size() < b.size() ? b.size() : a.size();
		v.reserve(size + 1);
		int tempA, tempB, prev = 0;
		for (int i = size - 1; i >= 0; --i) {
			if (a.size() < size && (i - size + a.size() >= 0 && i - size + a.size() < a.size()))
				tempA = int(a[i - size + a.size()]) - 48;
			else if (a.size() == size)
				tempA = int(a[i]) - 48;
			else
				tempA = 0;
			if (b.size() < size && (i - size + b.size() >= 0 && i - size + b.size() < b.size()))
				tempB = int(b[i - size + b.size()]) - 48;
			else if (b.size() == size)
				tempB = int(b[i]) - 48;
			else
				tempB = 0;
			v.push_back((tempA + tempB + prev) % 10);
			if (tempA + tempB + prev >= 10) prev = 1;
			else prev = 0;
		}
		cout << "   " << setw(size) << a << endl;
		cout << " + " << setw(size) << b << endl;
		if (prev == 1) {
			v.push_back(prev);
			cout << "  ";
		}
		else
			cout << "   ";
		for (auto i = v.rbegin(); i != v.rend(); ++i)
			cout << *i;
		cout << endl;		
	}
}
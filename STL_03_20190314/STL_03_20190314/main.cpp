// 파일을 읽고 쓰기
#include <iostream>
#include <algorithm>
#include <random>
#include <fstream>
//#include <iomanip> // 줄맞춤
#include "save.h"
using namespace std;

// 전역 데이터는 실행파일의(어디에)(어떻게) 기록되는가?
// -> 프로그램이 시작될 때부터 끝날 때까지 메모리에 데이터크기만큼 추가된다.
// int a[100];
// int a[100]{ 1 };
// 위 두 방식의 차이점을 설명해 보자

// 사용자가 원하는 만큼 정수를 입력받는다.
// 임의의 값으로 채운다, uid(dre)이용
// 오름차순 정렬 후 100개 출력
//while (true)
//{
//	int num;
//	cout << "원하는 정수의 갯수를 입력하세요 : ";
//	cin >> num;

//	default_random_engine dre;
//	uniform_int_distribution<> uid;

//	int* a = new int[num]; // 동적배열 선언 new[]

//	for (int i = 0; i < num; ++i)
//		a[i] = uid(dre);

//	cout << "정렬 전 100개" << endl;
//	for (int i = 0; i < 100; ++i)
//	{
//		cout << setw(12) << a[i] << " ";
//		if (i % 6 == 5)
//			cout << endl;
//	}
//	cout << endl << endl;

//	sort(a, a + num);

//	cout << "정렬 후 100개" << endl;
//	for (int i = 0; i < 100; ++i)
//	{
//		cout << setw(12) << a[i] << " ";
//		if (i % 6 == 5)
//			cout << endl;
//	}
//	cout << endl << endl;

//	delete[] a; // 동적배열 해제
//}




// 정수 10000개를 생성하고 랜덤값을 설정하고 정렬한 후
// 파일 "정수만개.dat"에 기록하라
// 정수만개를 기록하려면 몇 바이트가 필요한가?
// 40000byte가 필요하다.
// 파일을 default text모드 말고 binary모드로 열어야 한다.
// - binary모드가 무엇인가? (Windows, Apple, Unix) 각각 다름


// 파일 "정수만개.dat"에는 정수 만개가 오름차순으로 정렬되어있다.
// 이 파일은 binary모드로 기록되어 있다.
// [문제] 읽어서 화면에 출력하라

int main()
{
	default_random_engine dre;
	uniform_int_distribution<> uid;

	// 0번쨰 원소의 시작번지부터, 모두 10000개 * sizeof(int);
	int *a = new int[10000]; // int : 4바이트

	for (int i = 0; i < 10000; ++i)
	{
		a[i] = uid(dre);
	}

	sort(a, a + 10000);

	ofstream out("정수만개.dat", ios::binary); // binary 모드로 열기
	//ofstream out("정수만개.dat");

	//for (int i = 0; i < 10000; ++i)
	//{
	//	out << a[i] << " "; 십진수로 표현하는 과정에서 메모리크기가 늘어나게됨
	//} 103kb소모

	//write(const char* _Str, streamsize Count);
	//char* 변수가 필요하여 int* -> char*로 변환
	//out.write(const_cast<const char*>(reinterpret_cast<char*>(a)), 10000 * sizeof(int)); 
	// 저 수준 입출력

	out.write((char *)a, 10000 * sizeof(int)); // 40.185byte소모 185byte낭비

	delete[] a;
	
	ifstream in("정수만개.dat", ios::binary);

	int d;
	for (int i = 0; i < 10000; ++i)
	{
		in.read((char *)&d, sizeof(int));
		cout << d << endl;
	}
	in.close();

	save("main.cpp");
}
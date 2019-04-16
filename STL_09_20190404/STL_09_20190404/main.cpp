// ======================================================
// 2장 순차 컨테이너
//   array
// - vector
// - deque
// - list
// - forward_list
//
// 2019. 4. 4 이동을 지원하는 클래스가 되었다
// 5. 이동생성			( 이동생성자에서 자원을 가져온다 )
// 6. 이동할당연산자
// ======================================================
#include <iostream>
#include <vector>
#include <string>
#include <istream>
#include <algorithm>
#include <fstream>
#include "save.h"
#include "String.h"
using namespace std;

// 입력자료 - 키보드
// 출력자료 - 화면
// 키보드에서 char을 입력받아 정렬 후 화면 출력하라
// 문제점 - 크기가 몇인가?


int main()
{
	//vector<String> v;
	
	// 메모리 크기를 미리 잡아두지 않으면 추가할때마다 계속 메모리를 새로 잡고
	// 복사 생성을 반복함 ( 원래는 이동 생성을 해야 함 )
	// 미리 공간을 조금이라도 예측할수있다면 array와 동일한 성능을 보임
	// 단 크기가 고정되는 경우에는 array를 쓰는게 더 좋음
	//v.reserve(10);

	//v.push_back(String{ 30 });	// String(30)이 먼저 생성되고 push_back으로 v에 복사생성됨
									// 그 후 생성에 사용된 String(30)이 소멸하고 v가 소멸함
									// 그러나 30을 받아 HEAP에서 30개의 문자열을 생성하고 다른 메모리에
									// 깊은 복사 한후 다시 v로 옮기는 과정이 발생함
									// 그러니 그냥 자원을 이동하는 방법은 없을까?

	// 임시로 스택에 변수를 만들고 그것을 다시 벡터에 집어넣아야 하는 번거로움
	// 만약 벡터에게 직접 만들어 낼 수 있는 명령어가 있다면
	// v.emplace_back(String{ 30 });
	// 개선이 되지 않는다 객체를 만들어서 넘겼기 때문
	// 따라서 인자값만 넣는다
	//v.emplace_back(30);


	// 문자열의 크기를 모를때 받는 방법
	// vector<string> v	(어디부터, 어디까지);
	//					(키보드시작, 키보드끝);
	// vector<string> v(istream_iterator<string>(cin), istream_iterator<string>());
	// 이 문장은 벡터v를 만드는 문장이 아닌 함수 선언문
	
	vector<char> v{ istream_iterator<char>(cin), istream_iterator<char>() };

	// 파일에서 string을 입력받아 정렬 후 화면에 출력하라
	//ifstream in("main.cpp");
	//vector<string> v{ istream_iterator<string>(in), istream_iterator<string>() };


	sort(v.begin(), v.end());

	for (auto& d: v)
		cout << d;
	//copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\t"));
	cout << endl;

	save("main.cpp");
}
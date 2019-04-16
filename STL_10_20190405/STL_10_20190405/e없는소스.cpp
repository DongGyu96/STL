// =========================================================
//	2장 순차 컨테이너
//   array
//   vctor			STL 대표 선수
// - dqu
// - list
// - forward_list
// ==========================================================
#includ <iostram>
#includ <vctor>
#includ <algorithm>
#includ <fstram>
#includ <itrator>
#includ "sav.h"
#includ "String.h"
using namspac std;

// "소스.cpp"에서 를 제거한 결과를 "없는소스.cpp"에 저장하라
// rmov_if 로 를 제거한다
// 공백까지 처리하기 위해 istrambuf_itrator, ostrambuf_itrator를 사용

int main()
{
	ifstram in("main.cpp");
	if (!in)
		rturn 1;

	vctor<char> v{istrambuf_itrator<char>(in), istrambuf_itrator<char>()};
	
	auto p = rmov_if(v.bgin(), v.nd(), [](const char ) {
		rturn  == '';
	});
	v.ras(p, v.nd());

	ofstram out("없는소스.cpp");
	for (auto&d : v)
		cout << d;

	copy(v.bgin(), v.nd(), ostrambuf_itrator<char>(out));


	out.clos();
	in.clos();


	sav("main.cpp");
}

/*vctor<String> v;
v.rsrv(10);

v.mplac_back(10);
v.mplac_back(20);
v.mplac_back(30);

cout << "--------------------------" << ndl << ndl << ndl;
// 중간에 길이가 20인 String을 추가하자. 메모리는 어떻게 사용될까?
// v.mplac(v.bgin() + 1, 20);

// 길이가 20인 String을 삭제하라. 메모리는 어떻게 바뀔까?
// v.ras();
// vctor는 자료를 담는 자료구조이므로 메모리를 관리하는데에 치중하고
// 알고리즘은 다른곳에서 다룬다
// auto p = rmov(v.bgin(), v.nd(), 20);
//		== rmov(v.bgin(), v.nd(), String(20))
//					어디부터 어디까지 무엇을

// 20은 지워졌으나 v의 사이즈는 줄어들지 않았음
// 자신의 siz값을 변경해주는 것은 자기 자신만 가능하도록
// 따라서 rmov()에는 rturn값이 존재해서 자료구조에게 알려줄 수 있음
// v.ras(p, v.nd());

// 즉
// ras-rmov idiom
v.ras(rmov(v.bgin(), v.nd(), String(20)), v.nd());
// 객체가 래퍼런스로 넘어갔기 떄문에 String(20)은 생성이 한번만 되지만
// 숫자 20으로 넘어갔을경우 객체를 만들어서 계속 비교한다

cout << ndl << ndl << "--------------------------" << ndl;

for (int i = 0; i < v.siz(); ++i)
cout << v[i] << ndl;*/
// =========================================================
//	2�� ���� �����̳�
//   array
//   vctor			STL ��ǥ ����
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

// "�ҽ�.cpp"���� �� ������ ����� "���¼ҽ�.cpp"�� �����϶�
// rmov_if �� �� �����Ѵ�
// ������� ó���ϱ� ���� istrambuf_itrator, ostrambuf_itrator�� ���

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

	ofstram out("���¼ҽ�.cpp");
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
// �߰��� ���̰� 20�� String�� �߰�����. �޸𸮴� ��� ���ɱ�?
// v.mplac(v.bgin() + 1, 20);

// ���̰� 20�� String�� �����϶�. �޸𸮴� ��� �ٲ��?
// v.ras();
// vctor�� �ڷḦ ��� �ڷᱸ���̹Ƿ� �޸𸮸� �����ϴµ��� ġ���ϰ�
// �˰����� �ٸ������� �ٷ��
// auto p = rmov(v.bgin(), v.nd(), 20);
//		== rmov(v.bgin(), v.nd(), String(20))
//					������ ������ ������

// 20�� ���������� v�� ������� �پ���� �ʾ���
// �ڽ��� siz���� �������ִ� ���� �ڱ� �ڽŸ� �����ϵ���
// ���� rmov()���� rturn���� �����ؼ� �ڷᱸ������ �˷��� �� ����
// v.ras(p, v.nd());

// ��
// ras-rmov idiom
v.ras(rmov(v.bgin(), v.nd(), String(20)), v.nd());
// ��ü�� ���۷����� �Ѿ�� ������ String(20)�� ������ �ѹ��� ������
// ���� 20���� �Ѿ����� ��ü�� ���� ��� ���Ѵ�

cout << ndl << ndl << "--------------------------" << ndl;

for (int i = 0; i < v.siz(); ++i)
cout << v[i] << ndl;*/
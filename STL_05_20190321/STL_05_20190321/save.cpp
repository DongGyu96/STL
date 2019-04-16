#pragma once
#include "save.h"

void save(std::string fname)
{
	// fname�� �б� ���� ����
	std::ifstream in(fname);
	if (!in) // �̸��� �߸����� ���
	{
		return;
	}

	// ����� ������ ���ٿ����� ���� ����
	std::ofstream out("STL_05_20190321.txt", std::ios::app);


	// ����� �ð��� ����Ѵ�
	// �ð�������� ��tic�� �귶��?
	auto tic = std::chrono::system_clock::now();

	// �� ���� time_t�� ��ȯ
	auto time = std::chrono::system_clock::to_time_t(tic);

	// �� ���� ���ڷ� ��ȯ
	std::string date = ctime(&time);

	out << std::endl << std::endl;
	out << "==================" << std::endl;
	out << date << std::endl;
	out << "==================" << std::endl;


	// fname�� ��� ������ ���ٿ� ����
	std::copy(std::istreambuf_iterator<char>(in),
		std::istreambuf_iterator<char>(),
		std::ostreambuf_iterator<char>(out));//copy(������, ������, ����)

}
/* �ð��� ��� �ڵ�
using namespace std::chrono;
auto b = chrono::steady_clock::now();
cout << duration_cast<milliseconds>(steady_clock::now() - b).count() << endl;
*/
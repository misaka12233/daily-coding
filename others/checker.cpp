#include <bits/stdc++.h> 
using namespace std;
int main()
{
	while(1) //һֱѭ����ֱ���ҵ���һ��������
	{
		system("datamaker.exe > in.txt");
		system("TC_unknown.exe < in.txt > baoli.txt");
		system("TC_std.exe < in.txt > std.txt");
		if(system("fc std.txt baoli.txt")) //�� fc ����1ʱ��˵����ʱ���ݲ�һ��
		break; //��һ��������ѭ��
	}
	return 0;
}


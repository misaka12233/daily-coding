#include <bits/stdc++.h> 
using namespace std;
int main()
{
	while(1) //һֱѭ����ֱ���ҵ���һ��������
	{
		system("data.exe > in.txt");
		system("10.exe < in.txt > baoli.txt");
		system("zj.exe > std.txt");
		if(system("fc std.txt baoli.txt")) //�� fc ����1ʱ��˵����ʱ���ݲ�һ��
		break; //��һ��������ѭ��
	}
	return 0;
}


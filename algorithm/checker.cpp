#include <bits/stdc++.h> 
using namespace std;
int main()
{
	while(1) //һֱѭ����ֱ���ҵ���һ��������
	{
		system("data.exe > in.txt");
		system("D402.exe < in.txt > baoli.txt");
		system("std02.exe < in.txt > std.txt");
		if(system("fc std.txt baoli.txt")) //�� fc ����1ʱ��˵����ʱ���ݲ�һ��
		break; //��һ��������ѭ��
	}
	return 0;
}


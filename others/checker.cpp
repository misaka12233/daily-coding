#include <bits/stdc++.h> 
using namespace std;
int main()
{
	while(1) //һֱѭ����ֱ���ҵ���һ��������
	{
		int x;
		scanf("%d", &x);
		if (x > 100) break;
		system("datamaker.exe > in.txt");
		system("gcy_L12Q3.exe < in.txt > out.txt");
		/*system("lxy.exe < in.txt > lxy.txt");
		if(system("fc my.txt lxy.txt")) //�� fc ����1ʱ��˵����ʱ���ݲ�һ��
		break; //��һ��������ѭ��*/
	}
	return 0;
}


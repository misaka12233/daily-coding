#include <bits/stdc++.h> 
using namespace std;
int main()
{
	while(1) //一直循环，直到找到不一样的数据
	{
		system("data.exe > in.txt");
		system("D402.exe < in.txt > baoli.txt");
		system("std02.exe < in.txt > std.txt");
		if(system("fc std.txt baoli.txt")) //当 fc 返回1时，说明这时数据不一样
		break; //不一样就跳出循环
	}
	return 0;
}


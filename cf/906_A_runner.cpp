#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int main()
{
	srand(time(0));
	while (1)
	{
		int n = (rand() % 10 + 1) * 2;
		char str[50];
		sprintf(str, "906_A_data.exe %d > 906A.in", n);
		system(str);
		system("cf#906_A.exe < 906A.in > 906A.out");
		sprintf(str, "906_A_checker.exe < 906A.out > res.out", n);
		system(str);
		if (system("fc res.out ans.out")) break;
	}
	return 0;
}


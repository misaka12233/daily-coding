#include<bits/stdc++.h>
using namespace std;
const int N = 30000; //数据总项数 
const int M = 30000; //高精度计算位数 
const int mul = 17; //等比数列公比 
const int bit = 10000; //高精度计算每位的上限 
int cnt[10];
int cur[M + 5];
int main()
{
	freopen("benford2.txt", "w", stdout);
	cur[0] = 7;
	for (int i = 1; i <= N; i++)
	{
		int res = 0, fir;
		for (int j = 0; j <= M; j++)
		{
			int tmp = cur[j] * mul + res;
			res = tmp / bit;
			cur[j] = tmp % bit;
			if (cur[j] != 0) fir = cur[j];
		}
		while (fir >= 10) fir /= 10;
		cnt[fir]++;
	}
	printf("共统计%d个数\n", N);
	for (int i = 1; i <= 9; i++)
		printf("%d出现次数为：%d次，占比%.2f%%\n", i, cnt[i], 1.0 * cnt[i] / N * 100.0);
	return 0;
}


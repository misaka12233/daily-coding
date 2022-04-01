#include<bits/stdc++.h>
using namespace std;
const int N = 30000; //���������� 
const int M = 30000; //�߾��ȼ���λ�� 
const int mul = 17; //�ȱ����й��� 
const int bit = 10000; //�߾��ȼ���ÿλ������ 
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
	printf("��ͳ��%d����\n", N);
	for (int i = 1; i <= 9; i++)
		printf("%d���ִ���Ϊ��%d�Σ�ռ��%.2f%%\n", i, cnt[i], 1.0 * cnt[i] / N * 100.0);
	return 0;
}


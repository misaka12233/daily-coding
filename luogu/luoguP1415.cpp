#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500 + 10;
int f[maxn]; // f[i] 代表 1~i 组成的数列中最后一个数的开始位置的最大值
int g[maxn]; // g[i] 代表 i~n 组成的数列中第一个数的结束位置的最大值
char s[maxn];
int digit[maxn];
bool cmp(int l1, int r1, int l2, int r2)
{
	int x = l1, y = l2;
	while (digit[x] == 0 && x < r1) x++;
	while (digit[y] == 0 && y < r2) y++;
	if (r1 - x == r2 - y)
	{
		while (x <= r1)
		{
			if (digit[x] == digit[y])
				x++, y++;
			else
				return digit[x] > digit[y];
		}
		return 0;
	}
	else
		return r1 - x > r2 - y;
}
int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	digit[0] = -1;
	for (int i = 1; i <= n; i++)
		digit[i] = s[i] - '0';
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j >= 1; j--)
		{
			if (cmp(j, i, f[j - 1], j - 1))
			{
				f[i] = j;
				break;
			}
		}
	}
	
	int pos = f[n];
	g[pos--] = n;
	for (; digit[pos] == 0; pos--) 
		g[pos] = n;
	// 所有g的结果越大越好
	// f求出的最后一个数前面的0全部都可以划分入最后一个数 
	
	for (int i = pos; i >= 1; i--)
	{
		for (int j = f[n] - 1; j >= i; j--)
		{
			if (cmp(j + 1, g[j + 1], i, j))
			{
				g[i] = j;
				break;
			}
		}
	}
	
	int now = g[1] + 1;
	for (int i = 1; i <= n; i++)
	{
		if (i == now)
		{
			putchar(',');
			now = g[now] + 1;
		}
		putchar(s[i]);
	} 
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 10;
typedef long long ll;
int n, q;
ll pre[maxn]; // pre[i]表示以i为结尾的括号序最多可以连续向前延申多少个不相互包含的括号 
ll sum[maxn]; // pre的前缀和，表示每个点可以向前延申的括号个数的总和 
char s[maxn];
int sta[maxn], top;
int main()
{
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == ')') 
		{
			if (top != 0)
			{
				pre[i] = pre[sta[top] - 1] + 1;
				top--;
			}
		}
		else sta[++top] = i;
		sum[i] = sum[i - 1] + pre[i];
	}
	int x, l, r;
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d%d", &x, &l, &r);
		printf("%lld\n", sum[r] - sum[l - 1] - pre[l - 1] * (pre[r] - pre[l - 1]));
		// sum[r] - sum[l - 1]表示询问区间内所有点向前延申的互不包含的括号个数之和
		// 即以每个点为结尾的合法括号序个数之和
		// 此时存在一部分序列超出 l 至 r 范围，需要减去这部分答案 
		// 已知 l 至 r 一定是一个合法序列
		// 因此超出范围的序列一定会与  l 至 r 整体构成一整个互不包含的括号序 
		// 那么超出部分一定由l-1起的连续延申的括号序组成
		// 未超出部分一定会以r为最右端，l为最左端
		// 超出部分括号个数与未超出部分括号个数的乘积即为多余答案 
	}
	return 0;
}


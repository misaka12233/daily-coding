#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
char s[maxn];
int n, m;
namespace SA
{
	int sa[maxn], rk[maxn], bkt[maxn], t[maxn], ht[maxn];
	// sa[i]: 排名为i的后缀是以sa[i]为起点的后缀 
	// rk[i]: 以i为起点的后缀排名为rk[i]
	// ht[i]: sa[i]与sa[i-1]对应的后缀的最长公共前缀(LCP) 
	// 后缀的前缀即为子串 
	// 以x为起点的后缀与以y为起点的后缀的LCP：min(ht[rk[x+1]]...ht[rk[y]]) (设rk[x] < rk[y])
	// 可重叠最长重复子串：ht数组的最大值 
	// 不可重叠最长重复子串：二分答案
	// 本质不同子串数量： sum(n-sa[i]+1-height[i])
	void Radsort()
	{
		for (int i = 1; i <= m; i++)
			bkt[i] = 0;
		for (int i = 1; i <= n; i++)
			bkt[rk[i]]++;
		for (int i = 2; i <= m; i++)
			bkt[i] += bkt[i - 1];
		for (int i = n; i >= 1; i--)
			sa[bkt[rk[t[i]]]--] = t[i];
	}
	void Sufsort()
	{
		m = 100;
		for (int i = 1; i <= n; i++)
			rk[i] = s[i] - '0' + 1, t[i] = i;
		Radsort();
		for (int k = 1, cnt = 0; cnt < n; k <<= 1)
		{
			cnt = 0;
			for (int i = n - k + 1; i <= n; i++) 
				t[++cnt] = i;
			for (int i = 1; i <= n; i++)
				if (sa[i] > k)
					t[++cnt] = sa[i] - k;
			Radsort();
			swap(rk, t);
			rk[sa[1]] = 1, cnt = 1; 
			for (int i = 2; i <= n; i++)
				rk[sa[i]] = (t[sa[i]] == t[sa[i - 1]] && t[sa[i] + k] == t[sa[i - 1] + k])? cnt : ++cnt;
			m = cnt;
		}
	}
	void getht()
	{
		for (int i = 1, k = 0; i <= n; i++)
		{
			if (k) 
				k--;
			int j = sa[rk[i] - 1];
			while (s[i + k] == s[j + k]) 
				k++;
			ht[rk[i]] = k;
		}
	}
} using namespace SA;
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	Sufsort();
	for (int i = 1; i <= n; i++)
		printf("%d ", sa[i]);
	return 0;
}


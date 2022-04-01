#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
char s[maxn];
int n, m;
namespace SA
{
	int sa[maxn], rk[maxn], bkt[maxn], t[maxn], ht[maxn];
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


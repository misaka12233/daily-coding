#include<bits/stdc++.h>
using namespace std;

template<typename T> bool chkmx(T &a, T b) { return a<b ? a=b, 1 : 0; }

typedef long long ll;
const int mod = 998244353;
const int maxn = 1000000 + 10;
int m;
ll p[maxn];
int z1[maxn]; // s µÄ z
int z2[maxn]; // st µÄ z
char st[maxn];
char s[maxn], t[maxn];
void z_func(char s[], int n, int z[])
{
	int l = 0, r = 0; z[0] = 0;
	for (int i=1; i<n; ++i)
	{
		z[i] = i < r ? min(z[i-l], r-i) : 0;
    	while (i+z[i] < n && s[i+z[i]] == s[z[i]]) ++z[i];
    	if (chkmx(r, i+z[i])) l = i;
	}
}
int main()
{
	scanf("%d", &m);
	scanf("%s", s);
	scanf("%s", t);
	int l1 = strlen(s), l2 = strlen(t), ans = 0;
	int l = l1 + l2;
	if (l % 2 != 0)
	{
		for (int i = 1; i <= m; i++)
			printf("0 ");
		return 0;
	}
	p[0] = 1;
	for (int i = 1; i <= m; i++)
		p[i] = p[i - 1] * 26 % mod;
	if (l1 >= l2)
	{
		z_func(s, l1, z1);
		for (int i = 0; i < l2; i++)
			st[i] = t[i];
		for (int i = 0; i < l1; i++)
			st[l2 + i] = s[i];
		z_func(st, l, z2);
		for (int i = 1; i <= m; i++)
		{
			ans = 0;
			if (i + l / 2 < l1)
			{
				if (z2[(l1 - l2) / 2 + l2] >= l2 && z1[i + l / 2] >= l1 - i - l / 2)
					ans = 1;
			}
			else
			{
				if (z2[(l1 - l2) / 2 + l2] >= l2)
					ans = p[i + l / 2 - l1]; 
			}
			printf("%d ", ans);
		}
	}
	else
	{
		z_func(t, l2, z1);
		for (int i = 0; i < l1; i++)
			st[i] = s[i];
		for (int i = 0; i < l2; i++)
			st[l1 + i] = t[i];
		z_func(st, l, z2);
		for (int i = 1; i <= m; i++)
		{
			ans = 0;
			if (i + l / 2 < l2)
			{
				if (z2[(l2 - l1) / 2 + l1] >= l1 && z1[i + l / 2] >= l2 - i - l / 2)
					ans = 1;
			}
			else
			{
				if (z2[(l2 - l1) / 2 + l1] >= l1)
					ans = p[i + l / 2 - l2];
			}
			printf("%d ", ans);
		}
	}
	return 0;
}


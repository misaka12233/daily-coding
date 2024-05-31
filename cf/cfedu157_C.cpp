#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
struct node{
	char s[8];
	int val[2];
	int len;
	void calc(int l)
	{
		val[0] = val[1] = 50;
		for (int i = 0; i < l && i < len; i++)
			val[0] += s[i] - '0';
		for (int i = l; i < 2 * l && i < len; i++)
			val[0] -= s[i] - '0';
		for (int i = len - 1; i >= len - l && i >= 0; i--)
			val[1] += s[i] - '0';
		for (int i = len - 1 - l; i >= len - 2 * l && i >= 0; i--)
			val[1] -= s[i] - '0';
	}
}a[maxn];
int cnt[11][100];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", a[i].s);      
		a[i].len = strlen(a[i].s);
	}
	long long ans = 0; 
	for (int len = 2; len <= 10; len += 2)
	{
		for (int i = 1; i <= 10; i++)
			for (int j = 0; j < 100; j++)
				cnt[i][j] = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i].len < len)
			{
				a[i].calc(len / 2);
				cnt[a[i].len][a[i].val[0]]++;
			}
		}
		for (int i = 1; i <= n; i++)
			if (a[i].len < len)
				ans = ans + cnt[len - a[i].len][a[i].val[1]];
	}
	printf("%lld\n", ans);
	return 0;
}


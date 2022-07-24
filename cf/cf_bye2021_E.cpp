#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int T;
int n;
char s[maxn], t[maxn];
long long q[30][maxn];
int st[30], ed[30];
int c[maxn];
int lowbit(int x){ return x & -x;}
void add(int x, int val)
{
	for (int i = x; i <= n; i += lowbit(i))
		c[i] += val;
}
long long query(int x)
{
	int res = 0;
	for (int i = x; i; i -= lowbit(i))
		res += c[i];
	return res;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 0; i < 26; i++) 
			st[i] = 1, ed[i] = 0;
		scanf("%d", &n);
		scanf("%s%s", s + 1, t + 1);
		for (int i = 1; i <= n; i++)
		{
			c[i] = 0;
			int k = s[i] - 'a';
			ed[k]++;
			q[k][ed[k]] = i;
		}
		long long ans, now;
		ans = -1;
		now = 0;
		for (int i = 1; i <= n; i++)
		{
			int k = t[i] - 'a';
			for (int j = 0; j < k; j++)
			{
				if (st[j] <= ed[j] && (ans == -1 || ans > now + q[j][st[j]] - query(q[j][st[j]]) - 1))
					ans = now + q[j][st[j]] - query(q[j][st[j]]) - 1;
			}
			if (st[k] <= ed[k])
			{
				now = now + q[k][st[k]] - query(q[k][st[k]]) - 1;
				add(q[k][st[k]], 1);
				st[k]++;
			}
			else
			{
				now = -1;
				break;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}


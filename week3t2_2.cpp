#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
const int mod = 998244353; 
int T;
int n;
int nxt[maxn];
bool vis[maxn];
int len[maxn], p[maxn], tot;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", nxt + i);
		for (int i = 1; i <= n; i++)
			vis[i] = len[i] = p[i] = 0;
		tot = 0;
		for (int i = 1; i <= n; i++)
		{
			int now = i;
			if (!vis[now])
			{
				int cnt = 0;
				while (!vis[now])
				{
					vis[now] = true;
					cnt++;
					now = nxt[now];
				}
				len[++tot] = cnt;
			}
		}
		for (int i = 1; i <= tot; i++)
		{
			int now = len[i];
			for (int j = 2; j * j <= len[i]; j++)
			{
				int cnt = 0;
				while (now % j == 0)
				{
					now /= j;
					cnt++;
				}
				p[j] = max(p[j], cnt);
			}
			p[now] = max(p[now], 1);
		}
		int ans = 1;
		for (int i = 2; i <= n; i++)
			for (int j = 1; j <= p[i]; j++)
				ans = 1ll * ans * i % mod;
		printf("%d\n", ans);
	}
	return 0;
}


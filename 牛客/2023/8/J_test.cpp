#include<bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
bool vis[maxn];
int n, p[maxn];
int notpri[maxn], pri[maxn];
void getP(int m)
{
	int tp = 0;
	notpri[1] = 1;
	for (int i = 2; i <= m; ++i)
	{
		if (!notpri[i]) pri[++tp] = i;
		for (int j = 1; j <= tp && pri[j] * i <= m; ++j)
		{
			notpri[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
		}
	}
}
bool prime(int x)
{
	if (x <= 2) return false;
	return !notpri[x];
}
bool check(int val, int id)
{
	if (id == 1) return true;
	return prime(abs(val - p[id - 1])) || prime(val + p[id - 1]);
}
bool dfs(int x)
{
	if (x == n + 1)
	{
		for (int i = 1; i <= n; i++)
			printf("%d ", p[i]);
		printf("\n");
		return true;
	}
	for (int i = max(x - 4, 1); i <= n && i <= x + 4; i++)
	{
		if (!vis[i] && check(i, x))
		{
			vis[i] = true;
			p[x] = i;
			if (dfs(x + 1))
				return true;
			vis[i] = false;
		}
	}
	return false;
} 
int main()
{
	//freopen("my.in", "r", stdin);
	//freopen("my.out", "w", stdout);
	getP(200000);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			vis[i] = false;
		dfs(1);
	}
	return 0;
}


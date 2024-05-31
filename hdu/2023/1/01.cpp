#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 3000 + 10;
int T;
int n, m, ans_t, ans_n;
int node[maxn][3], siz;
int delvis[maxn], num;
int fa[maxn], dep[maxn], vis[maxn];
int head[maxn], ver[maxn << 1], nxt[maxn << 1], tot;

int exgcd(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int gcd = exgcd(b, a % b, y, x);
	y = y - a / b * x;
	//printf("%d*%d + %d*%d = %d\n", x, a, y, b, gcd);
	return gcd;
}
void dfs(int u, int p)
{
	fa[u] = p;
	dep[u] = dep[p] + 1;
	for (int i = head[u]; i; i = nxt[i])
	{
		int v = ver[i];
		if (v == p) continue;
		dfs(v, u);
	}
}
int getlca(int u, int v)
{
	int isswap = 1;
	if (dep[u] < dep[v]) 
	{
		swap(u, v);
		isswap = 2;
	}
	for (; dep[u] != dep[v]; u = fa[u])
	{
		if (vis[u] != 0)
		{
			node[++siz][0] = u;
			node[siz][1] = vis[u];
			node[siz][2] = isswap;
		}
		else
		{
			vis[u] = isswap;
			delvis[++num] = u;
		}
	}
	for (; u != v; u = fa[u], v = fa[v])
	{
		if (vis[u] != 0)
		{
			node[++siz][0] = u;
			node[siz][1] = vis[u];
			node[siz][2] = isswap;
		}
		else
		{
			vis[u] = isswap;
			delvis[++num] = u;
		}
		if (vis[v] != 0)
		{
			node[++siz][0] = v;
			node[siz][1] = vis[v];
			node[siz][2] = 3 - isswap;
		}
		else
		{
			vis[v] = 3 - isswap;
			delvis[++num] = v;
		}
	}
	if (vis[u] != 0)
	{
		node[++siz][0] = u;
		node[siz][1] = vis[u];
		node[siz][2] = isswap;
	}
	else
	{
		vis[u] = isswap;
		delvis[++num] = u;
	}
	return u;
}
void sol()
{
	scanf("%d%d", &n, &m);
	tot = 0;
	for (int i = 1; i <= n; i++) head[i] = 0;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		ver[++tot] = v; nxt[tot] = head[u]; head[u] = tot;
		ver[++tot] = u; nxt[tot] = head[v]; head[v] = tot;
	}
	dfs(1, 0);
	for (int i = 1; i <= m; i++)
	{
		int sa, ta, sb, tb;
		scanf("%d%d%d%d", &sa, &ta, &sb, &tb);
		ans_t = inf;
		ans_n = num = siz = 0;
		int lcaa = getlca(sa, ta);
		int lcab = getlca(sb, tb);
		int La = dep[sa] + dep[ta] - 2 * dep[lcaa];
		int Lb = dep[sb] + dep[tb] - 2 * dep[lcab];
		int A = 2 * La;
		int B = 2 * Lb; 
		int x, y, gcd;
		gcd = exgcd(A, B, x, y);
		int shiftx = B / gcd, shifty = A / gcd;
		for (int i = 1; i <= siz; i++)
		{
			int a, b;
			int u = node[i][0];
			if (node[i][1] == 1) 
				a = dep[sa] - dep[u];
			else 
				a = dep[sa] + dep[u] - 2 * dep[lcaa];
			if (node[i][2] == 1) 
				b = dep[sb] - dep[u];
			else 
				b = dep[sb] + dep[u] - 2 * dep[lcab];
			if ((a - b) % gcd == 0)
			{
				int kb = ((y * (a - b) / gcd) % shifty + shifty) % shifty;
				if (B * kb + b < ans_t)
				{
					ans_t = B * kb + b;
					ans_n = u;
					//printf("%d %d %d\n", kb, ans_t, ans_n);
				}
			}
			if ((a + b - B) % gcd == 0)
			{
				int kb = ((y * (a + b - B) / gcd) % shifty + shifty) % shifty;
				if (B * kb + B - b < ans_t)
				{
					ans_t = B * kb + B - b;
					ans_n = u;
					//printf("%d %d %d\n", kb, ans_t, ans_n);
				}
			}
			if ((A - a - b) % gcd == 0)
			{
				int kb = ((y * (A - a - b) / gcd) % shifty + shifty) % shifty;
				if (B * kb + b < ans_t)
				{
					ans_t = B * kb + b;
					ans_n = u;
					//printf("%d %d %d\n", kb, ans_t, ans_n);
				}
			}
			if ((A - B - a + b) % gcd == 0)
			{
				int kb = ((y * (A - B - a + b) / gcd) % shifty + shifty) % shifty;
				if (B * kb + B - b < ans_t)
				{
					ans_t = B * kb + B - b;
					ans_n = u;
					//printf("%d %d %d\n", kb, ans_t, ans_n);
				}
			}
		}
		for (int i = 1; i <= num; i++) vis[delvis[i]] = 0;
		if (ans_n != 0) printf("%d\n", ans_n);
		else puts("-1");
	}
}
int main()
{
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}
/*
2
9 5
1 2
1 3
1 9
2 4
2 5
2 6
3 7
3 8
4 9 8 5
*/


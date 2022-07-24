#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 10;
ll n;
struct node{
	int ed;
	int val;
	int nxt;
}edge[maxn << 1];
int head[maxn], tot;
void add(int x, int y, int v)
{
	tot++;
	edge[tot].ed = y;
	edge[tot].val = v;
	edge[tot].nxt = head[x];
	head[x] = tot;
}
ll siz[maxn], cnt[maxn], ans;
void getsiz(int x, int fa)
{
	siz[x]++;
	for (int i = head[x]; i; i = edge[i].nxt)
	{
		int y = edge[i].ed;
		if (y == fa) continue;
		getsiz(y, x);
		siz[x] += siz[y];
	}
}
void dfs(int x, int fa)
{
	for (int i = head[x]; i; i = edge[i].nxt)
	{
		int y = edge[i].ed;
		if (y == fa) continue;
		ans += siz[y] * (n - siz[y]);
		int v = edge[i].val;
		ll pre = cnt[v];
		dfs(y, x);
		ans -= pre * siz[y] + (cnt[v] - pre) * (n - siz[y]) - pre * (cnt[v] - pre) + pre * (siz[y] - cnt[v] + pre) + (cnt[v] - pre) * (n - siz[y] - pre);
		cnt[v] = pre + siz[y];
	}
}
int main()
{
	scanf("%lld", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		add(x, y, v);
		add(y, x, v);
	}
	getsiz(1, 0);
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}


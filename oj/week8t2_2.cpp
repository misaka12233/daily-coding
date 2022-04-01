#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
const int maxm = 2000000 + 10;
struct node{
	int st, ed;
	ll val;
}edge[maxm];
int n, m;
ll ans;
int fa[maxn];
bool cmp(node x, node y)
{
	return x.val < y.val;
}
int getfa(int x) //并查集 
{
	if (fa[x] == x) return fa[x];
	return fa[x] = getfa(fa[x]);
}
void Kruskal() //Kruskal算法
{
	for (int i = 1; i <= n; i++) fa[i] = i;
	sort(edge + 1, edge + m + 1, cmp);
	for (int i = 1; i <= m; i++)
	{
		int fx = getfa(edge[i].st), fy = getfa(edge[i].ed);
		if (fx != fy || edge[i].val < 0)
		{
			ans += edge[i].val;
			fa[fx] = fy;
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%lld", &edge[i].st, &edge[i].ed, &edge[i].val);
	Kruskal();
	bool chk = true;
	int now = getfa(1);
	for (int i = 2; i <= n; i++)
	{
		if (now != getfa(i))
		{
			chk = false;
			break;
		}
	}
	if (chk)
		printf("%lld\n", ans);
	else
		puts("bad idea");
	return 0;
}


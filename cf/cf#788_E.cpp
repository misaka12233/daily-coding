#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n, cnt;
struct node{
	node() {}
	node(int y, int id): y(y), id(id) {}
	int y;
	int id;
};
vector<node> e[maxn];
int val_v[maxn], val_e[maxn];
void dfs(int x, int fa, int typ)
{
	for (auto edge : e[x])
	{
		int y = edge.y, id = edge.id;
		if (y == fa) continue;
		cnt++;
		if (typ == 0)
		{
			val_v[y] = cnt;
			val_e[id] = cnt + n;
		}
		else
		{
			val_v[y] = cnt + n;
			val_e[id] = cnt;
		}
		dfs(y, x, typ ^ 1);
	}
}
void sol()
{
	scanf("%d", &n);
	n = 1 << n;
	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		e[i].clear();
		val_v[i] = val_e[i] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(node(y, i));
		e[y].push_back(node(x, i)); 
	}
	val_v[1] = n;
	dfs(1, 0, 0);
	printf("1\n");
	for (int i = 1; i <= n; i++)
		printf("%d ", val_v[i]);
	printf("\n");
	for (int i = 1; i < n; i++)
		printf("%d ", val_e[i]);
	printf("\n");
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}


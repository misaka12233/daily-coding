#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
int n;
struct node{
	int r, g, b;
}c[maxn]; 
queue<int> q;
vector<int> e_in[maxn];
vector<int> e_out[maxn];
int indeg[maxn], res[maxn];
bool smaller(int x, int y)
{
	return (c[x].r < c[y].r) && (c[x].g < c[y].g) && (c[x].b < c[y].b);
}
void add(int x, int y)
{
	if (x == 1) x = 2;
	if (y == 1) y = 2;
	e_out[x].push_back(y);
	e_in[y].push_back(x);
	indeg[y]++;
}
bool check_res()
{
	for (int i = 2; i <= n; i++)
	{
		if (indeg[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto &v : e_in[u])
			res[u] = max(res[u], res[v] + 1);
		if (res[u] > 255)
			return false;
		for (auto &v : e_out[u])
		{
			indeg[v]--;
			if (indeg[v] == 0)
				q.push(v);
		}
	}
	for (int i = 2; i <= n; i++)
		if (indeg[i] != 0)
			return false;
	res[1] = res[2];
	return true;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &c[i].r, &c[i].g, &c[i].b);
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (smaller(i, j))
				add(i, j);
			else if (smaller(j, i))
				add(j, i);
		}
	}
	if (check_res())
	{
		for (int i = 1; i <= n; i++)
			printf("%d\n", res[i]);
	}
	else puts("-1");
	return 0;
}


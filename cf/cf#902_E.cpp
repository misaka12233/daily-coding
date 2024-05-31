#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 200000 + 10;
int n, ans;
int a[maxn];
queue<int> q;
int col[maxn];
bool tag[maxn];
int indeg[maxn];
bool check(int u)
{
	if (indeg[u] == 0) return true;
	indeg[u] = 0;
	int v = a[u];
	if (col[v] == 0)
	{
		col[v] = 3 - col[u];
		return check(v);
	}
	else if (col[v] == 2)
		return check(v);
	else
	{
		if (col[u] == 1)
			return false;
		else
			return check(v);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		indeg[a[i]]++;
	}
	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0)
			q.push(i);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		if (col[u] == 0)
			col[u] = 1;
		int v = a[u];
		indeg[v]--;
		if (col[u] == 1)
			col[v] = 2;
		if (indeg[v] == 0)
			q.push(v);
	}
	for (int i = 1; i <= n; i++)
	{
		if (indeg[i] != 0 && col[i] == 2)
		{
			if (!check(i))
				ans = -1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (indeg[i] != 0)
		{
			col[i] = 1;
			if (!check(i))
				ans = -1;
		}
	}
	if (ans != -1)
	{
		for (int i = 1; i <= n; i++)
			if (col[i] == 1)
				ans++;
		printf("%d\n", ans);
		for (int i = 1; i <= n; i++)
			if (col[i] == 1)
				printf("%d ", a[i]);
	}
	else puts("-1");
}


#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
struct node{
	int ed;
	int nxt;
}edge[maxn];
int head[maxn], tot, ans;
void add(int x, int y)
{
	tot++;
	edge[tot].ed = y;
	edge[tot].nxt = head[x];
	head[x] = tot;
}

int dfn[maxn], low[maxn], Index;
int sta[maxn], top;
bool insta[maxn];
void tarjan(int x)
{
	dfn[x] = low[x] = ++Index;
	sta[++top] = x;
	insta[x] = true;
	for (int i = head[x]; i ; i = edge[i].nxt)
	{
		int y = edge[i].ed;
		if (!dfn[y])
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if (insta[y]) low[x] = min(low[x], dfn[y]);
	}
	if (low[x] == dfn[x])
	{
		if (sta[top] == x)
		{
			insta[sta[top]] = false;
			top--;
		}
		else
		{
			while (sta[top] != x)
			{
				insta[sta[top]] = false;
				top--;
				ans++;
			}
			insta[sta[top]] = false;
			top--;
			ans++;
		}
	}
}

int n;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		add(i, x);
		if (i == x)
			ans++;
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	printf("%d", ans);
	return 0;
}


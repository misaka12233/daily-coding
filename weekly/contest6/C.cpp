#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2000 + 10;
int n;
int a[maxn];
int in[maxn], out[maxn];
vector<int> e[maxn];
int id[maxn];
bool dfs(int x, int c)
{
	id[x] = c;
	for (auto y : e[x])
	{
		if (id[y] != 0)
		{
			if (id[y] == id[x])
				return false;
		}
		else
		{
			if (!dfs(y, 3 - c))
				return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++)
	{
		scanf("%d", a + i);
		if (a[i] > 0)
			in[a[i]] = i;
		else
			out[-a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (in[i] < in[j] && in[j] < out[i] && out[i] < out[j])
			{
				e[i].push_back(j);
				e[j].push_back(i);
			}
		}
	}
	bool res = true;
	for (int i = 1; i <= n; i++)
		if (id[i] == 0)
			if (!dfs(i, 1))
				res = false;
	if (res)
	{
		for (int i = 1; i <= n; i++)
			putchar((id[i] == 1)? 'G' : 'S');
		putchar('\n');
	}
	else
		puts("*");
	return 0;
}


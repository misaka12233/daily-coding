#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 4000 + 10;
typedef pair<int, int> pii;
int n;
int deg[maxn], fa[maxn], siz[maxn], mn[maxn];
char s[maxn];
int getfa(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = getfa(fa[x]);
}
void sol()
{
	scanf("%d", &n);
	siz[0] = deg[0] = inf;
	for (int i = 1; i <= n; i++)
	{
		mn[i] = 0;
		deg[i] = 0;
		fa[i] = i;
		siz[i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s + 1);
		for (int j = i + 1; j <= n; j++)
		{
			if (s[j] == '1')
			{
				deg[i]++;
				deg[j]++;
				int x = getfa(i), y = getfa(j);
				if (x != y)
				{
					fa[x] = y;
					siz[y] += siz[x];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (fa[i] == i && siz[i] == 1)
		{
			printf("1\n%d\n", i);
			return;
		}
		if (fa[i] == i && siz[i] == n)
		{
			printf("0\n");
			return;
		}
		int f = getfa(i);
		if (deg[mn[f]] > deg[i])
		mn[f] = i;
	}
	int cntK = 0, mnK = 0;
	for (int i = 1; i <= n; i++)
	{
		if (fa[i] == i)
		{
			if (deg[mn[i]] < siz[i] - 1)
			{
				printf("1\n%d\n", mn[i]);
				return;
			}
			else
			{
				cntK++;
				if (siz[mnK] > siz[i])
					mnK = i;
			}
		}
	}
	if (cntK > 2)
	{
		cntK = 2;
		printf("2\n");
		for (int i = 1; i <= n; i++)
		{
			if (fa[i] == i)
			{
				printf("%d ", i);
				cntK--;
				if (cntK == 0)
				{
					printf("\n");
					return;
				}
			}
		}
	}
	else
	{
		printf("%d\n", siz[mnK]);
		for (int i = 1; i <= n; i++)
		{
			if (getfa(i) == mnK)
				printf("%d ", i);
		}
		printf("\n");
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 50000 + 10;
int m;
vector<int> a[maxn];
bool vis[maxn];
int ans[maxn];
bool sol()
{
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int n;
		scanf("%d", &n);
		a[i].clear();
		for (int j = 1; j <= n; j++)
		{
			int x;
			scanf("%d", &x);
			vis[x] = false;
			a[i].push_back(x);
		}
	}
	for (int i = m; i >= 1; i--)
	{
		bool getans = false;
		for (auto x : a[i])
		{
			if (!vis[x])
			{
				ans[i] = x;
				getans = true;
			}
			vis[x] = true;
		}
		if (!getans) return false;
	}
	return true;
} 
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		if (sol())
		{
			for (int i = 1; i <= m; i++)
				printf("%d ", ans[i]);
			printf("\n");
		}
		else
			puts("-1");
	}
	return 0;
}


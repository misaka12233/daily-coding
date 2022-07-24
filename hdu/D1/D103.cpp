#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1024 + 10;
int T;
int n, m;
int v[maxn], w[maxn]; 
bitset<1024> f[2][maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d%d", v + i, w + i);
		for (int i = 0; i <= 1023; i++)
			f[0][i].reset();
		f[0][0][0] = 1;
		int now = 1, pre = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= 1023; j++)
				f[now][j] = f[pre][j] | (f[pre][j ^ w[i]] << v[i]);
			swap(now, pre);
		}
		bool can = false;
		for (int i = 1023; i >= 0; i--)
		{
			if (f[pre][i][m])
			{
				printf("%d\n", i);
				can = true;
				break;
			}
		}
		if (!can)
			puts("-1");
	}
	return 0;
}


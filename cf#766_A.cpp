#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
int n, m;
int r, c;
char s[maxn][maxn]; 
bool vis_r[maxn], vis_c[maxn], ans;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d", &n, &m, &r, &c);
		for (int i = 1; i <= n; i++)
			vis_r[i] = false;
		for (int i = 1; i <= m; i++)
			vis_c[i] = false;
		ans = false;
		for (int i = 1; i <= n; i++)
			scanf("%s", s[i] + 1);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (s[i][j] == 'B')
				{
					vis_r[i] = true;
					vis_c[j] = true;
					ans = true;
				}
			}
		}
		if (ans)
		{
			if (s[r][c] == 'B')
				puts("0");
			else if (vis_r[r] || vis_c[c])
				puts("1");
			else
				puts("2");
		}
		else puts("-1");
	}
	return 0;
}


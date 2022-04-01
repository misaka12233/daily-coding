#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int T;
int n;
char s[maxn][5];
bool vis[maxn], ans;
int getnum(char c)
{
	return c - 'a' + 1;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		ans = false;
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", s[i]);
			int l = strlen(s[i]);
			if (l == 1) ans = true;
			else if (l == 2)
			{
				vis[getnum(s[i][0]) * 30 + getnum(s[i][1])] = true;
				ans |= vis[getnum(s[i][1]) * 30 + getnum(s[i][0])];
				for (int j = 1; j <= 26; j++)
				ans |= vis[getnum(s[i][1]) * 30 * 30 + getnum(s[i][0]) * 30 + j];
			}
			else
			{
				vis[getnum(s[i][0]) * 30 * 30 + getnum(s[i][1]) * 30 + getnum(s[i][2])] = true;
				ans |= vis[getnum(s[i][2]) * 30 * 30 + getnum(s[i][1]) * 30 + getnum(s[i][0])];
				ans |= vis[getnum(s[i][2]) * 30 + getnum(s[i][1])];
			}
		}
		if (ans) puts("YES");
		else puts("NO");
	}
	return 0;
}


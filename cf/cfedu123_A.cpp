#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
char s[10]; 
int vis[300];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		memset(vis, 0, sizeof(vis));
		scanf("%s", s);
		int l = strlen(s);
		bool ans = true;
		for (int i = 0; i < l; i++)
		{
			if (s[i] == 'R' || s[i] == 'G' || s[i] == 'B')
			{
				if (!vis[s[i] + 'a' - 'A']) 
					ans = false;
			}
			else vis[s[i]] = true;
		}
		if (ans) puts("YES");
		else puts("NO");
	}
	return 0;
}


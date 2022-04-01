#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int relation[maxn][maxn];
int T;
int n;
bool ans;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		ans = true;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &relation[i][j]);
		for (int i = 1; i <= n; i++)
		{
			if (!relation[i][i])
				ans = false;
			if (!ans)
				break;
			for (int j = i + 1; j <= n; j++)
			{
				bool chk_up = false, chk_down = false;
				for (int k = 1; k <= n; k++)
				{
					if (relation[i][k] && relation[j][k])
					{
						bool chk = true;
						for (int l = 1; l <= n; l++)
						{
							if (relation[i][l] && relation[j][l] && !relation[k][l])
							{
								chk = false;
								break;
							}
						}
						chk_up = chk_up || chk;
					}
					if (relation[k][i] && relation[k][j])
					{
						bool chk = true;
						for (int l = 1; l <= n; l++)
						{
							if (relation[l][i] && relation[l][j] && !relation[l][k])
							{
								chk = false;
								break;
							}
						}
						chk_down = chk_down || chk;
					}
					if (relation[i][j] && relation[j][i])
					{
						if (relation[i][k] ^ relation[j][k] || relation[k][i] ^ relation[k][j])
							ans = false;
					}
					else
					{
						if (relation[i][k] && relation[k][j] && !relation[i][j])
							ans = false;
						if (relation[j][k] && relation[k][i] && !relation[j][i])
							ans = false;
					}
					if (!ans)
						break;
				}
				if (!chk_up || !chk_down)
					ans = false;
				if (!ans)
					break;
			}
			if (!ans)
				break;
		}
		if (ans)
			puts("Y");
		else
			puts("N");
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n;
int cnt[2][maxn];
int ans[maxn];
void sol()
{
	for (int i = 0; i < n; i++) 
		cnt[0][i] = cnt[1][i] = 0;
	for (int k = 1; k <= 3 * n; k++)
	{
		int p;
		char s[7];
		scanf("%d%s", &p, s);
		if (s[0] == 'Y') cnt[1][p]++;
		else cnt[0][p]++;
	}
	int ned = 0;
	bool unable = false;
	for (int i = 0; i < n; i++)
	{
		if (!cnt[0][i] || !cnt[1][i]) continue;
		if (cnt[0][i] > 1 && cnt[1][i] > 1) 
		{
			unable = true;
			break;
		}
		if (cnt[0][i] == 1 && cnt[1][i] == 1)
		{
			unable = true;
			break;
		}
		if (cnt[0][i] == 1) cnt[0][i]--;
		else cnt[1][i]--;
		ned++;
	}
	if (ned > 1 || unable) puts("-1");
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (cnt[0][i]) ans[i] = 0;
			else ans[i] = 1;
			if (cnt[ans[i]][i] == 1 && ned == 0)
			{
				unable = true;
				break;
			}
		}
		if (unable) puts("-1");
		else
		{
			for (int i = n - 1; i >= 0; i--)
				printf("%d", ans[i]);
			puts("");
		}
	}
}
int main()
{
	int T;
	while (scanf("%d", &n) != EOF)
	{
		sol();
	}
	return 0;
}


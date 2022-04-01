#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 64 + 10;
const int maxm = 1000 + 10;
int s[maxn], n, m;
bool relat[maxm][maxm], reflexive, symmetric, transitive;
int main()
{
	while (s[n] != -1)
		n++, scanf("%d", s + n);
	n--;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		relat[x][y] = true;
	}
	reflexive = symmetric = transitive = true;
	for (int i = 1; i <= n; i++)
	{
		reflexive = reflexive && relat[s[i]][s[i]];
		for (int j = 1; j <= n; j++)
		{
			symmetric = symmetric && ((relat[s[i]][s[j]] && relat[s[j]][s[i]]) || (!relat[s[i]][s[j]] && !relat[s[j]][s[i]]));
			for (int k = 1; k <= n; k++)
				if (relat[s[i]][s[j]] && relat[s[j]][s[k]])
					transitive = transitive && relat[s[i]][s[k]];
		}
	}
	if (reflexive)
		puts("reflexive");
	if (symmetric)
		puts("symmetric");
	if (transitive)
		puts("transitive");
	return 0;
}


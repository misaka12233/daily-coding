#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
int n, k;
char s[maxn]; 
int nxt[maxn]; 
int now[30], fir[30];
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	scanf("%d", &k);
	for (int i = 0; i < 26; i++)
		fir[i] = now[i] = n + 1;
	for (int i = 1; i <= n; i++)
	{
		if (fir[s[i] - 'a'] == n + 1)
			fir[s[i] - 'a'] = i;
		else
			nxt[now[s[i] - 'a']] = i;
		now[s[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++)
	{
		nxt[now[i]] = n + 1;
		now[i] = fir[i];
	}
	for (int t = k; t > 0; t--)
	{
		for (int i = 0; i < 26; i++)
			if (n - now[i] + 1 >= t)
			{
				printf("%c", s[now[i]]);
				for (int j = 0; j < 26; j++)
				{
					while (now[j] < now[i])
						now[j] = nxt[now[j]];
				}
				now[i] = nxt[now[i]];
				break;
			}
	}
	printf("\n");
	return 0;
}


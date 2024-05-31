#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1000010
using namespace std;
char s1[maxn], s2[maxn];
int n, m;
int nxt[maxn];
int main()
{
	scanf("%s%s", s1, s2);
	n = strlen(s1), m = strlen(s2);
	for (int i = n; i >= 1; i--)
		s1[i] = s1[i - 1];
	for (int i = m; i >= 1; i--)
		s2[i] = s2[i - 1];
	for (int i = 2, j = 0; i <= m; i++)
	{
		while (s2[j + 1] != s2[i] && j != 0)
			j = nxt[j];
		if (s2[j + 1] == s2[i])
			j++;
		nxt[i] = j;
	}
	for (int i = 1, j = 0; i <= n; i++)
	{
		while (s2[j + 1] != s1[i] && j != 0)
			j = nxt[j];
		if (s2[j + 1] == s1[i])
			j++;
		if (j == m)
		{
			printf("%d\n", i - m + 1);
			j = nxt[j];
		}
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", nxt[i]);
}

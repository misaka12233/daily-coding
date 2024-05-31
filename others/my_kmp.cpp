#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
int n, m;
char s[maxn], t[maxn];
int nxt[maxn];
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	scanf("%s", t + 1); 
	m = strlen(t + 1);
	int i = 2, j = 0;
	nxt[1] = 0;
	while (i <= m)
	{
		while (j != 0 && t[i] != t[j + 1])
			j = nxt[j];
		if (t[i] == t[j + 1])
			j++;
		nxt[i] = j;
		i++;
	}
	i = 1, j = 0;
	while (i <= n)
	{
		while (j != 0 && s[i] != t[j + 1])
			j = nxt[j];
		if (s[i] == t[j + 1])
			j++;
		if (j == m)
			printf("%d\n", i - m + 1);
		i++;
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", nxt[i]);
	printf("\n");
	return 0;
}


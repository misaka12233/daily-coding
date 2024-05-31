#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int T, n, m;
int nxt[maxn];
char t[maxn], s[maxn << 2];
bool cmp()
{
	int len = n + m + m;
	for(int i = 1, j = 0; i <= len; i++)
	{
		while (t[j+1] != s[i] && j != 0) j = nxt[j];
		if (t[j + 1] == s[i]) j++;
		if (j == m)
		{
			if (i != m && i != len)
				return false;
			else
				j = nxt[j];
		}
	}
	return true;
}
void sol()
{
	scanf("%d", &n);
	scanf("%s", t + 1);
	m = strlen(t + 1);
	
	for (int i = 2, j = 0; i <= m; i++)
	{
		while (t[j + 1] != t[i] && j != 0) j = nxt[j];
		if (t[j + 1] == t[i]) j++;
		nxt[i] = j;
	}
	
	for (int i = 1; i <= m; i++)
		s[i] = t[i];
	for (int i = m + 1; i <= m + n; i++)
		s[i] = '0';
	for (int i = 1; i <= m; i++)
		s[i + m + n] = t[i];
		
	if (cmp())
	{
		for (int i = 1; i <= n; i++)
			printf("0");
		printf("\n"); 
	}
	else
	{
		for (int i = 1; i <= n; i++)
			printf("1");
		printf("\n");
	}
}
int main()
{
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}


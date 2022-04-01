#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5000000 + 10;
char s[maxn];
int n, m;
int pos[75];
int ans[11];
int qry[75];
int main()
{
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; 2 * i + 1 < len; i++)
		swap(s[i], s[len - i - 1]);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", pos + i);
	memset(qry, -1, sizeof(qry));
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		qry[x] = i;
	}
	if (qry[0] >= 0)
		ans[qry[0]] = strlen(s);
	for (int i = 1; i <= n; i++)
	{
		len = strlen(s);
		int l = (len + 4) / 5;
		for (int j = 0; j < l; j++)
			s[len + l - j - 1] = s[len - (pos[i] + j) % len - 1];
		if (qry[i] >= 0)
			ans[qry[i]] = strlen(s);
	}
	len = strlen(s);
	for (int i = 0; 2 * i + 1 < len; i++)
		swap(s[i], s[len - i - 1]);
	for (int i = 0; i < m; i++)
		puts(s + len - ans[i]);
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int t[maxn];
char ans[maxn], c[maxn];
int getTime()
{
	char s[maxn];
	scanf("%s", s);
	scanf("%s", s);
	if (s[0] == 'G')
		return 0;
	scanf("%s", s);
	int r = 0, l = strlen(s);
	for (int i = 1; i < l; i++)
		r = r * 10 + s[i] - '0';
	scanf("%s", s);
	return r;
}
int main()
{
	int len;
	t[0] = 5;
	for (int i = 1; i <= 20; i++)
		t[i] = t[i - 1] + 9;
	for (int i = 0; i < 26; i++)
		c[i] = 'a' + i;
	for (int i = 0; i < 26; i++)
		c[i + 26] = 'A' + i;
	for (int i = 0; i < 10; i++)
		c[i + 52] = '0' + i;
	int now;
	for (len = 1; len <= 20; len++)
	{
		ans[len - 1] = 'a';
		printf("%s\n", ans);
		fflush(stdout);
		now = getTime();
		if (now == 0)
			return 0;
		else if (now != t[0])
			break;
	}
	for (int i = 0; i < len; i++)
	{
		if (t[i + 1] != now) continue;
		for (int j = 0; j < 62; j++)
		{
			ans[i] = c[j];
			printf("%s\n", ans);
			fflush(stdout);
			now = getTime();
			if (now == 0)
				return 0;
			else if (now != t[i + 1])
				break;
		}
	}
	return 0;
}


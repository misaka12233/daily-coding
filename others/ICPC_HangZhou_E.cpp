#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
const int maxm = 5000000 + 10;
int n;
char s[maxm];
int len[maxn][17];
struct node{
	int len;
	int c[26];
};
int cnt[maxn][26];
node lim[maxn];
bool cmp(node x, node y)
{
	return x.len < y.len;
}
int getmin(int l, int r)
{
	int k = log(r - l + 1) / log(2);
	return min(len[l][k], len[r - (1 << k) + 1][k]);
}
bool sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		len[i][0] = strlen(s);
		for (int j = 0; j < 26; j++)
			cnt[i][j] = 0;
		for (int j = 0; j < len[i][0]; j++)
			cnt[i][s[j] - 'a']++;
	}
	for (int l = 1; l < 17; l++)
		for (int i = 1; i + (1 << l) < n; i++)
			len[i][l] = min(len[i][l - 1], len[i + (1 << (l - 1))][l - 1]);
	for (int i = 1; i <= n; i++)
	{
		lim[i].len = 0;
		for (int j = 0; j < 26; j++)
		{
			lim[i].c[j] = cnt[i][j];
			lim[i].len += cnt[i][j];
		}
		int now = i;
		while (now > 1)
		{
			int l = 1, r = now - 1;
			while (l < r)
			{
				int mid = l + r >> 1;
				if (getmin(mid + 1, now - 1) <= lim[i].len) l = mid + 1;
				else r = mid;
			}
			int t = lim[i].len / len[l][0];
			lim[i].len %= len[l][0];
			for (int j = 0; j < 26; j++)
			{
				lim[i].c[j] -= cnt[l][j] * t;
				if (lim[i].c[j] > cnt[l][j])
					return false;
			}
			now = l;
		}
	}
	sort(lim + 1, lim + n + 1, cmp);
	int now = 0;
	int nowc[26] = {0};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 26; j++)
			while (nowc[j] < lim[i].c[j])
				s[now++] = 'a' + j, nowc[j]++;
		if (now > lim[i].len)
			return false; 
	}
	s[now] = '\0';
	return true;
}
void getans()
{
	puts("YES");
	printf("%s\n", s);
	for (int i = 2; i <= n; i++)
	{
		for (int j = len[i - 1][0]; j < len[i][0]; j++)
			s[j] = s[j % len[i - 1][0]];
		s[len[i][0]] = '\0';
		printf("%s\n", s);
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		if (sol())
			getans();
		else
			puts("NO");
	}
	return 0;
}


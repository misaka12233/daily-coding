#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5000 + 10;
int n, w;
int a[maxn];
int v[maxn][maxn];
int f[maxn], g[maxn];
int st[maxn], ed[maxn], c, len[maxn];
string s[maxn];
// dp[n][r] = min(dp[i][r] + v[n][i+1]) + 1
// v[n][i] = max(a[i...n])
bool check(int r)
{
	for (int i = 1; i <= n; i++)
	{
		f[i] = inf;
		for (int j = max(0, i - r); j < i; j++)
			if (f[i] > f[j] + v[i][j + 1] + 1)
				f[i] = f[j] + v[i][j + 1] + 1, g[i] = j;
	}
	return f[n] - 1 <= w;
}
void getans(int x)
{
	if (x == 0) return;
	getans(g[x]);
	c++;
	st[c] = g[x] + 1;
	ed[c] = x;
}
int main()
{
	cin >> n >> w;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		a[i] = s[i].length();
	}
	for (int i = 1; i <= n; i++)
		for (int j = i; j > 0; j--)
			v[i][j] = max(v[i][j + 1], a[j]);
	int l = 1, r = n, mid;
	while (l < r)
	{
		mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	check(l);
	getans(n);
	cout << l << ' ' << c << endl;
	for (int i = 1; i <= c; i++)
		cout << (len[i] = v[ed[i]][st[i]]) << ' ';
	cout << endl;
	for (int i = 1; i <= l; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (st[j] <= ed[j])
			{
				cout << s[st[j]] << ' ';
				int space = len[j] - s[st[j]].length();
				for (int k = 0; k < space; k++)
					cout << ' ';
				st[j]++;
			}
			else
				for (int k = 0; k <= len[j]; k++)
					cout << ' ';
		}
		cout << endl;
	}
	return 0;
}


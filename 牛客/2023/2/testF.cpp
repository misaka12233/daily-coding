#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
int n; 
bool vis[maxn][maxn][maxn];
bool check(int *s, int *d)
{
	for (int i = 0; i < 3; i++)
		if (s[i] + d[i] < 1 || s[i] + d[i] > n)
			return false;
	return true;
}
bool dfs(int *s)
{
	bool res = false;
	vis[s[0]][s[1]][s[2]] = true;
	int d[3] = {0, 0, 0};
	for (int i = 0; i < 3; i++)
	{
		d[i] = 1;
		if (!vis[s[0] + d[0]][s[1] + d[1]][s[2] + d[2]] && check(s, d))
		{
			for (int j = 0; j < 3; j++)
				s[j] += d[j];
			res |= !dfs(s);
			for (int j = 0; j < 3; j++)
				s[j] -= d[j];
		}
		d[i] = -1;
		if (!vis[s[0] + d[0]][s[1] + d[1]][s[2] + d[2]] && check(s, d)) 
		{
			for (int j = 0; j < 3; j++)
				s[j] += d[j];
			res |= !dfs(s);
			for (int j = 0; j < 3; j++)
				s[j] -= d[j];
		}
		d[i] = 0;
	}
	vis[s[0]][s[1]][s[2]] = false;
	return res;
}
bool sol()
{
	int r, g, b;
	scanf("%d%d%d%d", &n, &r, &g, &b);
	int s[3];
	s[0] = r, s[1] = g, s[2] = b;
	return dfs(s);
}
int main()
{
	scanf("%d", &T);
	while (T--) 
	{
		if (sol()) puts("Alice");
		else puts("Bob");
	}
	return 0;
}


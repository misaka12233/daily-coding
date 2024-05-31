#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int m, k;
int f[maxn][maxn], a[maxn];
int check(int len)
{
	for (int i = 1; i <= len; i++)
	{
		int cnt = 0;
		for (int j = 0; j < k && i + j <= len; j++)
			cnt += a[i + j];
		if (cnt > m)
			return -1;
	}
	int s = 0;
	for (int i = 1; i <= len; i++)
		s += a[i];
	return s;
}
void dfs(int len)
{
	if (len == 21)
		return;
	a[len] = 0;
	int cnt = check(len);
	if (cnt != -1)
	{
		f[len][cnt]++;
		dfs(len + 1);
	}
	a[len] = 1;
	cnt = check(len);
	if (cnt != -1)
	{
		f[len][cnt]++;
		dfs(len + 1);
	}
	return;
}
int main()
{
	scanf("%d%d", &k, &m);
	dfs(1);
	for (int i = 1; i <= 20; i++)
	{
		for (int j = 0; j <= i; j++)
			printf("%d ", f[i][j]);
		printf("\n"); 
	}
	return 0;
}


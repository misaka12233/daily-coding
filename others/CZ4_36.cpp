#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
int n = 14;
int p[maxn];
ll A[maxn][maxn] = {0};
ll ans = 1;
void add(int x, int y, int now)
{
	while (A[y][now] != 0)
	{
		ll k = A[x][now] / A[y][now];
		for (int i = now; i <= n; i++)
		{
			A[x][i] -= A[y][i] * k;
			swap(A[x][i], A[y][i]);
		}
		ans = -ans;
	}
}
int main()
{
	for (int i = 1; i <= 20; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		A[u][u] += 1;
		A[v][v] += 1;
		A[u][v] -= 1;
		A[v][u] -= 1;
	}
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			add(i, j, i);
	for (int i = 1; i <= n; i++)
		ans *= A[i][i];
	printf("%lld\n", ans);
}
/*
0 2
0 3
1 3
1 4
2 5
3 5
3 6
4 6
5 7
5 9
6 10
6 8
7 11
8 14
9 11
9 10
9 12
10 13
10 14
12 13
*/

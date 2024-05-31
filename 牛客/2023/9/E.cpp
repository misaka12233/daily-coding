#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n, m;
int k, ans[maxn][3];
void getans(int x, int y, int n, int m)
{
	k++;
	ans[k][0] = x;
	ans[k][1] = y;
	ans[k][2] = min(n, m);
	if (n == m)
		return;
	if (n > m)
		getans(x + m, y, n - m, m);
	else
		getans(x, y + n, n, m - n);
}
void sol()
{
	scanf("%d%d", &n, &m);
	k = 0;
	getans(0, 0, n, m);
	puts("YES");
	printf("%d\n", k);
	for (int i = 1; i <= k; i++)
		printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}


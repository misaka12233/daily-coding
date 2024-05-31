#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int n, k;
int ans[maxn][maxn];
int sol(int l, int r)
{
	if (l == r)
		return 0;
	int len = (r - l + k) / k;
	int mxc = 0;
	for (int st = l; st <= r; st += len)
		mxc = max(mxc, sol(st, min(st + len - 1, r)));
	for (int st = l; st <= r; st += len)
		for (int i = 0; i < len; i++)
			for (int j = st + len; j <= r; j++)
				ans[st + i][j] = mxc + 1;
	return mxc + 1;
}
int main()
{
	scanf("%d%d", &n, &k);
	printf("%d\n", sol(1, n));
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			printf("%d ", ans[i][j]);
	printf("\n");
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int a[maxn];
int n, k;
bool solve(int l, int r)
{
	if (k == 0 || r - l == 1) return false;
	int mid = l + r >> 1;
	k -= 2;
	bool judge = !solve(l, mid);
	judge = !solve(mid, r) && judge;
	if(judge)
	{
		int tmp = a[l];
		for (int i = l; i < mid; i++)
			a[i] = a[i + 1];
		a[mid] = tmp;
	}
	return true;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		a[i] = i;
	k--;
	solve(1, n + 1);
	if (k == 0)
	{
		for (int i = 1; i <= n; i++)
			printf("%d ", a[i]);
	}
	else puts("-1");
	return 0;
}


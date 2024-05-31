#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n, m;
int f[maxn];
int lst[maxn];
int a[maxn], b[maxn];
vector<int> ins[maxn];
int ed_val[maxn], ed_id[maxn], cnt; 
int getpos(int l, int r, int x)
{
	while (l < r)
	{
		int mid = l + r >> 1;
		if (lst[mid + 1] < x) l = mid + 1;
		else r = mid;
	}
	return l;
}
void sol()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i), lst[i] = inf;
	for (int i = 1; i <= m; i++)
		scanf("%d", b + i);
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		f[i] = getpos(0, n, a[i]) + 1;
		lst[f[i]] = min(lst[f[i]], a[i]);
		res = max(res, f[i]);
	}
	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (f[i] == res)
		{
			ed_val[++cnt] = a[i];
			ed_id[cnt] = i;
		}
	}
	ed_val[++cnt] = 0;
	ed_id[cnt] = n + 1;
	sort(b + 1, b + m + 1, greater<int>());
	int now = 1;
	for (int i = 1; i <= m; i++)
	{
		while (now <= cnt && b[i] < ed_val[now]) now++;
		ins[ed_id[now]].push_back(b[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (auto x : ins[i])
			printf("%d ", x);
		printf("%d ", a[i]);
		ins[i].clear();
	}
	for (auto x : ins[n + 1])
		printf("%d ", x);
	ins[n + 1].clear();
	printf("\n");
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}


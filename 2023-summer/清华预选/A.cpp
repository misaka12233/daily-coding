#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 10;
int n, ans;
int rk[maxn];
int a[maxn], nxt[maxn];
map<int, int> lst;
int init(int now, int end, int rank)
{
	rk[now] = rank;
	lst[a[now]] = rank;
	if (nxt[now] != end)
		return init(nxt[now], end, rank + 1);
	else
		return rank + 1;
}
void getans(int now, int end, int siz)
{
	int res = rk[now] - lst[a[now]];
	if (res <= 0) res = siz + res;
	//printf("%d: %d\n", now, res); 
	ans = max(ans, res);
	lst[a[now]] = rk[now];
	if (nxt[now] != end)
		getans(nxt[now], end, siz);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
		scanf("%d", nxt + i);
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (rk[i] == 0)
		{
			lst.clear();
			int siz = init(i, i, 0);
			getans(i, i, siz);
		}
	}
	printf("%d\n", ans);
	return 0;
}


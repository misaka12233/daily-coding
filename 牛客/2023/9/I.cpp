#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000000 + 10;
const int mod = 1e9 + 7;
int n;
ll p[maxn];
int vis[maxn];
struct node{
	int x;
	int id;
};
node L[maxn], R[maxn];
bool cmp(node a, node b)
{
	if (a.x == b.x) return a.id < b.id;
	return a.x < b.x;
}
int main()
{
	scanf("%d", &n);
	int m = 2 * n;
	for (int i = 1; i <= n; i++)
	{
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		L[i].x = l1, L[i].id = i;
		L[i + n].x = l2, L[i + n].id = i;
		R[i].x = r1, R[i].id = i;
		R[i + n].x = r2, R[i + n].id = i;
	}
	sort(L + 1, L + m + 1, cmp);
	sort(R + 1, R + m + 1, cmp);
	p[0] = 1;
	for (int i = 1; i <= n; i++)
		p[i] = p[i - 1] * 2 % mod;
	int cnt1 = 0, cnt2 = 0, ans = 0;
	for (int i = 1, j = 1; i <= m; i++)
	{
		while (j <= m && R[j].x < L[i].x)
		{
			if (vis[R[j].id] == 2) 
			{
				cnt2--;
				cnt1++;
			}
			else if (vis[R[j].id] == 1)
				cnt1--;
			vis[R[j].id]--;
			j++;
		}
		if (vis[L[i].id] == 1)
		{
			cnt1--;
			cnt2++;
		}
		else if (vis[L[i].id] == 0)
			cnt1++;
		vis[L[i].id]++;
		if (cnt1 + cnt2 == n)
			ans = (ans + p[cnt2 - (vis[L[i].id] == 2)]) % mod;
	}
	printf("%d\n", ans);
	return 0;
}


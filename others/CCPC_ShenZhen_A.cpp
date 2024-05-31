#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
typedef pair<int, int> pii;
int n;
struct node{
	int val;
	int id;
};
node a[maxn];
vector<pii> ans;
bool cmp(node x, node y)
{
	if (x.val == y.val) return x.id < y.id;
	return x.val < y.val;
}
void sol(int l, int r, int base)
{
	if (l > r || a[r].val == base)
		return;
	int mid = a[l + r >> 1].val;
	int st = -1, ed = -1;
	for (int i = l; i <= r; i++)
	{
		if (a[i].val == mid)
		{
			if (st == -1)
				st = i;
			ed = i;
		}
	}
	if (base == mid)
	{
		sol(ed + 1, r, base);
		return;
	}
	for (int i = st; i <= r; i++)
		ans.push_back(pii(2, a[i].id));
	for (int i = base + 1; i < mid; i++)
		ans.push_back(pii(1, i));
	sol(ed + 1, r, mid);
	sol(l, st - 1, base);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].val);
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, cmp);
	sol(1, n, 0);
	printf("%d\n", ans.size());
	for (auto r : ans)
		printf("%d %d\n", r.first, r.second);
	return 0;
}


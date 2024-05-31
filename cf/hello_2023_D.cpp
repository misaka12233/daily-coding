#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
typedef pair<int, int> pii;
int n, m;
int a[maxn];
pii b[maxn];
int tr[maxn];
map<int, int> cnt;
int lowbit(int x)
{
	return x & -x;
}
void update(int x, int val)
{
	for (int i = x; i <= n; i += lowbit(i))
		tr[i] += val;
}
int query(int x)
{
	int res = 0;
	for (int i = x; i; i -= lowbit(i))
		res += tr[i];
	return res;
}
bool sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	bool ans = true;
	for (int i = 1; i <= n; i++)
	{
		tr[i] = 0;
		scanf("%d", &b[i].first);
		b[i].second = i;
	 	if (b[i].first > a[i])
			ans = false;
	}
	cnt.clear();
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	if (!ans) return false;
	sort(b + 1, b + n + 1);
	bool no_use;
	for (int i = 1; i <= n; i++)
	{
		if (b[i].first != b[i - 1].first)
			no_use = true;
		if (b[i].first != a[b[i].second])
		{
			if (no_use)
			{
				cnt[b[i].first]--;
				no_use = false;
			}
			else
			{
				if (b[i].first == b[i - 1].first)
				{
					int sum = query(b[i].second - 1) - query(b[i - 1].second);
					if (sum < b[i].second - 1 - b[i - 1].second)
						cnt[b[i].first]--;
				}
				else
					cnt[b[i].first]--;
			}
			if (cnt[b[i].first] < 0)
				return false;
		}
		update(b[i].second, 1);
	}
	return true;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) 
	{
		if (sol()) puts("YES");
		else puts("NO");
	}
	return 0;
}


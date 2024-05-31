#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n, m;
struct Color{
	Color(int a, int cnt) : a(a), cnt(cnt) {}
	int a, cnt;
	bool operator < (Color y) const
	{
		if (cnt == y.cnt) return a < y.a;
		return cnt > y.cnt;
	}
};
int cnt[maxn];
set<Color> s;
vector<Color> tmp;
struct node{
	int s, d, id;
}lim[maxn];
vector<int> col[maxn];
bool cmp(node x, node y)
{
	if (x.d == y.d) return x.s > y.s;
	return x.d > y.d;
}
bool sol()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	s.clear();
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] != 0)
			s.insert(Color(i, cnt[i]));
		cnt[i] = 0;
	}
	for (int i = 1; i <= m; i++)
		scanf("%d", &lim[i].s), lim[i].id = i, col[i].clear();
	for (int i = 1; i <= m; i++)
		scanf("%d", &lim[i].d);
	sort(lim + 1, lim + m + 1, cmp);
	for (int i = 1; i <= m; i++)
	{
		for (int k = 0; k < lim[i].s; k += lim[i].d)
		{
			int num = min(lim[i].d, lim[i].s - k);
			tmp.clear();
			for (auto x : s)
			{
				tmp.push_back(x);
				num--;
				if (num == 0)
					break;
			}
			if (num > 0) return false;
			for (auto x : tmp)
			{
				col[lim[i].id].push_back(x.a);
				s.erase(x);
				x.cnt--;
				if (x.cnt != 0)
					s.insert(x);
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (auto x : col[i])
			printf("%d ", x);
		printf("\n");
	}
	return true;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		if (!sol())
			puts("-1");
	}
	return 0;
}


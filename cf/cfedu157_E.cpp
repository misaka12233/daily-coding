#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 10;
struct node{
	int a, d;
	int id;
	bool operator < (const node &y) const
	{
		if (d == y.d && a == y.a) return id < y.id;
		if (d == y.d) return a < y.a;
		return d < y.d;
	}
};
int n[2];
int typ[2][maxn];
node val[2][maxn];
int mx_w[2], mx_d_rk[2];
set<node> win[2], draw[2];
bool cmp(node x, node y)
{
	return x.a < y.a;
}
void sol()
{
	for (int t = 0; t < 2; t++)
	{
		scanf("%d", &n[t]);
		for (int i = 1; i <= n[t]; i++)
		{
			typ[t][i] = 1;
			val[t][i].id = i;
		}
		win[t].clear(), draw[t].clear();
		mx_w[t] = 0;
		for (int i = 1; i <= n[t]; i++)
			scanf("%d", &val[t][i].a);
		for (int i = 1; i <= n[t]; i++)
			scanf("%d", &val[t][i].d);
		sort(val[t] + 1, val[t] + n[t] + 1, cmp);
		mx_d_rk[t] = n[t];
		for (int i = 1; i <= n[t]; i++)
			draw[t].insert(val[t][i]);
	}
	bool changed = true;
	while (changed)
	{
		changed = false;
		for (int t = 0; t < 2; t++)
		{
			if (draw[t].empty()) continue;
			int mxa = max(val[t ^ 1][mx_d_rk[t ^ 1]].a, mx_w[t ^ 1]);
			node x = *draw[t].rbegin();
			while (x.d >= mxa)
			{
				changed = true;
				typ[t][x.id] = 0;
				draw[t].erase(x);
				while (mx_d_rk[t] > 0 && typ[t][val[t][mx_d_rk[t]].id] != 1) mx_d_rk[t]--;
				win[t].insert(x);
				mx_w[t] = max(mx_w[t], x.a);
				if (draw[t].empty()) break;
				x = *draw[t].rbegin();
			}
			
			if (draw[t].empty()) continue;
			mxa = mx_w[t ^ 1];
			x = *draw[t].begin();
			while (x.d < mxa)
			{
				changed = true;
				typ[t][x.id] = 2;
				draw[t].erase(x);
				while (mx_d_rk[t] > 0 && typ[t][val[t][mx_d_rk[t]].id] != 1) mx_d_rk[t]--;
				if (draw[t].empty()) break;
				x = *draw[t].begin();
			}
		}
	}
	int ans[3] = {0, 0, 0};
	for (int i = 1; i <= n[0]; i++)
		ans[typ[0][i]]++;
	for (int i = 0; i < 3; i++)
		printf("%d ", ans[i]);
	printf("\n");
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}


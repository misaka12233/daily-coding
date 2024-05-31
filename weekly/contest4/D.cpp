#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200 + 10;
typedef long long ll;
int v;
map<ll, int> mp;
int t1[maxn], t2[maxn], id[maxn], indeg[maxn];
vector<int> e[maxn];
int getT(ll x)
{
	if (mp.find(x) != mp.end())
		return mp[x];
	if (x == 1)
	{
		mp[x] = v;
		t1[v] = t2[v] = -1;
		return v++;
	}
	int l = getT(max(x / 2, x - x / 2)), r = getT(min(x / 2, x - x / 2));
	mp[x] = v;
	t1[v] = l;
	e[l].push_back(v);
	indeg[v]++;
	t2[v] = r;
	e[r].push_back(v);
	indeg[v]++;
	return v++;
}
queue<int> q;
void sol()
{
	ll n;
	scanf("%lld", &n);
	v = 0;
	mp.clear();
	memset(t1, 0, sizeof(t1));
	memset(t2, 0, sizeof(t2));
	memset(id, 0, sizeof(id));
	memset(indeg, 0, sizeof(indeg));
	for (int i = 0; i < 125; i++)
		e[i].clear();
	getT(n);
	printf("%d\n", v);
	q.push(0);
	int cnt = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		id[x] = cnt;
		cnt++;
		printf("%d %d\n", (t1[x] == -1)? -1 : id[t1[x]], (t2[x] == -1)? -1 : id[t2[x]]);
		for (auto y : e[x])
		{
			indeg[y]--;
			if (indeg[y] == 0)
				q.push(y);
		}
	}
	printf("%d\n", v - 1);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol(); 
	return 0;
}


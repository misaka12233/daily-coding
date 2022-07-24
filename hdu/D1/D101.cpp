#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1000005;
const ll mod = 998244353;

vector<int> edge[maxn], cnt[maxn];
stack<int> sta;
int now[maxn];

int nxt[maxn];
char s[maxn];
int n, k, T;

int main() 
{
    scanf("%d", &T); 
	while (T--) 
	{
		scanf("%s", s + 1);
		scanf("%d", &k);
		n = strlen(s + 1);
		for (int i = 0; i <= n; i++) 
		{
			now[i] = 0;
			edge[i].clear();
		}
		for (int i = 0; i < k; i++)
			cnt[i].clear();
		nxt[1] = 0;
		edge[0].push_back(1);
		for (int i = 2, j = 0; i <= n; i++)
		{
			while (j != 0 && s[i] != s[j + 1]) j = nxt[j];
			if (s[i] == s[j + 1]) j++;
			nxt[i] = j;
			edge[j].push_back(i);
		}
		ll ans = 1;
		sta.push(0);
		while (!sta.empty())
		{
			int u = sta.top();
			if (now[u] == edge[u].size())
			{
				sta.pop();
				cnt[u * 2 % k].pop_back();
			}
			else
			{
				int v = edge[u][now[u]];
				now[u]++;
				sta.push(v);
				cnt[v * 2 % k].push_back(v * 2);
				int l = 0, r = cnt[v % k].size() - 1, mid;
				while (l < r)
				{
					mid = l + r >> 1;
					if (cnt[v % k][mid] <= v) l = mid + 1;
					else r = mid;
				}
				if (!cnt[v % k].empty() && cnt[v % k][l] > v)
					ans = ans * (cnt[v % k].size() - l + 1) % mod;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

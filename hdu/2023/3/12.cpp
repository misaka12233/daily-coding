#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
const int maxn = 50000 + 10;
int T;
int n, q;
pii a[maxn];
map< pii, vector<int> > mp;

template <typename type>
void read(type &a) 
{
    int t, f = 0;
    while (!isdigit(t = getchar())) 
        f |= t == '-';
    a = t - '0';
    while ( isdigit(t = getchar())) 
    {
        a *= 10;
        a += t - '0';
    }
    a = f ? -a : a;
}

void gcd(pii x)
{
	int tmp;
	if (x.first == 0 || x.second == 0) return;
	if (x.first > x.second)
	{
		tmp = x.first / x.second;
		x.first %= x.second;
		mp[x].push_back(tmp - 1);
	}
	else
	{
		tmp = x.second / x.first;
		x.second %= x.first;
		mp[x].push_back(tmp - 1);
	}
	gcd(x);
}
int getans(pii x, int k)
{
	return mp[x].end() - lower_bound(mp[x].begin(), mp[x].end(), k);
}
void sol()
{
	read(n), read(q);
	mp.clear();
	for (int i = 1; i <= n; i++)
	{
		read(a[i].first);
		read(a[i].second);
		mp[a[i]].push_back(0);
		gcd(a[i]);
	}
	for (auto &x : mp)
		sort(x.second.begin(), x.second.end());
	for (int i = 1; i <= q; i++)
	{
		int A, B, ans = 0;
		read(A), read(B);
		ans += getans(pii(A % B, B), A / B);
		ans += getans(pii(A, B % A), B / A);
		printf("%lld\n", ans);
	}
}
signed main()
{
	read(T);
	while (T--) sol();
	return 0;
}

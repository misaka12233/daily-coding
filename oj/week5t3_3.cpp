#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int maxn = 1000000 + 10;
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
template <typename type>
void write(type a) 
{
    char out[42];
    int index = 42;
    out[--index] = 0;
    out[--index] = '\n';
    if (a < 0) 
    {
        putchar('-');
        a = -a;
    }
    if (a) 
    {
        do 
        {
            out[--index] = a % 10 + '0';
        } 
        while(a /= 10);
    } 
    else
        out[--index] = '0';
    do 
    {
        putchar(out[index]);
    } 
    while(out[++index]);
}
int n, m, k, r, s;
struct node{
	int u, v;
	ll w;
	node () {}
	node (int u, int v, ll w) : u(u), v(v), w(w) {}
};
vector<node> e[maxn];
int fa[maxn];
int id[maxn], len0, len;
node edge[maxn];
ll val[maxn];
int op[maxn];
int cnt[maxn], sum_cnt; 
vector<pli> res;
bool vis[maxn];
ll ans;
int getfa(int x)
{
	if (x == fa[x]) return x;
	int f = getfa(fa[x]);
	val[x] = val[fa[x]] + val[x] * (-1) * op[fa[x]];
	op[x] = (-1) * op[fa[x]] * op[x] ;
	return fa[x] = f;
}
int find(int x)
{
	int l = 1, r = len + 1;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (id[mid] < x) l = mid + 1;
		else r = mid;
	}
	return l;
}
void getres(int u, ll w, int t)
{
	res.push_back({w, cnt[u]});
	sum_cnt += cnt[u];
	vis[u] = true;
	for (auto now : e[u])
	{
		int v = now.v;
		if (vis[v]) continue;
		getres(v, w + now.w * t, t * (-1));
	}
}
ll getrk(int rk)
{
	int pre = 0;
	for (auto x : res)
	{
		pre += x.second;
		if (pre >= rk) 
			return x.first;
	}
}
ll getans(ll mid)
{
	ll sum = 0;
	for (auto x : res)
		sum += ((x.first < mid) ? (mid - x.first) : (x.first - mid)) * x.second;
	return sum;
}
ll sol()
{
	for (int i = 1; i <= len; i++) e[i].clear();
	len0 = len = 0;
	ans = 0;
	read(n), read(m), read(k);
	for (int i = 1; i <= k; i++)
	{
		read(edge[i].u), read(edge[i].v), read(edge[i].w);
		id[++len0] = edge[i].u;
		id[++len0] = edge[i].v + n;
	}
	sort(id + 1, id + len0 + 1);
	for (int i = 1; i <= len0; i++)
	{
		while (id[i] == id[i + 1] && i + 1 <= len0) i++;
		id[++len] = id[i];
	}
	for (int i = 1; i <= len; i++) 
	{
		fa[i] = i;
		op[i] = -1;
		val[i] = 0;
		cnt[i] = 1;
		vis[i] = false;
	}
	id[len + 1] = n + m + 1;
	read(r), read(s);
	for (int i = 1; i <= r; i++)
	{
		int u, w;
		read(u), read(w);
		cnt[find(u)] = w;
	}
	for (int i = 1; i <= s; i++)
	{
		int v, w;
		read(v), read(w);
		cnt[find(v + n)] = w;
	}
	for (int i = 1; i <= k; i++)
	{
		int u = find(edge[i].u), v = find(edge[i].v + n);
		int fu = getfa(u), fv = getfa(v);
		if (fu == fv)
		{
			if (val[u] * op[u] + val[v] * op[v] != edge[i].w)
				return -1;
		}
		else
		{
			op[fu] = op[u] * op[v];
			val[fu] = val[u] * op[u] * op[v] + val[v] - edge[i].w * op[v];
			fa[fu] = fv;
			e[u].push_back(node(u, v, edge[i].w));
			e[v].push_back(node(v, u, edge[i].w));
		}
	}
	for (int i = 1; i <= len; i++)
	{
		if (!vis[i])
		{
			res.clear();
			sum_cnt = 0;
			getres(i, 0, 1);
			sort(res.begin(), res.end());
			ll mid = getrk((sum_cnt + 1) / 2);
			ans += getans(mid);
		}
	}
	return ans;
}
int main()
{
	int T;
	read(T);
	while (T--) write(sol());
	return 0;
}


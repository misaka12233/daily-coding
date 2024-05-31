#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int maxn = 500000 + 10;
struct node{
	ll val;
	int pre;
	int nxt;
	bool del;
}t[maxn];
int n, k;
priority_queue<pli> s;
ll ans;
void del(int x)
{
	t[x].del = true;
	t[t[x].pre].nxt = t[x].nxt;
	t[t[x].nxt].pre = t[x].pre;
}
int main()
{
	int op;
	scanf("%d", &op);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &t[i].val);
		t[i].pre = i % n + 1;
		t[i].nxt = (i - 2 + n) % n + 1;
		t[i].del = false;
		s.push({t[i].val, i});
	}
	while (!s.empty())
	{
		int x = s.top().second;
		s.pop();
		if (t[x].val <= 0 || k <= 0) break;
		if (t[x].del) continue;
		ans += t[x].val;
		t[x].val = t[t[x].pre].val + t[t[x].nxt].val - t[x].val;
		s.push({t[x].val, x});
		del(t[x].pre);
		del(t[x].nxt);
		k--;
	}
	printf("%lld\n", ans);
	return 0;
}


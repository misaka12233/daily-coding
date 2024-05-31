#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
typedef long long ll;
int n;
ll c;
struct node{
	ll val;
	int id;
}a[maxn];
ll calc(node x)
{
	return c * x.id - x.val;
}
bool cmp(node x, node y)
{
	return calc(x) < calc(y);
}
bool sol()
{
	scanf("%d%lld", &n, &c);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i].val), a[i].id = i;
	sort(a + 2, a + n + 1, cmp);
	for (int i = 2; i <= n; i++)
	{
		if (a[1].val < calc(a[i])) return false;
		a[1].val += a[i].val;
	}
	return true;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		if (sol()) puts("Yes");
		else puts("No");
	}
	return 0;
}


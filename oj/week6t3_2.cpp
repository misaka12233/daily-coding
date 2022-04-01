#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const int maxn = 1.8e7 + 10;
lld A, B, C, MOD;
lld L;
int n, m, tot;
lld get_random() 
{
	return A = C + (A * B) % MOD;
}
lld a[maxn];
int ans;
void solve(int l, int r)
{
	if (r - l == 0)
	{
		if (a[l] <= L) L -= a[l], ans++;
		return;
	}
	lld tmp = l + r >> 1;
	swap(a[l], a[tmp]);
	tmp = a[l];
	int i = l, j = r;
	lld sum = 0;
	while (i < j)
	{
		while (i < j && a[j] >= tmp) j--;
		swap(a[i], a[j]);
		while (i < j && a[i] < tmp) sum += a[i], i++;
		swap(a[i], a[j]);
	}
	a[i] = tmp;
	sum += a[i];
	if (sum > L)
	{
	    if (l <= i - 1)
			solve(l, i - 1);
	}
	else
	{
		L -= sum, ans += i - l + 1;
		int t;
		for (t = i + 1; a[t] == tmp && t <= r; t++)
		{
			if (a[t] <= L) L -= a[t], ans++;
			else break;
		}
		if (tmp <= L && t <= r)
		solve(t, r);
	}
}
int main() 
{
	srand(time(0));
	cin >> n >> A >> B >> C >> MOD >> L;
	for (int i = 1; i <= n; i++) 
	{
		lld x;
		x = get_random();
		if (x <= 0) L -= x, ans++;
		else a[++tot] = x;
	}
	if (L >= 0)
	{
		if (L > 0 && tot >= 1)
			solve(1, tot);
		printf("%d\n", ans);
	}
	else
		puts("0");
	return 0;
}

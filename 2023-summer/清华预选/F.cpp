#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
char a[maxn];
int nxt[maxn], n;
char s1[maxn], s2[maxn];
int kmp(char *s)
{
	int m = strlen(s + 1);
	for (int i = 0; i <= m; i++) nxt[i] = 0;
	for(int i = 2, j = 0; i <= m; i++)
	{
		while (s[j + 1] != s[i] && j != 0) j = nxt[j];
		if (s[j + 1] == s[i]) j++;
		nxt[i] = j;
	}
	int mid = 2 * nxt[m] - m;
	if (mid >= 0 && mid % (m - nxt[m]) == 0)
		return m / (m - nxt[m]);
	else
		return 1;
}
bool cmp() 
{
	const int b = 31;
	const int m = 1e9 + 9;
	int tot = n / 2;
	vector<ll> b_pow(tot);
	b_pow[0] = 1;
	for (int i = 1; i < tot; i++) 
		b_pow[i] = (b_pow[i - 1] * b) % m;
	
	vector<ll> h1(tot + 1, 0);
	for (int i = 0; i < tot; i++)
		h1[i + 1] = (h1[i] * b + s1[i + 1] - 'a' + 1) % m;
	
	vector<ll> h2(tot + 1, 0);
	for (int i = 0; i < tot; i++)
		h2[i + 1] = (h2[i] * b + s2[i + 1] - 'a' + 1) % m;
		
	if (h1[tot] == h2[tot]) return true;
	
	for(int i = 1; i < tot; i++)
	{
		ll tmp1 = ((h2[tot] - h2[i] * b_pow[tot - i]) % m + m) % m;
		ll tmp2 = ((h1[tot] - h1[tot - i] * b_pow[i]) % m + m) % m;
		if (h1[tot - i] == tmp1 && tmp2 == h2[i])
			return true;
	}
		
	return false;
}

int main()
{
	scanf("%d", &n);
	scanf("%s", a + 1);
	for (int i = 1; i <= n; i++)
	{
		if (i & 1) s1[(i + 1) / 2] = a[i];
		else s2[i / 2] = a[i];
	}
	ll x = kmp(s1), y = kmp(s2), z = kmp(a);
	ll ans = 1ll * n * n;
	ans = ans - x * y * n / z;
	if (cmp()) ans = ans - x * y * n / z * 3;
	printf("%lld\n", ans);
	return 0;
}


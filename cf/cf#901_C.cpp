#include<bits/stdc++.h>
using namespace std;

int n, m;
int gcd(int x, int y)
{
	if (y == 0) return x;
	return gcd(y, x % y);
}
bool check(int x)
{
	while (x % 2 == 0) x >>= 1;
	return x == 1;
}
long long sol()
{
	scanf("%d%d", &n, &m);
	int p = n / gcd(n, m), q = m / gcd(n, m);
	p = p % q;
	if (!check(q)) return -1;
	long long ans = 0;
	for (int k = 29; k >= 0; k--)
	{
		int x = 1 << k;
		if (p >= x)
		{
			long long t = q / x;
			ans += (t - 1) * m / t;
			p -= x;
		}
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) printf("%lld\n", sol()); 
	return 0;
}


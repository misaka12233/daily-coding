#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 10;
int n;
long long a[maxn], k;
bool check(long long t)
{
	long long sum = 0;
	for (int i = 1; i <= n; i++)
		sum += min(t, a[i]);
	if (sum >= t * k) return true;
	else return false;
}
int main()
{
	scanf("%d%lld", &n, &k);
	long long sum = 0;
	for (int i = 1; i <= n; i++)
		scanf("%lld", a + i), sum += a[i];
	long long l = 0, r = sum / k, mid;
	while (l < r)
	{
		mid = l + r >> 1;
		if (check(mid + 1)) l = mid + 1;
		else r = mid;
	}
	printf("%lld\n", l);
	return 0;
}


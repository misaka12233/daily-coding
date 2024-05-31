#include<bits/stdc++.h>
using namespace std;
int k, c, n;
int gcd(int x, int y)
{
	if (y == 0) return x;
	return gcd(y, x % y);
}
bool check(int x)
{
	return ((x != c) && (c - x) % k == 0) && (gcd((c - x) / k, x) >= n);
}
void sol()
{
	scanf("%d%d%d", &k, &c, &n);
	int ans = 0, sqrc = sqrt(c); 
	for (int i = 1; i <= sqrc; i++)
	{
		if (c % i == 0)
		{
			int j = c / i;
			if (check(i)) ans++;
			if (j != i && check(j)) ans++;
		}
	}
	printf("%d\n", ans);
}
int main()
{
	int q;
	scanf("%d", &q);
	while (q--) sol();
	return 0;
}


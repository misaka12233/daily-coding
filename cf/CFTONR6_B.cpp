#include<bits/stdc++.h>
using namespace std;
void sol()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int s0 = 0; 
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		s0 ^= x;
	}
	int s1 = s0; 
	for (int i = 1; i <= m; i++)
	{
		int x;
		scanf("%d", &x);
		if (n & 1) s1 |= x;
		else s1 &= ~x;
	}
	if (n & 1) printf("%d %d\n", s0, s1);
	else printf("%d %d\n", s1, s0);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) sol();
	return 0;
}


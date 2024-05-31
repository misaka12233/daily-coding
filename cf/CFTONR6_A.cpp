#include<bits/stdc++.h>
using namespace std;
void sol()
{
	int n, k, x;
	scanf("%d%d%d", &n, &k, &x);
	if (x < k - 1 || n < k) puts("-1");
	else if (x == k) printf("%d\n", k * (k - 1) / 2 + (n - k) * (k - 1));
	else printf("%d\n", k * (k - 1) / 2 + (n - k) * x);
	return; 
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) sol();
	return 0;
}


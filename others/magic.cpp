#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n = 4;
int a[maxn];
int ans[] = {0, 1, 0, 1, 2, 1, 0, 1, 0, 2, 3, 2, };
int m = 9;
int main()
{
	for (int i = 0; i < n; i++)
		a[i] = 1 << i;
	a[n-1] ^= a[0];
	for (int i = n - 2; i >= 0; i--)
		a[i] ^= a[i + 1];
	for (int i = 1; i <= n - 2; i++)
		a[i] ^= a[i + 1];
	for (int i = n - 3; i >= 0; i--)
		a[i] ^= a[i + 1];
	for (int i = 1; i <= n - 3; i++)
		a[i] ^= a[i + 1];
	a[n-1] ^= a[0];
	for (int i = 0; i < n; i++)
		printf("%x\n", a[i]);
	return 0;
}


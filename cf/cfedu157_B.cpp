#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200 + 10;
int a[maxn];
void sol()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++)
		scanf("%d", a + i);
	sort(a + 1, a + 2 * n + 1);
	printf("%d\n", a[n] - a[1] + a[2 * n] - a[n + 1]);
	for (int i = 1; i <= n; i++)
		printf("%d %d\n", a[i], a[n + i]);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol(); 
	return 0;
}


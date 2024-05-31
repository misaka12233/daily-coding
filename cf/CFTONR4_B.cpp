#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
int n;
void putans(int n, int cnt)
{
	if (n == 1)
	{
		printf("%d\n", cnt);
		return;
	}
	int a1 = (n + 1) / 2, a2 = (n - 1) / 2;
	if (a1 & 1) 
	{
		putans(a1, cnt + 1);
		printf("1 ");
	}
	else
	{
		putans(a2, cnt + 1);
		printf("2 ");
	}
}
void sol()
{
	scanf("%d", &n);
	if (n & 1) putans(n, 0), putchar('\n');
	else puts("-1");
}
int main()
{
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}


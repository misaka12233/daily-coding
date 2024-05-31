#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
char a[maxn];
void sol()
{
	int n;
	scanf("%d", &n);
	scanf("%s", a);
	int now = a[0] - '0';
	for (int i = 1; i < n; i++)
	{
		if (now & (a[i] - '0'))
			now -= (a[i] - '0'), putchar('-');
		else
			now += (a[i] - '0'), putchar('+');
	}
	putchar('\n');
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
char s[maxn];
void sol()
{
	int n;
	scanf("%d", &n);
	scanf("%s", s + 1);
	int x = n + 2, y = -1;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == 'R')
		{
			x = i;
			break;
		}
	}
	for (int i = n; i >= 1; i--)
	{
		if (s[i] == 'L')
		{
			y = i;
			break;
		}
	}
	if (x == y + 1)
		printf("%d\n", y);
	else if (x < y)
		printf("0\n");
	else
		printf("-1\n");
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}


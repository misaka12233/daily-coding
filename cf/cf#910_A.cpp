#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n, k;
char s[maxn];
void sol()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (s[i] == 'B')
			cnt++;
	if (cnt == k)
	{
		puts("0");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (cnt < k && s[i] == 'A')
		{
			cnt++;
			if (cnt == k)
			{
				printf("1\n%d B\n", i);
				return;
			}
		}
		if (cnt > k && s[i] == 'B')
		{
			cnt--;
			if (cnt == k)
			{
				printf("1\n%d A\n", i);
				return;
			}
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}


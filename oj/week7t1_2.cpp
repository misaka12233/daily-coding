#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2100000 + 10;
char num[maxn];
int T;
int ans = 0;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", num);
		int len = strlen(num);
		bool pre_0 = true;
		ans = -1;
		for (int i = 0; i < len; i++)
		{
			if (num[i] != '0')
				pre_0 = false;
			if (!pre_0)
			{
				ans += num[i] - '0';
				ans++;
			}
		}
		if (!pre_0)
			printf("%d\n", ans);
		else
			puts("0");
	}
	return 0;
}


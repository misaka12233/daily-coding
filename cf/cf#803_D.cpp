#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 10000 + 10;
int T;
int n;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		int l = 1, r = n, mid;
		while (l < r)
		{
			mid = l + r >> 1;
			printf("? %d %d\n", l, mid);
			fflush(stdout);
			int x, cnt = 0;
			for (int i = l; i <= mid; i++)
			{
				scanf("%d", &x);
				if (l <= x && x <= mid) cnt++;
			}
			if (cnt & 1) r = mid;
			else l = mid + 1;
		}
		printf("! %d\n", l);
		fflush(stdout);
	}
	return 0;
}


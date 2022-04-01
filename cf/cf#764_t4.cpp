#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int T;
int n, k;
int cnt_save[30], cnt[30];
char s[maxn];
bool check(int x)
{
	if (x&1) x--;
	for (int i = 0; i < 26; i++)
		cnt[i] = cnt_save[i];
	for (int i = 1; i <= k; i++)
	{
		int tmp = x;
		for (int j = 0; j < 26; j++)
		{
			while (cnt[j] >= 2)
			{
				cnt[j] -= 2;
				tmp -= 2;
				if (!tmp)
					break;
			}
			if (!tmp)
				break;
		}
		if (tmp) return false;
	}
	return true;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		scanf("%s", s);
		memset(cnt_save, 0, sizeof(cnt_save));
		for (int i = 0; i < n; i++)
			cnt_save[s[i] - 'a']++;
		int l = 1, r = n / k, mid;
		while (l < r)
		{
			mid = l + r >> 1;
			if (check(mid + 1)) l = mid + 1;
			else r = mid;
		}
		printf("%d\n", l);
	}
	return 0;
}


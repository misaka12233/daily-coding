#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int T;
long long ans, n, cnt[30];
char s[maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		scanf("%s", s);
		long long l = strlen(s);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < l; i++)
			cnt[s[i] - 'A']++;
		if (s[l - 1] == 'D') s[l] = 'R';
		else s[l] = 'D';
		int t = 0, sum;
		ans = 0;
		while (s[t] == s[t + 1]) t++;
		t++;
		while (t < l)
		{
			sum = 0;
			while (s[t] == s[t + 1]) t++, sum++;
			t++, sum++;
			ans += sum * (n - cnt[s[t] - 'A']);
		}
		if (t == l) ans += n - cnt['D' - 'A'] + n - cnt['R' - 'A'];
		printf("%lld\n", ans);
	}
	return 0;
}


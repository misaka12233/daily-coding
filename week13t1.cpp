#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n, m;
char s[maxn][maxn]; 
int cnt[30], sum;
pii ans[maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for (int k = 0; k < m; k++)
	{
		scanf("%s", s[k]);
		int l = strlen(s[k]);
		memset(cnt, 0, sizeof(cnt));
		sum = 0;
		for (int i = l - 1; ~i; i--)
		{
			sum += cnt[s[k][i] - 'A'];
			for (int j = s[k][i] - 'A' + 1; j <= 26; j++)
				cnt[j]++;
		}
		ans[k] = pii(sum, k);
	}
	sort(ans, ans + m);
	for (int k = 0; k < m; k++)
		printf("%s\n", s[ans[k].second]);
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 100 + 10;
int T, n;
char s[maxn];
vector<pii> ans;
vector<int> S0, S1;
void sol()
{
	S0.clear();
	S1.clear();
	ans.clear();
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == '0') S0.push_back(i);
		else S1.push_back(i);
	}
	int cnt0 = S0.size();
	int l = S1[0], r = S0[cnt0 - 1];
	
	for (auto &x : S0) 
		if (x != r)
			ans.push_back(pii(x, r));
	for (auto &x : S1) 
		if (l != x)
			ans.push_back(pii(l, x));
			
	for (int i = 1; i < n; i++)
	{
		if (i == l || i == r) continue;
		for (int j = i + 1; j <= n; j++)
		{
			if (j == l || j == r) continue;
			ans.push_back(pii(i, j));
		}
	}
	
	for (int i = cnt0 + 1; i < r; i++)
		ans.push_back(pii(i, r));
	for (int i = n; i > r; i--)
		ans.push_back(pii(r, i));
	for (int i = cnt0; i > l; i--)
		ans.push_back(pii(l, i));
	for (int i = 1; i < l; i++)
		ans.push_back(pii(i, l));
	
	printf("%d\n", ans.size());
	for (auto &x : ans)
		printf("%d %d\n", x.first, x.second);
}
int main()
{
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}


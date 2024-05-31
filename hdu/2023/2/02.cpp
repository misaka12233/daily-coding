#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 10;
int T;
ll k;
int n;
char a[maxn];
void sol()
{
	scanf("%d%lld", &n, &k);
	scanf("%s", a + 1);
	int cnt = 0;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] == '0' && a[i - 1] != '0')
			cnt++;
	}
	if (k >= cnt)
	{
		if (n == 1)
		{
			if (k & 1) printf("0\n");
			else printf("1\n");
		}
		else
		{
			for (int i = 1; i < n; i++)
				printf("1");
			if (k == 1 && cnt == 0)
				printf("0\n");
			else
				printf("1\n");
		}
	}
	else
	{
		printf("1");
		for (int i = 2; i <= n; i++)
		{
			if (a[i] == '0' && a[i - 1] != '0')
				k--;
			if (a[i] == '1' || (a[i] == '0' && k >= 0))
				printf("1");
			else
				printf("0");
		}
		printf("\n");
	}
}
int main()
{
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n[1010], a[1010][maxn];
bool check(int t)
{
	for (int i = 1; i <= n[t]; i++)
		if (a[t][i] == a[t][n[t] - i + 1])
			return false;
	return true; 
}
int main()
{
	freopen("906A.in", "w", stdout);
	freopen("906A.out", "r", stdin);
	srand(time(0));
	int T = 100;
	printf("%d\n", T);
	for (int t = 1; t <= T; t++)
	{
		n[t] = (rand() % 10 + 1) * 2;
		printf("%d\n", n[t]);
		int cnt1 = n[t] / 2, cnt0 = n[t] / 2;
		for (int i = 1; i <= n[t]; i++)
		{
			int x = rand() & 1;
			if (x == 1 && cnt1 > 0)
			{
				cnt1--;
				printf("%d", a[t][i] = x);
			}
			else if (x == 0 && cnt0 > 0)
			{
				cnt0--;
				printf("%d", a[t][i] = x);
			}
			else if (cnt1 == 0) printf("%d", a[t][i] = 0);
			else if (cnt0 == 0) printf("%d", a[t][i] = 1);
		}
		printf("\n"); 
	}
	fclose(stdout);
	
	system("cf#906_A.exe");
	
	for (int t = 1; t <= T; t++)
	{
		int s;
		scanf("%d", &s);
		if (s == -1)
			return 233;
		for (int i = 1; i <= s; i++)
		{
			int x;
			scanf("%d", &x);
			for (int j = n[t]; j > x; j--)
				a[t][j + 2] = a[t][j];
			a[t][x + 1] = 0;
			a[t][x + 2] = 1;
			n[t] += 2;
		}
		if (!check(t)) return 233;
	}
	return 0;
}


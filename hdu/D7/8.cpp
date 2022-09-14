#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200 + 10;
bool nbchk(int i, int j, int k)
{
	if (i == 1)
	{
		if (j != k) return true;
		else return false;
	}
	int t = log(1.0 * i - 0.5) / log(2);
	int p = 1 << t;
	int a = i - p - 1, b = (j - 1) % (2 * p), c = (k - p - 1) % (2 * p);
	int now = (a ^ b ^ c) == 0 && j >= 2 * p + 1 && b < p && k >= 3 * p + 1 && c < p && (j - 1) / (2 * p) == (k - p - 1) / (2 * p);
	return now ^ 1;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int a[3];
		scanf("%d%d%d", &a[0], &a[1], &a[2]);
		sort(a, a + 3);
		if (nbchk(a[0], a[1], a[2])) puts("Win");
		else puts("Lose");
	}
	return 0;
}


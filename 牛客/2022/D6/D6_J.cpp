#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int A, B, C, x;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d", &A, &B, &C, &x);
		A = A - B;
		bool ans;
		if (A - B != 0)
		{
			if ((x - C) % (A - B) == 0 || (x - B + C) % (A - B) == 0 || (x - A + C) % (A - B) == 0)
				ans = true;
			else
				ans = false;
		}
		else 
		{
			if ((x - C) == 0 || (x - B + C) == 0 || (x - A + C) == 0)
				ans = true;
			else
				ans = false;
		}
		if (ans) puts("Yes");
		else puts("No");
	}
	return 0;
}


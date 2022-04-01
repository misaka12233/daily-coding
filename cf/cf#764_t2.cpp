#include<bits/stdc++.h>
using namespace std;
int T;
int a, b, c;
bool check()
{
	if ((2 * b - c) % a == 0 && (2 * b - c) / a > 0)
		return true;
	if ((2 * b - a) % c == 0 && (2 * b - a) / c > 0)
		return true;
	if ((a + c) % (2 * b) == 0 && (a + c) / (2 * b) > 0 )
		return true;
	return false;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &a, &b, &c);
		if (check())
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}


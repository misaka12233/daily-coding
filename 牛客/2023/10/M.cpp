#include<bits/stdc++.h>
using namespace std;
int A, B, C;
bool check()
{
	if (A + B == C) return true; 
	int pre, suf, t;
	pre = A, suf = 0, t = 1;
	while (1)
	{
		for (int i = 0; i <= 9; i++)
		{
			if (pre * t * 10 + i * t + suf + B == C)
			{
				A = pre * t * 10 + i * t + suf;
				return true;
			}
		}
		if (pre == 0) break;
		suf = suf + pre % 10 * t;
		pre = pre / 10;
		t = t * 10;
	}
	
	pre = B, suf = 0, t = 1;
	while (1)
	{
		for (int i = 0; i <= 9; i++)
		{
			if (A + pre * t * 10 + i * t + suf == C)
			{
				B = pre * t * 10 + i * t + suf;
				return true;
			}
		}
		if (pre == 0) break;
		suf = suf + pre % 10 * t;
		pre = pre / 10;
		t = t * 10;
	}
	
	pre = C, suf = 0, t = 1;
	while (1)
	{
		for (int i = 0; i <= 9; i++)
		{
			if (A + B == pre * t * 10 + i * t + suf)
			{
				C = pre * t * 10 + i * t + suf;
				return true;
			}
		}
		if (pre == 0) break;
		suf = suf + pre % 10 * t;
		pre = pre / 10;
		t = t * 10;
	}
	return false;
}
int main()
{
	
	char s[3];
	scanf("%d", &A);
	scanf("%s", s);
	scanf("%d", &B);
	scanf("%s", s);
	scanf("%d", &C);
	if (check())
	{
		puts("Yes");
		printf("%d + %d = %d\n", A, B, C);
	}
	else puts("No");
	return 0;
}


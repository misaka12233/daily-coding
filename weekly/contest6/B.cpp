#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n; 
int m, cnt[100];
int main()
{
	scanf("%lld", &n);
	int i = 2;
	while (1ll * i * i <= n)
	{
		if (n % i == 0)
		{
			m++;
			while (n % i == 0)
				n = n / i, cnt[m]++;
		}
		i++;
	}
	if (n != 1)
		cnt[++m] = 1;
	if (m == 1)
	{
		if (cnt[1] & 1)
			puts("Y");
		else
			puts("N");
	}
	else if (m == 2)
	{
		if (cnt[1] == 1 && cnt[2] == 1)
			puts("Y");
		else
			puts("N");
	}
	else
		puts("N");
	return 0;
}


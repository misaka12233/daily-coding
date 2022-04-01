#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int T;
char digit[maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", digit);
		int l = strlen(digit);
		bool los = true;
		for (int i = l - 1; i > 0; i--)
		{
			int tmp = digit[i] + digit[i - 1] - 2 * '0';
			if (tmp >= 10)
			{
				digit[i] = tmp % 10 + '0';
				digit[i - 1] = tmp / 10 + '0';
				los = false;
				break;
			}
		}
		if (!los) printf("%s\n", digit);
		else
		{
			bool change = false;
			for (int i = 1; i < l; i++)
			{
				if (digit[i] != '0')
				{
					digit[i - 1] += digit[i] - '0';
					for (int j = 0; j < i; j++)
					putchar(digit[j]);
					for (int j = i + 1; j < l; j++)
					putchar(digit[j]);
					puts("");
					change = true;
					break;
				}
			}
			if (!change)
			{
				digit[1] = digit[0];
				for (int i = 1; i < l; i++)
				putchar(digit[i]);
				puts("");
			}
		}
	}
	return 0;
}


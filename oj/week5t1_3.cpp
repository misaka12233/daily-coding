#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 100000 + 10;
int n, q;
ull result_0 = 0, result_1 = -1, m; 
//	记录每一位初始状态下为0或1最终的结果 
// 	补码表示下，-1即为全1 
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		char op[5];
		ull x;
		scanf("%s%llu", op, &x);
		if (op[0] == 'A')
		{
			result_0 &= x;
			result_1 &= x;
		}
		else if (op[0] == 'O')
		{
			result_0 |= x;
			result_1 |= x;
		}
		else if (op[0] == 'X')
		{
			result_0 ^= x;
			result_1 ^= x;
		}
	}
	while (q--)
	{
		scanf("%llu", &m);
		ull ans = 0;
		for (int i = 63; i >= 0; i--)
		{
			if ((result_0 >> i) & 1)
				ans |= (1ull << i);
			else if ( ((result_1 >> i) & 1) && m >= (1ull << i) )
			{
				ans |= (1ull << i);
				m -= (1ull << i);
			}
		}
		printf("%llu\n", ans);
		// 从高位向低位贪心当前位应当为0还是1
		// 若初始为0，最终为1，则当前位为0，为当前位提供贡献并不占用m的大小
		// 若不满足上述条件，且初始为1，最终为0，则尝试当前位能否取1，能取则取，因为高位有1永远比没有更优
		// 若不满足以上条件，则不能使得当前位为1，为了保证此后有更大选择空间，当前位取0，即不操作 
	}
	return 0;
}


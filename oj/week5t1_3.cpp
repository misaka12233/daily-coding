#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 100000 + 10;
int n, q;
ull result_0 = 0, result_1 = -1, m; 
//	��¼ÿһλ��ʼ״̬��Ϊ0��1���յĽ�� 
// 	�����ʾ�£�-1��Ϊȫ1 
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
		// �Ӹ�λ���λ̰�ĵ�ǰλӦ��Ϊ0����1
		// ����ʼΪ0������Ϊ1����ǰλΪ0��Ϊ��ǰλ�ṩ���ײ���ռ��m�Ĵ�С
		// �������������������ҳ�ʼΪ1������Ϊ0�����Ե�ǰλ�ܷ�ȡ1����ȡ��ȡ����Ϊ��λ��1��Զ��û�и���
		// ����������������������ʹ�õ�ǰλΪ1��Ϊ�˱�֤�˺��и���ѡ��ռ䣬��ǰλȡ0���������� 
	}
	return 0;
}


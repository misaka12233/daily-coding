#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n;
int q[maxn];
ll sum[maxn];
int dp[maxn];  // dp[i]���� 1~i �кϲ������ʣ���Ԫ�ظ��� 
int lst[maxn]; // lst[i]���� 1~i �ϲ������һ����Ϊ lst[i]~i �ϲ��õ� 
int head, tail;
ll getLimit(int x){ return sum[x] * 2 - sum[lst[x]]; }
void printMethod(int num)
{
	if (num == 0) return;
	ll now = 0;
	printMethod(lst[num]);
	printf("%lld ", sum[num] - sum[lst[num]]);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		sum[i] = sum[i - 1] + x;
	}
	head = tail = 1;
	q[head] = 0;
	for (int i = 1; i <= n; i++)
	{
		// dp[i] = max(dp[j]) + 1 (sum[i] - sum[j] >= sum[j] - sum[lst[j]])
		// lst[i] = sum[i] - sum[j]
		while (head < tail && sum[i] >= getLimit(q[head + 1])) head++;
		dp[i] = dp[q[head]] + 1;
		lst[i] = q[head];
		while (head <= tail && getLimit(i) <= getLimit(q[tail])) tail--;
		q[++tail] = i;
	}
	printf("%d\n", n - dp[n]);
	printMethod(n);
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 10;
typedef long long ll;
int n, q;
ll pre[maxn]; // pre[i]��ʾ��iΪ��β��������������������ǰ������ٸ����໥���������� 
ll sum[maxn]; // pre��ǰ׺�ͣ���ʾÿ���������ǰ��������Ÿ������ܺ� 
char s[maxn];
int sta[maxn], top;
int main()
{
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == ')') 
		{
			if (top != 0)
			{
				pre[i] = pre[sta[top] - 1] + 1;
				top--;
			}
		}
		else sta[++top] = i;
		sum[i] = sum[i - 1] + pre[i];
	}
	int x, l, r;
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d%d", &x, &l, &r);
		printf("%lld\n", sum[r] - sum[l - 1] - pre[l - 1] * (pre[r] - pre[l - 1]));
		// sum[r] - sum[l - 1]��ʾѯ�����������е���ǰ����Ļ������������Ÿ���֮��
		// ����ÿ����Ϊ��β�ĺϷ����������֮��
		// ��ʱ����һ�������г��� l �� r ��Χ����Ҫ��ȥ�ⲿ�ִ� 
		// ��֪ l �� r һ����һ���Ϸ�����
		// ��˳�����Χ������һ������  l �� r ���幹��һ�������������������� 
		// ��ô��������һ����l-1���������������������
		// δ��������һ������rΪ���Ҷˣ�lΪ�����
		// �����������Ÿ�����δ�����������Ÿ����ĳ˻���Ϊ����� 
	}
	return 0;
}


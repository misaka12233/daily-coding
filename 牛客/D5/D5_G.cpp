#include<bits/stdc++.h>
using namespace std;
const int maxn = 500000 + 10;
char a[maxn],s[maxn<<1];
int l[maxn<<1],n; 
int ans[3];
int main()
{
	scanf("%d", &n);
	scanf("%s",a);
	for(int i=1;i<=n;i++) 
	s[2*i]=a[i-1];
	n=n*2+1;
	for(int i=1;i<=n;i+=2) s[i]='#';
	l[1]=1;
	int k=1;
	for(int i=2;i<=n;i++)
	{
		int t=max(1,k+l[k]-i);
		while(i+t<=n&&s[i+t]==s[i-t]) t++;
		l[i]=t;
		if (l[i] > 1)
		{
			int ed = i + l[i] - 2;
			if (s[ed] == 'k') ans[0]++;
			if (s[ed] == 'f') ans[1]++;
			if (s[ed] == 'c') ans[2]++;
		}
	}
	printf("%d %d %d\n", ans[0], ans[1], ans[2]);
}


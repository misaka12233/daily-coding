#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int main()
{
	srand(time(0));
	int cnt[6]={0,0,0,0,0,0};
	int a[6],n;
	scanf("%d", &n);
	for(int i = 1 ;i <= n; i++)
	{
		a[0]=rand();
		a[1]=rand();
		a[2]=rand();
		a[3]=rand();
		int k=3;
		for(int j = 0;j<=3;j++)
			if(a[j]>a[k]) k=j;
		cnt[k]++;
	}
	printf("%d %d %d %d",cnt[0],cnt[1],cnt[2],cnt[3]);
}


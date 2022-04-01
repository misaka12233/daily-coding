#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 810
using namespace std;
int link[maxn][2],h[maxn][2];
int cnt[2][maxn];
int n;
priority_queue<int> q1,q2;
bool fre[maxn][2],ned[maxn][2];
int main()
{
	int x,k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[0][x]++;
		link[i][0]=link[i][1]=h[i][0]=h[i][1]=i;
	}
	k=0;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n;j++) 
		fre[j][0]=fre[j][1]=ned[j][0]=ned[j][1]=false;
		for(int j=1;j<=n-i;j++)
		{
			scanf("%d",&x);
			cnt[k^1][x]++;
		}
		if(i==1)
		{
		for(int j=1;j<=n;j++)
		{
			if(cnt[k][j]==cnt[k^1][j])
			{
				fre[j][0]=ned[j][1]=true;
				q1.push(j);
				q2.push(j);
			}
			if(cnt[k][j]>cnt[k^1][j])
			{
				ned[j][0]=ned[j][1]=true;
				q2.push(j);
				q2.push(j);
			}
			if(cnt[k][j]<cnt[k^1][j])
			{
				fre[j][0]=fre[j][1]=true;
				q1.push(j);
				q1.push(j);
			}
		}
		q1.push(0),q1.push(0);
		fre[0][0]=fre[0][1]=true;
		while(!q1.empty())
		{
			int a=q1.top(),b=q2.top();
			q1.pop(),q2.pop();
			int t1=0,t2=0;
			if(!fre[a][0]) t1=1;
			if(!ned[b][0]) t2=1;
			link[h[a][t1]][t1]=h[b][t2];
			link[h[b][t2]][t2]=h[a][t1];
			h[a][t1]=h[b][t2^1];
			h[b][t2]=h[a][t1^1];
			fre[a][t1]=ned[b][t2]=false;
		}
		}
	}
	int now=link[h[1][0]][1];
	while(now!=0)
	{
		printf("%d ",now);
		now=link[now][1];
	}
}


#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 100010
using namespace std;
int r[maxn][2],c[maxn][2],a[maxn];
int n,m,t,ans;
long long k;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%lld",&n,&m,&k);
		for(int i=1;i<=n;i++) r[i][0]=r[i][1]=0;
		for(int i=1;i<=m;i++) c[i][0]=c[i][1]=inf;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				int x;
				scanf("%d",&x);
				if(i==1&&j==1) ans=x;
				if(x>r[i][0]) r[i][0]=x,r[i][1]=j;
				if(x<c[j][0]) c[j][0]=x,c[j][1]=i;
			}
		}
		if(k==1||r[1][1]==1) printf("%d\n",r[1][0]);
		else
		{
			if(k&1) 
			{
				int mn=inf;
				for(int i=1;i<=n;i++) mn=min(mn,r[i][0]);
				printf("%d\n",mn);
			}
			else
			{
				int mn=0;
				for(int i=1;i<=m;i++) mn=max(mn,c[i][0]);
				printf("%d\n",mn);
			}
		}
	}
}


#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1000010
using namespace std;
int v[maxn],sum[maxn],p[maxn],m,pre[maxn];
int t,n,k;
int main()
{
	p[0]=v[1]=sum[1]=1;
	m=0;
	for(int i=2;i<maxn;i++)
	{
		sum[i]=sum[i-1];
		if(v[i]==0)
		{
			v[i]=i;
			sum[i]++;
			p[++m]=i;
		}
		else pre[i-sum[i]]=i;
		for(int j=1;j<=m;j++)
		{
			if(p[j]>v[i]||p[j]>(maxn-1)/i) break;
			v[i*p[j]]=p[j];
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		int o,ans=0;
		scanf("%d%d%d",&o,&n,&k);
		if(o==1)
		{
			while(v[k]!=k) ans+=sum[n],k-=sum[k],n-=sum[n];
			ans+=sum[k];
		}
		else
		{
			int cnt=0;
			while(k>sum[n]) k-=sum[n],n-=sum[n],cnt++;
			ans=p[k-1];
			while(cnt--) ans=pre[ans];
		}
		printf("%d\n",ans);
	}
}


#include<bits/stdc++.h>
#define inf 0x7ffffffffffffff
#define maxm 510
#define ll long long
using namespace std;
struct node{
	int x,y;
};
bool operator <(const node &a,const node &b)
{
	return a.x<b.x;
}
ll dis[maxm][maxm],a[maxm][maxm],b[maxm][maxm],c[maxm][maxm],w[maxm][maxm];
int n,m,xs,ys,xt,yt;
priority_queue< pair<ll,node> > q;
bool vis[maxm][maxm];
int main()
{
	scanf("%d%d%d%d%d%d",&n,&m,&xs,&ys,&xt,&yt);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]),dis[i][j]=inf;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&b[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			scanf("%d",&c[i][j]);
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&w[i][j]);
	dis[xs][ys]=0;
	node tmp;
	tmp.x=xs,tmp.y=ys;
	q.push(make_pair(-dis[xs][ys],tmp));
	while(!q.empty())
	{
		int x1=q.top().second.x,y1=q.top().second.y;
		q.pop();
		if(vis[x1][y1]) continue;
		vis[x1][y1]=true;
		ll k=dis[x1][y1]%(a[x1][y1]+b[x1][y1]),d;
		if(x1>1) 
		{
			d=0;
			if(a[x1][y1]<=k) d=a[x1][y1]+b[x1][y1]-k;
			if(d+w[x1-1][y1]+dis[x1][y1]<dis[x1-1][y1])
			{
				dis[x1-1][y1]=d+w[x1-1][y1]+dis[x1][y1];
				tmp.x=x1-1,tmp.y=y1;
				q.push(make_pair(-dis[x1-1][y1],tmp));
			}
		}
		if(x1<n) 
		{
			d=0;
			if(a[x1][y1]<=k) d=a[x1][y1]+b[x1][y1]-k;
			if(d+w[x1][y1]+dis[x1][y1]<dis[x1+1][y1])
			{
				dis[x1+1][y1]=d+w[x1][y1]+dis[x1][y1];
				tmp.x=x1+1,tmp.y=y1;
				q.push(make_pair(-dis[x1+1][y1],tmp));
			}
		}
		if(y1>1) 
		{
			d=0;
			if(a[x1][y1]>k) d=a[x1][y1]-k;
			if(d+c[x1][y1-1]+dis[x1][y1]<dis[x1][y1-1])
			{
				dis[x1][y1-1]=d+c[x1][y1-1]+dis[x1][y1];
				tmp.x=x1,tmp.y=y1-1;
				q.push(make_pair(-dis[x1][y1-1],tmp));
			}
		}
		if(y1<n) 
		{
			d=0;
			if(a[x1][y1]>k) d=a[x1][y1]-k;
			if(d+c[x1][y1]+dis[x1][y1]<dis[x1][y1+1])
			{
				dis[x1][y1+1]=d+c[x1][y1]+dis[x1][y1];
				tmp.x=x1,tmp.y=y1+1;
				q.push(make_pair(-dis[x1][y1+1],tmp));
			}
		}
	}
	printf("%lld\n",dis[xt][yt]);
}


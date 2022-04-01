#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 5010
#define ll long long
using namespace std;
int t,n;
ll a[maxn],b[maxn];
int ans[2][maxn];
struct node{
	ll x;
	int p;
};
bool cmp(node x,node y)
{
	return x.x<y.x;
}
node c[maxn];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]),c[i].x=a[i],c[i].p=i;
		for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
		sort(c+1,c+n+1,cmp);
		for(int i=n;i>=1;i--)
		{
			int k=n;
			ans[0][c[i].p]=n-i+1;
			for(int j=n;j>i;j--)
				if(c[j].x+b[k]<=c[i].x+b[1]) 
					ans[0][c[i].p]--,k--;
		}
		for(int i=1;i<=n;i++)
		{
			int k=1;
			ans[1][c[i].p]=0;
			for(int j=1;c[j].x<=c[i].x&&j<=n;j++)
			{
				if(c[j+1].x>c[i].x||j+1>n) ans[1][c[i].p]+=n-j+1;
				if(i==j) continue;
				if(c[j].x+b[k]>c[i].x+b[n]) 
					ans[1][c[i].p]++,k++;
			}
		}
		for(int i=1;i<=n;i++) printf("%d %d\n",ans[0][i],ans[1][i]);
	}
}


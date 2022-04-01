#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 100010
#define ull unsigned long long
using namespace std;
char s[maxn],c[30][maxn];
ull a[maxn],b[30];
ull k[maxn];
int t,n,m;
const ull p=13331;
int f1[maxn],f2[maxn];
bool vis[maxn];
int main()
{
	scanf("%d",&t);
	k[0]=1;
	for(int i=1;i<maxn;i++)
	k[i]=k[i-1]*p;
	while(t--)
	{
		scanf("%d%d",&n,&m);
		char tmp[5];
		for(int i=1;i<=m;i++)
		{
			scanf("%s%s",tmp,c[i]);
			int l=strlen(c[i]);
			b[i]=c[i][0]-'0'+1;
			for(int j=1;j<l;j++)
			b[i]=b[i]*p+c[i][j]-'0'+1;
		}
		scanf("%s",s);
		a[1]=s[0]-'0'+1;
		for(int i=1;i<n;i++)
		a[i+1]=a[i]*p+s[i]-'0'+1;
		f1[0]=f2[0]=1;vis[0]=true;
		for(int i=1;i<=n;i++)
		{
			f1[i]=f2[i]=0;vis[i]=false;
			for(int j=1;j<=m;j++)
			{
				int l=strlen(c[j]);
				if(i<l) continue;
				if(b[j]==a[i]-a[i-l]*k[l]) f1[i]=(f1[i]+f1[i-l])%128,f2[i]+=f2[i-l],vis[i]|=vis[i-l];
			}
		}
		if(vis[n]&&f2[n]==1) puts("happymorsecode");
		else
		{
			if(!vis[n]) puts("nonono");
			else printf("puppymousecat %d\n",f1[n]);
		}
	}
}


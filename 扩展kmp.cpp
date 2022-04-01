#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 20000010
#define ll long long
using namespace std;
char a[maxn],b[maxn];
int n,m;
ll nxt[maxn],ext[maxn],ans1,ans2;
int main()
{
	scanf("%s%s",a,b);
	n=strlen(a),m=strlen(b);
	nxt[0]=m;
	int p=1;
	while(b[nxt[1]]==b[nxt[1]+1]&&nxt[1]+1<m) nxt[1]++;
	for(int i=2;i<m;i++)
	{
		if(i+nxt[i-p]<p+nxt[p]) nxt[i]=nxt[i-p];
		else
		{
			int t=max(p+nxt[p]-i,0ll);
			while(b[t]==b[i+t]&&i+t<m) t++;
			nxt[i]=t;
			p=i;
		}
	}
	p=0;
	while(a[ext[0]]==b[ext[0]]&&ext[0]<n&&ext[0]<m) ext[0]++;
	for(int i=1;i<n;i++)
	{
		if(i+nxt[i-p]<p+ext[p]) ext[i]=nxt[i-p];
		else
		{
			int t=max(p+ext[p]-i,0ll);
			while(a[i+t]==b[t]&&i+t<n&&t<m) t++;
			ext[i]=t;
			p=i;
		}
	}
	for(ll i=0;i<m;i++) ans1^=(i+1)*(nxt[i]+1);
	for(ll i=0;i<n;i++) ans2^=(i+1)*(ext[i]+1);
	printf("%lld\n%lld",ans1,ans2);
}


#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define maxn (1<<20)+10
using namespace std;
char s[maxn];
int t;
int n,z[maxn],sum[maxn];
int cnt[30];
ll tr[30],ans;
int lowbit(int x)
{
	return x&-x;
}
void add(int x)
{
	for(int i=x+1;i<=27;i+=lowbit(i))
	tr[i]++;
}
ll que(int x)
{
	ll p=0;
	for(int i=x+1;i;i-=lowbit(i))
	p+=tr[i];
	return p; 
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		memset(tr,0,sizeof(tr));
		scanf("%s",s);
		n=strlen(s);
		z[0]=n,z[1]=0;
		int p=1;
		while(s[z[1]]==s[z[1]+1]&&z[1]+1<n) z[1]++;
		for(int i=2;i<n;i++)
		{
			if(i+z[i-p]<p+z[p]) z[i]=z[i-p];
			else
			{
				int t=max(p+z[p]-i,0);
				while(s[i+t]==s[t]&&i+t<n) t++;
				z[i]=t;
				p=i;
			}
		}
		memset(cnt,0,sizeof(cnt));
		sum[n]=0;
		for(int i=n-1;i>=0;i--)
		{
			int t=s[i]-'a';
			cnt[t]++;
			if(cnt[t]&1) sum[i]=sum[i+1]+1;
			else sum[i]=sum[i+1]-1;
		}
		memset(cnt,0,sizeof(cnt));
		int now=1;
		cnt[s[0]-'a']++;
		for(int i=1;i<n-1;i++)
		{
			ll k=z[i+1]/(i+1)+1,k1,k2;
			if(k*(i+1)==n) k--;
			k1=k/2,k2=k-k1;
			add(now);
			ans+=que(sum[0])*k1; 
			ans+=que(sum[i+1])*k2;
			int t=s[i]-'a';
			cnt[t]++;
			if(cnt[t]&1) now++;
			else now--;
		}
		printf("%lld\n",ans);
	}
}


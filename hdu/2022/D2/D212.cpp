#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll read()
{
    ll ans=0,o=1;
    char c=getchar();
    for(;(c<'0'||c>'9')&&c!='-';c=getchar());
    if(c=='-') o*=-1,c=getchar();
    for(;'0'<=c&&c<='9';c=getchar())
        ans=ans*10+c-'0';
    return ans*o;
}
ll calc(ll x)
{
	return (x*9%31)+(7*(x*9/31)-2*x);
}
int main()
{
	int T=read();
	while(T--)
	{
		ll N=read();
		ll z=N/365,m=N%365;
		ll ans=0;
		if((N*9/31)<((2*N+6)/7))
		{
			if(z) ans=calc(m+365)+z-1;
			else 
			{
				puts("-1");
				continue;
			}
		}
		else ans=calc(m)+z;
		for(int i=1;i<=min(z,10000ll);i++)
			ans=min(ans,calc(m+365ll*i)+z-i);
		printf("%lld\n",ans);
	}
	return 0;
}
//1000000000000000000

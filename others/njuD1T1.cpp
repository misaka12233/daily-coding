#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1000010
#define ll long long
using namespace std;
ll t,p;
ll f[maxn]; 
double s;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&p);
		f[1]=1,s=1;
		for(ll i=2;i<p;i++)
		f[i]=f[p%i]+1,s+=1.0*f[i];
		s=s/(1.0*(p-1));
		printf("%0.10lf\n",s);
	}
	return 0;
}


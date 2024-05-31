#include<bits/stdc++.h>
#define N 1005
using namespace std;
typedef long long ll;
int read()
{
    int ans=0,o=1;
    char c=getchar();
    for(;(c<'0'||c>'9')&&c!='-';c=getchar());
    if(c=='-') o*=-1,c=getchar();
    for(;'0'<=c&&c<='9';c=getchar())
        ans=ans*10+c-'0';
    return ans*o;
}
int T,n,m; 
int d[N];
bitset<N> e[N];
const ll MOD=1000000007ll;
ll Inv[5]={0ll,1ll,500000004ll,333333336ll,250000002ll};
ll C(int a,int b){
	ll ans=1;
	for(int i=1;i<=b;i++)
		ans=ans*(a-i+1)%MOD*Inv[i]%MOD;
	return ans;
}
int main()
{
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=0;i<n;i++){
			e[i].reset();
			d[i]=0;
		}
		for(int i=0;i<m;i++){
			int u=read()-1,v=read()-1;
			d[u]++;
			d[v]++;
			e[u].set(v);
			e[v].set(u);
		}
		ll ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
			if(j!=i){
				int k=(e[i]&e[j]).count();
				ll t=d[i]-4;
				if(k<4) continue;
				if(e[i][j]) t--;
				if(t<2) continue;
				ans+=C(k,4)*C(t,2)%MOD;
				ans%=MOD; 	
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}


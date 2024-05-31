#include<bits/stdc++.h>
#define N 100005
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
int n;
int a[N],p[N];
void sol(){
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read(),p[a[i]]=i;
	int sum=0;
	for(int i=1;i<=n;i++){
		int x=p[i];
		if (a[i] != a[x])
			sum^=2;
		swap(a[i],a[x]);
		swap(p[a[i]],p[a[x]]);
	}
	int k=1;
	while(k<=n)k<<=1;
	k-=3;
	printf("%d %d\n",sum&2,sum|k);
}
int main()
{
	int _=read();
	while(_--){
		sol();
	}
	return 0;
}

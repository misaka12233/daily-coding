#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int m,n,ans1,ans2,cnt;
double p,ans3;
int main()
{
	scanf("%d%d%lf",&m,&n,&p);
	ans1=p,ans2=1;
	if(1.0*ans1+1.0-p<p-ans1*1.0) ans1++;
	if(ans1>m) ans1=m;
	ans3=fabs(ans1*1.0-p);
	for(int i=2;i<=n;i++)
	{
		double t=(double)i*p;
		int k;
		k=t;
		if(k>m) break;
		t=(double)k/i;
		t=p-t;
		if(ans3==t&&(long long)ans2*k!=(long long)ans1*i) cnt++;
		if(t<ans3) ans1=k,ans2=i,ans3=t,cnt=0;
		k++;
		t=(double)k/i;
		t=t-p;
		if(ans3==t&&(long long)ans2*k!=(long long)ans1*i) cnt++;
		if(t<ans3) ans1=k,ans2=i,ans3=t,cnt=0;
	}
	if(cnt==0)
	printf("%d/%d\n",ans1,ans2);
	else
	puts("TOO MANY");
}

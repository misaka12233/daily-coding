#include<bits/stdc++.h>
using namespace std;
int k,n,t,i,j,maxx,minn,pre;
long long num,m; 
bool check;
int main()
{
  scanf("%d",&t);
  while (t>0)
    {
      --t;check=false;
      scanf("%d%d",&n,&k);
      scanf("%d",&pre);
      m=pre;
      minn=INT_MAX;
      maxx=INT_MIN;
      for (i=1;i<k;++i)
        {
          scanf("%d",&j);
          if (j-pre<maxx) check=true;
          maxx=max(j-pre,maxx);
          minn=min(j-pre,minn);
          pre=j;
	    }
	  num=1ll*minn*(n-k+1);
	  if (num<m) check=true;
	  if (check==true)
	    printf("No\n");
	    else printf("Yes\n");
	}
  return 0;
}

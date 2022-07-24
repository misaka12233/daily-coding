#include <bits/stdc++.h>
using namespace std;
const int maxn = 4000000 + 10;
int n, m;
char s[maxn];
bool useful[maxn], nocnt[maxn];
int main()
{
    scanf("%d%d", &n, &m);
    int cntOut = 0, cntIn = 0, ans = 0;
    char c = getchar();
    for (int i = 0; i < m; i++)
    {
        s[i] = getchar();
        useful[i] = true;
        if (s[i] == '0')
            cntIn++;
        else 
        {
            if (cntOut < cntIn)
                cntOut++;
            else
                useful[i] = false;
        }
    }
    int cnt = 0, nowIn = 0, nowOut = 0;
    for (int i = 0; i < m; i++)
    {
        if (!useful[i]) continue;
        if (s[i] == '0')
        {
            nowIn++;
            if (nowIn > cntOut)
                continue;
            else
            {
                if (cnt < n) cnt++;
                else ans += 2, nocnt[nowIn] = true;
                ans++;
            }
        }
        else 
        {
            nowOut++;
            if (!nocnt[nowOut]) 
            {
                cnt--;
                if (cnt == 0 && nocnt[nowOut + 1])
                {
                    cnt++;
                    int tmp = nowOut + 1;
                    while (nocnt[tmp]) tmp++;
                    nocnt[tmp - 1] = false;
                }
            }
            ans++;
        }
        //printf("%d %d %d\n",i + 1, ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}
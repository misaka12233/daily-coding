#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
const long long inf = 0x7fffffff;
int t;
char s[maxn];
int cnt1, cnt2;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s);
        int l = strlen(s), i = 0;
        cnt1 = cnt2 = 0;
        while (i < l)
        {
            if (s[i] == 'a')
            {
                while (s[i] == 'a') 
                    i++;
                cnt1++;
            }
            else
            {
                while (s[i] == 'b') 
                    i++;
                cnt2++;
            }
        }
        if ((cnt1 + cnt2) & 1 == 1)
            printf("%s\n", s);
        else
        {
            s[l - 1] = ((s[l - 1] - 'a') ^ 1) + 'a';
            printf("%s\n", s);
        }
    }
    return 0;
}
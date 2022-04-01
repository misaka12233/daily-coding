#include <bits/stdc++.h>
using namespace std;
char s[1010], t[50];
int m;
int main()
{
    scanf("%s", s);
    scanf("%d", &m);
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        scanf("%s", t);
        l--;
        r--;
        int length = strlen(t), ans = 0;
        for (int i = l; i + length - 1 <= r; i++)
        {
            bool check = true;
            for (int j = 0; j < length; j++)
            {
                if (s[i + j] != t[j])
                {
                    check = false;
                    break;
                }
            }
            if (check)
                ans++;
        }
        printf("%d\n", ans);
    }
}
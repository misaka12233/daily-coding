#include <bits/stdc++.h>
using namespace std;
int T;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        char s[25];
        scanf("%s", s);
        int l = 0,r = strlen(s);
        bool judge = true;
        while (s[l] == '0') 
            l++;
        for (int i = l; i < r; i++)
        {
            if (s[i] != s[r + l - i - 1])
            {
                judge = false;
                break;
            }
        }
        if (judge)
            puts("Y");
        else
            puts("N");
    }
    return 0;
}

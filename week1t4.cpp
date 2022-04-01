#include <bits/stdc++.h>
using namespace std;
int T;
int main()
{
    char c[3];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", c);
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                if ((j >= i && j <= i + 2) || (j >= 10 - i - 1 && j <= 10 - i + 1))
                    putchar(c[0]);
                else
                    putchar(' ');
            }
            puts("");
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int T, x[8], y[8];
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        for (int i = 1; i <= 4; i++)
            scanf("%d%d", &x[i], &y[i]);
        for (int i = 1; i <= 3; i += 2)
        {
            if (x[i] > x[i + 1])
                swap(x[i], x[i + 1]);
            if (y[i] > y[i + 1])
                swap(y[i], y[i + 1]);
        }
        if (x[2] >= x[3] && x[4] >= x[1] && y[2] >= y[3] && y[4] >= y[1])
            puts("Intersection Found");
        else
            puts("Intersection Not Found");
    }
    return 0;
}
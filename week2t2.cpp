#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, d;
    for (a = 0; a <= 1; a++)
        for (b = 0; b <= 1; b++)
            for (c = 0; c <= 1; c++)
                for (d = 0; d <= 1; d++)
                    printf("cereal=%d, bread=%d, apple=%d, yogurt=%d, value=%d\n", a, b, c, d, !((a | b) & c) | d);
    return 0;
}
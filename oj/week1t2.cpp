#include <bits/stdc++.h>
using namespace std;
int main()
{
    int quarterSum, dimeSum, nickelSum;
    scanf("%d%d%d", &quarterSum, &dimeSum, &nickelSum);
    printf("%d\n", 25 * quarterSum + 10 * dimeSum + 5 * nickelSum);
    return 0;
}
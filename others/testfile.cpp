#include <bits/stdc++.h>

using namespace std;

int main()
{
    FILE *f = tmpfile();
    fprintf(f, "666\n");
    rewind(f);
    char s[100];
    fscanf(f, "%s", s);
    printf("%s\n", s);
}
#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200 + 10;
int n;
double f[maxn][maxn][maxn];
double p[6];
// f[x][y][z] = (x+2)(x+1)/n^2  * (f[x+2][y-2][z] + 1)
//			  + 2(x+1)(y+1)/n^2 * (f[x+1][y+1][z-2] + 1)
//			  + 2(x+1)z/n^2     * (f[x+1][y][z] + 1)
//			  + (y+2)y/n^2      * (f[x][y+2][z-2] + 1)
//			  + 2(y+1)z/n^2     * (f[x][y+1][z] + 1)
//			  + (z+2)(z+1)/n^2  * (f[x][y][z+2] + 1)
// rest = (x+y+z)/n^2 + y/n^2 + 1 - (x+y+z)^2/n^2
// f[x][y][z] += rest/(1-rest)^2
// x : 无配对 
// y : 仅有(a,b)
// z : 仅有(a,b), 且存在(b,c) 
bool check(int x, int y, int z)
{
	if (x + y + z <= n && x >= 0 && y >= 0 && z >= 0 && f[x][y][z] > 0.0)
		return true;
	else
		return false;
}
int main()
{
	scanf("%d", &n);
	if (n == 2)
	{
		puts("2.000000000");
		return 0;
	}
	for (int x = n; x >= 0; x--)
	{
		for (int y = n - x; y >= 0; y--)
		{
			for (int z = n - x - y; z >= 0; z--)
			{
				double r = 0.0;
				for (int i = 0; i < 6; i++)
					p[i] = 0;
				if (check(x + 2, y - 2, z))
					p[0] = 1.0 * (x+2) * (x+1) / n / n;
				if (check(x + 1, y + 1, z - 2))
					p[1] = 2.0 * (x+1) * (y+1) / n / n;
				if (check(x + 1, y, z))
					p[2] = 2.0 * (x+1) * z / n / n;
				if (check(x, y + 2, z - 2))
					p[3] = 1.0 * (y+2) * y / n / n;
				if (check(x, y + 1, z))
					p[4] = 2.0 * (y+1) * z / n / n;
				if (check(x, y, z + 2))
					p[5] = 1.0 * (z+2) * (z+1) / n / n;
				f[x][y][z] = p[0] * (f[x+2][y-2][z] + 1)
						   + p[1] * (f[x+1][y+1][z-2] + 1)
						   + p[2] * (f[x+1][y][z] + 1)
						   + p[3] * (f[x][y+2][z-2] + 1)
						   + p[4] * (f[x][y+1][z] + 1)
						   + p[5] * (f[x][y][z+2] + 1);
						   
				r = 1.0 - 1.0 * (x+y+z) * (x+y+z) / n / n + 1.0 * (x+2*y+z) / n / n;
				if (r < 1.0 && (f[x][y][z] > 0.0 || x == n))
    				f[x][y][z] += r / (1.0 - r) / (1.0 - r);
			}
		}
	}
	printf("%.9f\n", f[0][0][0]);
	return 0;
}


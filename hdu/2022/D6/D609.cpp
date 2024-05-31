#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
double x[4], y[4];
double A1, B1, C1, A2, B2, C2;
double a1, b1, c1, a2, b2, c2;
double dA1, dB1, dC1, dA2, dB2, dC2;
double l1, l2, k;
double ansx, ansy;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 0; i < 4; i++)
			scanf("%lf%lf", x + i, y + i);
			
		A1 = y[0] - y[1];
		B1 = x[1] - x[0];
		C1 = -x[0] * A1 - y[0] * B1;
		if (A1 * x[2] + B1 * y[2] + C1 < 0) A1 = -A1, B1 = -B1, C1 = -C1;
		l1 = sqrt(A1 * A1 + B1 * B1);
		A1 /= l1, B1 /= l1, C1 /= l1;
		
		A2 = y[0] - y[3];
		B2 = x[3] - x[0];
		C2 = -x[0] * A2 - y[0] * B2;
		if (A2 * x[2] + B2 * y[2] + C2 < 0) A2 = -A2, B2 = -B2, C2 = -C2;
		l1 = sqrt(A2 * A2 + B2 * B2);
		A2 /= l1, B2 /= l1, C2 /= l1;
		
		for (int i = 0; i < 4; i++)
			scanf("%lf%lf", x + i, y + i);
			
		a1 = y[0] - y[1];
		b1 = x[1] - x[0];
		c1 = -x[0] * a1 - y[0] * b1;
		if (a1 * x[2] + b1 * y[2] + c1 < 0) a1 = -a1, b1 = -b1, c1 = -c1;
		l2 = sqrt(a1 * a1 + b1 * b1);
		a1 /= l2, b1 /= l2, c1 /= l2;

		a2 = y[0] - y[3];
		b2 = x[3] - x[0];
		c2 = -x[0] * a2 - y[0] * b2;
		if (a2 * x[2] + b2 * y[2] + c2 < 0) a2 = -a2, b2 = -b2, c2 = -c2;
		l2 = sqrt(a2 * a2 + b2 * b2);
		a2 /= l2, b2 /= l2, c2 /= l2;
		
		k = l2 / l1;
		A1 *= k, B1 *= k, C1 *= k;
		A2 *= k, B2 *= k, C2 *= k;
		dA1 = A1 - a1, dB1 = B1 - b1, dC1 = C1 - c1;
		dA2 = A2 - a2, dB2 = B2 - b2, dC2 = C2 - c2;
		
		ansy = (dA1 * dC2 - dA2 * dC1) / (dA2 * dB1 - dA1 * dB2);
		ansx = (dB2 * dC1 - dB1 * dC2) / (dA2 * dB1 - dA1 * dB2);
		printf("%.6f %.6f\n", ansx, ansy);
	}
	return 0;
}
/*
2
0 5
15 5
15 0
0 0
3 2
9 5
10 3
4 0
0 2
2 2
2 0
0 0
0 1
1 1
1 0 
0 0
*/

#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
const long double eps = 0.000001;
long double A1, B1, C1, A2, B2, C2, x1, y1, z1, x2, y2, z2, r1, r2;
int q;
long double delta(long double a, long double b, long double c)
{
	return b * b - a * c * 4.0;
}
long double getans1(long double a, long double b, long double c)
{
	//cout << a << ' ' << b << ' ' << c << endl;
	return 1.0 / (2.0 * a) * (-b + sqrt(delta(a, b, c))); 
}
long double getans2(long double a, long double b, long double c)
{
	return 1.0 / (2.0 * a) * (-b - sqrt(delta(a, b, c)));
}
long double getdis(long double a, long double b, long double c)
{
	return (a - x2) * (a - x2) + (b - y2) * (b - y2) + (c - z2) * (c - z2);
}
int main()
{
	long double T;
	cin >> q;
	while (q--)
	{
		cin >> x1 >> y1 >> z1;
		cin >> A1 >> B1 >> C1;
		cin >> r1;
		cin >> x2 >> y2 >> z2;
		cin >> A2 >> B2 >> C2;
		cin >> r2;
		if(fabs(B1 * C2 - B2 * C1) < eps && fabs(A1 * B2 - A2 * B1) < eps && fabs(A1 * C2 - A2 * C1) < eps)
		{
			puts("No");
		}
		else
		{
			if(fabs(B1 * C2 - B2 * C1) < eps)
			{
				swap(x1, y1);
				swap(A1, B1);
				swap(x2, y2);
				swap(A2, B2);
			}
			if(fabs(B1 * C2 - B2 * C1) < eps)
			{
				swap(x1, z1);
				swap(A1, C1);
				swap(x2, z2);
				swap(A2, C2);
			}
			T = A2 * (x2 - x1) + B2 * (y2 - y1) + C2 * (z2 - z1);
			//cout << B2 << endl;
			/*cout << (B1 * C2 - B2 * C1) * (B1 * C2 - B2 * C1) + (A1 * B2 - A2 * B1) * (A1 * B2 - A2 * B1) + (A1 * C2 - A2 * C1) * (A1 * C2 - A2 * C1) << endl;
			cout << delta((B1 * C2 - B2 * C1) * (B1 * C2 - B2 * C1) + (A1 * B2 - A2 * B1) * (A1 * B2 - A2 * B1) + (A1 * C2 - A2 * C1) * (A1 * C2 - A2 * C1),
			2 * (B1 * T * (A1 * B2 - A2 * B1) + C1 * T * (A1 * C2 - A2 * C1)), B1 * B1 * T * T + C1 * C1 * T * T - r1 * r1 * (B1 * C2 - B2 * C1) * (B1 * C2 - B2 * C1)) << endl;*/
			if (delta((B1 * C2 - B2 * C1) * (B1 * C2 - B2 * C1) + (A1 * B2 - A2 * B1) * (A1 * B2 - A2 * B1) + (A1 * C2 - A2 * C1) * (A1 * C2 - A2 * C1),
			2.0 * (B1 * T * (A1 * B2 - A2 * B1) + C1 * T * (A1 * C2 - A2 * C1)), B1 * B1 * T * T + C1 * C1 * T * T - r1 * r1 * (B1 * C2 - B2 * C1) * (B1 * C2 - B2 * C1)) > -eps)
			{
				long double xa = getans1((B1 * C2 - B2 * C1) * (B1 * C2 - B2 * C1) + (A1 * B2 - A2 * B1) * (A1 * B2 - A2 * B1) + (A1 * C2 - A2 * C1) * (A1 * C2 - A2 * C1),
			2.0 * (B1 * T * (A1 * B2 - A2 * B1) + C1 * T * (A1 * C2 - A2 * C1)), B1 * B1 * T * T + C1 * C1 * T * T - r1 * r1 * (B1 * C2 - B2 * C1) * (B1 * C2 - B2 * C1)) + x1;
				long double xb = getans2((B1 * C2 - B2 * C1) * (B1 * C2 - B2 * C1) + (A1 * B2 - A2 * B1) * (A1 * B2 - A2 * B1) + (A1 * C2 - A2 * C1) * (A1 * C2 - A2 * C1),
			2.0 * (B1 * T * (A1 * B2 - A2 * B1) + C1 * T * (A1 * C2 - A2 * C1)), B1 * B1 * T * T + C1 * C1 * T * T - r1 * r1 * (B1 * C2 - B2 * C1) * (B1 * C2 - B2 * C1)) + x1;
				long double ya;
				long double za;
				long double yb;
				long double zb;
				ya = ((A1 * C2 - A2 * C1) * (xa - x1) + C1 * T) / (B2 * C1 - B1 * C2) + y1;
				za = ((A1 * B2 - A2 * B1) * (xa - x1) + B1 * T) / (B1 * C2 - B2 * C1) + z1;
				yb = ((A1 * C2 - A2 * C1) * (xb - x1) + C1 * T) / (B2 * C1 - B1 * C2) + y1;
				zb = ((A1 * B2 - A2 * B1) * (xb - x1) + B1 * T) / (B1 * C2 - B2 * C1) + z1;
				long double d1 = getdis(xa, ya, za), d2 = getdis(xb, yb, zb);
				if(max(d1, d2) >= r2 * r2 && min(d1, d2) <= r2 * r2)
					puts("Yes");
				else 
					puts("No");
			}
			else
			{
				puts("No");
			}
		}
	}
	return 0;
}


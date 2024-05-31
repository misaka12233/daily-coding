#include <bits/stdc++.h>

typedef long double ldb;

using namespace std;

ldb x, y, z, a, b, c, r;
ldb x_, y_, z_, a_, b_, c_, r_;

ldb calc_dist(ldb x1, ldb y1, ldb z1, ldb x2, ldb y2, ldb z2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
}

bool sol() {
    cin >> x >> y >> z >> a >> b >> c >> r;
    cin >> x_ >> y_ >> z_ >> a_ >> b_ >> c_ >> r_;
    //printf("%Lf %Lf %Lf\n", a, b, c);
    if (
        a*b_ == a_*b and
        a*c_ == a_*c and
        b*a_ == b_*a and
        b*c_ == b_*c and
        c*a_ == c_*a and
        c*b_ == c_*b
    ) return 0;
    ldb d = -(a*x + b*y + c*z);
    ldb d_ = -(a_*x_ + b_*y_ + c_*z_);
    if (a == 0 and b != 0) {
        swap(a, b);
        swap(a_, b_);
        swap(x, y);
        swap(x_, y_);
    } else if (a == 0 and c != 0) {
        swap(a, c);
        swap(a_, c_);
        swap(x, z);
        swap(x_, z_);
    }
    if (a*b_ == a_*b) {
        swap(b, c);
        swap(b_, c_);
        swap(y, z);
        swap(y_, z_);
    }
    
    // ax + by + cz + d = 0
    // a_x_ + b_y_ + c_z_ + d_ = 0
    // (b_-a_/a*b) y + (c_-a_/a*c) z + (d_-a_/a*d) = 0
    // y = ky * z + hy
    // ax + (bk+c) z + (bh+d) = 0
    // x = kx * z + hx
    // (x-x0)^2 + (y-y0)^2 + (z-z0)^2 - r0^2 = 0
    // (kx * z + hx - x0)^2 + ... = 0
    ldb ky = -(c_-a_/a*c)/(b_-a_/a*b);
    ldb hy = -(d_-a_/a*d)/(b_-a_/a*b);
    ldb kx = -(b*ky+c)/a;
    ldb hx = -(b*hy+d)/a;
    ldb A = kx*kx + ky*ky + 1;
    ldb B = 2*( kx*(hx-x) + ky*(hy-y) - z );
    ldb C = (hx-x)*(hx-x) + (hy-y)*(hy-y) + z*z - r*r;
    ldb Delta = B*B - 4*A*C;
    if (Delta <= 0) return 0;
    ldb z1 = (-B + sqrt(Delta)) / (2*A), x1 = kx*z1+hx, y1 = ky*z1+hy;
    ldb z2 = (-B - sqrt(Delta)) / (2*A), x2 = kx*z2+hx, y2 = ky*z2+hy;
    ldb dist1 = calc_dist(x1, y1, z1, x_, y_, z_);
    ldb dist2 = calc_dist(x2, y2, z2, x_, y_, z_);
    //printf("%Lf %Lf %Lf\n", x1, y1, z1);
    //printf("%Lf %Lf %Lf\n", x2, y2, z2);
    if (dist1 < r_ and dist2 > r_) return 1;
    if (dist1 > r_ and dist2 < r_) return 1;
    return 0;
}

int main() {
    int _; cin >> _; while (_--) puts(sol() ? "Yes" : "No");
	return 0;
}

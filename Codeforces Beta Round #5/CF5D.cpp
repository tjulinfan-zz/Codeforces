#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

double a, v, l, d, w;

double dist(double speed, double time) {
    return speed * time + a * time * time / 2;
}

double travelTime(double l, double speed) {
    double tAll = (sqrt(speed * speed + 2 * a * l)- speed) / a;
    double tMax = (v - speed) / a;
    if (tMax >= tAll) {
        return tAll;
    } else {
        return tMax + (l - dist(speed, tMax)) / v;
    }
}

int main() {
    cin >> a >> v >> l >> d >> w;

    double ans;
    if (w > v) {
        ans = travelTime(l, 0);
    } else {
        double tw = w / a;
        double dw = dist(0, tw);
        if (dw >= d) {
            ans = travelTime(l, 0);
        } else {
            ans = tw + travelTime(0.5 * (d - dw), w) * 2 + travelTime(l - d, w);
        }
    }

    cout << fixed << setprecision(8) << ans << endl;

    return 0;
}

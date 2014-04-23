#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 1000000 + 10;

int n;
int a[MAXN], h[MAXN];
int l[MAXN], r[MAXN], c[MAXN];

int main() {
    scanf("%d", &n);
    int maxh = 0, maxi;
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &a[i]);
        if (a[i] > maxh) {
            maxh = a[i];
            maxi = i;
        }
    }

    for (int i = 0; i < n; ++ i)
        h[i] = a[(maxi + i) % n];
    h[n] = h[0];

    c[0] = 0, l[0] = -1;
    for (int i = 1; i <= n; ++ i) {
        l[i] = i - 1;
        while (l[i] >= 0 && h[i] > h[l[i]])
            l[i] = l[l[i]];
        c[i] = 0;
        if (h[l[i]] == h[i]) {
            c[i] = c[l[i]] + 1;
            l[i] = l[l[i]];
        }
    }

    r[n] = n + 1;
    for (int i = n - 1; i >= 0; -- i) {
        r[i] = i + 1;
        while (r[i] <= n && h[i] > h[r[i]])
            r[i] = r[r[i]];
        if (h[i] == h[r[i]])
            r[i] = r[r[i]];
    }

    long long ans = 0;
    for (int i = 0; i < n; ++ i) {
        ans += c[i];
        if (l[i] >= 0) ans ++;
        if (r[i] <= n) ans ++;
        if (l[i] == 0 && r[i] == n)
            ans -= 1;
    }
    printf("%I64d\n", ans);

    return 0;
}

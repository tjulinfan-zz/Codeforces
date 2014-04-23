#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 5010;

struct en {
    int w, h, pos;
} ens[MAXN];

bool cmp(const struct en& a, const struct en& b) {
    return a.w < b.w;
}

int f[MAXN], g[MAXN];

int main() {
    int n, w, h;
    scanf("%d%d%d", &n, &w, &h);
    for (int i = 1; i <= n; ++ i) {
        scanf("%d%d", &ens[i].w, &ens[i].h);
        ens[i].pos = i;
    }
    sort(ens + 1, ens + n + 1, cmp);
    int st = n;
    for (int i = 1; i <= n; ++ i) {
        if (ens[i].w > w) {
            st = i - 1;
            break;
        }
    }
    memset(f, 255, sizeof(f));
    f[st] = 0;
    ens[st].w = w, ens[st].h = h;

    int ansi = st;
    for (int i = st + 1; i <= n; ++ i) {
        for (int j = st; j < i; ++ j) {
            if (f[j] != -1 && ens[i].w > ens[j].w && ens[i].h > ens[j].h) {
                if (f[j] + 1 > f[i]) {
                    f[i] = f[j] + 1;
                    g[i] = j;
                }
            }
        }
        if (f[i] > f[ansi])
            ansi = i;
    }

    printf("%d\n", f[ansi]);
    if (ansi != st) {
        vector<int> ans;
        while (ansi != st) {
            ans.push_back(ens[ansi].pos);
            ansi = g[ansi];
        }
        for (vector<int>::reverse_iterator it = ans.rbegin(); it != ans.rend(); it ++) {
            printf("%d ", *it);
        }
        puts("");
    }
    return 0;
}

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

const int MINVAL = 0;
const int MAXVAL = 1e9;

const int MAXM = 1010;
const int MAXN = 1010;

int n, m;
int a[MAXN][MAXM];
bool flag[MAXM][MAXM];


bool check(int val) {
    memset(flag, false, sizeof(flag));
    for (int i = 0; i < n; ++ i) {
        vector<int> pos;
        for (int j = 0; j < m; ++ j) {
            if (a[i][j] >= val) {
                for (int k = 0; k < pos.size(); ++ k)
                    if (flag[pos[k]][j])
                        return true;
                    else
                        flag[pos[k]][j] = true;
                pos.push_back(j);
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            scanf("%d", &a[i][j]);
        }
    }

    int l = MINVAL, r = MAXVAL;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    printf("%d\n", r);
    return 0;
}

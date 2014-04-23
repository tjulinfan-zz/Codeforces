#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int d, sumTime;
    int minTime[30], maxTime[30];
    int summin[30], summax[30];
    int ans[30];
    scanf("%d%d", &d, &sumTime);
    for (int i = 0; i < d; ++ i) {
        scanf("%d%d", &minTime[i], &maxTime[i]);
        if (i == 0) {
            summin[i] = minTime[i];
            summax[i] = maxTime[i];
        } else {
            summin[i] = summin[i - 1] + minTime[i];
            summax[i] = summax[i - 1] + maxTime[i];
        }
    }
    d --;
    if (sumTime < summin[d] || sumTime > summax[d]) {
        puts("NO");
    } else {
        puts("YES");
        for (int i = 0; i <= d; ++ i) {
            int tmp = sumTime - (summin[d] - summin[i]);
            tmp = (tmp < maxTime[i] ? tmp : maxTime[i]);
            sumTime -= tmp;
            printf("%d ", tmp);
        }
        puts("");
    }
    return 0;
}

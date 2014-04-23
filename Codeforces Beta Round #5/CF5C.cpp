#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <cstring>
#include <stack>
using namespace std;

char s[1010000];
int len[1010000];

int main() {
    scanf("%s", s);
    stack<int> st;
    int n = 0;
    for (; s[n] != 0; ++ n) {
        if (s[n] == '(') {
            st.push(n);
        } else {
            if (!st.empty()) {
                int last = st.top();
                st.pop();
                if (last == 0)
                    len[n] = n + 1;
                else
                    len[n] = len[last - 1] + n - last + 1;
            }
        }
    }

    int ansl = 0, ansc = 1;
    for (int i = 0; i < n; ++ i) {
        if (len[i] == ansl) {
            ansc ++;
        } else if (len[i] > ansl) {
            ansl = len[i];
            ansc = 1;
        }
    }
    if (ansl == 0) ansc = 1;
    printf("%d %d\n", ansl, ansc);
    return 0;
}

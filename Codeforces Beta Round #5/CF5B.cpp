#include <cstdio>
#include <iostream>
using namespace std;

string s[1001];

int main() {
    int n = 0, maxlen = 0;
    while (getline(cin, s[n])) {
        if (s[n].length() > maxlen)
            maxlen = s[n].length();
        n ++;
    }
    for (int i = 0; i < maxlen + 2; ++ i)
        cout << "*";
    cout << endl;

    int offset = 0;
    for (int i = 0; i < n; ++ i) {
        cout << "*";
        int leftsps = (maxlen - s[i].length()) / 2;
        if ((maxlen - s[i].length()) % 2 != 0) {
            leftsps += offset;
            offset = 1 - offset;
        }
        for (int j = 0; j < leftsps; ++ j)
            cout << " ";
        cout << s[i];
        for (int j = 0; j < maxlen - s[i].length() - leftsps; ++ j)
            cout << " ";
        cout << "*" << endl;


    }

    for (int i = 0; i < maxlen + 2; ++ i)
        cout << "*";
    cout << endl;
    return 0;
}

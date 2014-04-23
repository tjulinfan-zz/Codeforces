#include <string>
#include <map>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> cnt;
    for (int i = 0; i < n; ++ i) {
        string name;
        cin >> name;
        if (cnt.find(name) == cnt.end()) {
            cout << "OK" << endl;
            cnt[name] = 1;
        } else {
            cout << name << cnt[name] << endl;
            cnt[name] ++;
        }
    }
    return 0;
}

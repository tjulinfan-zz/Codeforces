#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;

int main() {
    string s;
    int ans = 0;
    map<string, int> person;
    while (getline(cin, s)) {
        if (s[0] == '+') {
            string name(s, 1, s.length() - 1);
            person[name] = 1;
        } else if (s[0] == '-') {
            string name(s, 1, s.length() - 1);
            map<string, int>::iterator it = person.find(name);
            if (it != person.end()) {
                person.erase(it);
            }
        } else {
            int pos =  s.find(':');
            ans += person.size() * (s.length() - pos - 1);
        }
    }
    cout << ans << endl;
    return 0;
}

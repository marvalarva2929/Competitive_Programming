#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;

signed main() {

    while (true) {
        string c; cin >> c;
        map<string, int> cnt;

        for (int i = 0; i < c.size(); i++)
            for (int j = i; j < c.size(); j++)
                cnt[c.substr(i, j - i + 1)]++;

        for (auto &p : cnt)
            if (p.second % 2 == 0)
                cout << c << " " <<  p.first << nl;
        }
    }

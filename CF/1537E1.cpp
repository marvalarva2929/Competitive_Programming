using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, k; cin >> n >> k;
    string s; cin >> s;
    int ind = 0;
    int j = 0;

    for (int i = 1; i < n; i++)
        if (s[i] < s[j]) ind = i, j = 0;
        else if (s[i] == s[j]) j++;
        else break;

    s = s.substr(0, ind + 1);

    while (s.size() < k) {
        s += s;
    }

    s = s.substr(0, k);
    cout << s << nl;
}
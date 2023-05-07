using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n - 1; i++)
        { int x; cin >> x; a[--x]++; }

    sort(a.begin(), a.end(), greater<int>());
    while (a.size() && a.back() <= 0) a.pop_back();

    int secs = 0;
    a.emplace_back(1);
    
    int rem = a.size();
    for (int & i : a)
        i -= rem--,
        secs++;
    
    while (a.size() && a.back() <= 0) a.pop_back();
    sort(a.begin(), a.end(), greater<int>());

    while (a.size()) {
        n = a.size();
        int last = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == a[0])
                last = i;
            else break;

        a[last]--;
        for (int i = 0; i < n; i++)
            a[i]--;
        while (a.size() && a.back() <= 0) a.pop_back();
        secs++;
    }

    cout << secs << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
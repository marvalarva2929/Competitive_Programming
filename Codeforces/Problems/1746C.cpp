using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    int a[n] = {};
    vector<pair<int, int>> diffs;


    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            diffs.push_back({a[i] - a[i + 1], i + 1});

    sort(diffs.begin(), diffs.end());
    int ans[n] = {};
    int i = n - 1;
    while (i >= 0 && diffs.size())
        ans[i--] = diffs.back().second + 1, diffs.pop_back();

    while (i >= 0)
        ans[i--] = 1;

    for (int i : ans)
        cout << i << " ";
    cout << nl;
}   

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t; cin >> t;
    while(t--)
        solve();
}
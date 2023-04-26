using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX 20
#define pi pair<int, int>

string x;
string s[MAX];
string t;
int n;

pi longest_prefix(string y) {
    pair<int, int> ans = {0, -1};
    for (int i = 0; i < n; i++) {
        string find = s[i];
        bool isPrefix = true;
        for (int j = 0; j < find.size(); j++)
            if (find[j] != y[j]) 
                { isPrefix = false; break; }
        if (isPrefix) 
            ans = max(ans, {find.size(), i});
    }
    return ans;
}

void solve() {
    cin >> t >> n;
    for (int i = 0; i < n; i++) { 
        string xx; cin >> xx;
        s[i] = xx;
    }
    pi pref[t.size()] = {};
    vector<pi> ans;
    vector<int> q;

    for (int i = 0; i < t.size(); i++)
        pref[i] = longest_prefix(t.substr(i));

    int curr = 0;
    q.push_back(curr);

    while (curr < t.size()) {
        pi mx = {curr + pref[curr].first, 0};
        for (int i = curr; i <= curr + pref[curr].first; i++) {
            mx = max(mx, {i + pref[i].first, i});
        }
        if (mx.first == (curr + pref[curr].first)) {
            cout << -1 << nl;
            return;
        }

        if (mx.second == t.size()) break;

        q.push_back(mx.second);
        curr = mx.second;
    }

    for (int i : q)
        ans.push_back({pref[i].second, i});

    cout << ans.size() << nl;
    for (auto p : ans)
        cout << p.first + 1 << " " << p.second + 1 << nl;
    

    
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
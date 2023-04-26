using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

void solve() {
    int n; cin >> n;
    vector<int> trade[3][3] = {};
    int a[n][3] = {};
    vector<pair<pair<int, int>, pair<int, int>>> trades;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < 3; j++)
            a[i][j] = (s[j] == 'w' ? 0 : s[j] == 'i' ? 1 : 2);
    }

    for (int j = 0; j < n; j++) {
        int cnt[3] = {};
        for (int i : a[j])
            cnt[i]++;

        for (int i = 0; i < 3; i++)
            if (cnt[i] > 1) {
                if (!cnt[(i + 1) % 3]) // 1 -> 2, 2 -> 0, 3 -> 1
                    trade[(i + 1) % 3][i].push_back(j);
                if (!cnt[(i + 2) % 3]) // 1 -> 3, 2 -> 1, 3 -> 2
                    trade[(i + 2) % 3][i].push_back(j);
            }   
    }

    for (int i = 0; i < 3; i++) 
        for (int j = i + 1; j < 3; j++) {
            int delta = min(trade[i][j].size(), trade[j][i].size());
            for (int k = 0; k < delta; k++) {
                trades.push_back({{trade[i][j].back(), j}, {trade[j][i].back(), i}}),
                trade[i][j].pop_back(),
                trade[j][i].pop_back();
            }
        } 

    if (trade[0][1].size()) {
        assert(trade[0][1].size() == trade[2][0].size());
        while (trade[0][1].size())
            trades.push_back({{trade[0][1].back(), 1}, {trade[2][0].back(), 0}}),
            trade[2][1].push_back(trade[2][0].back()),
            trade[0][1].pop_back(),
            trade[2][0].pop_back();
        
        while (trade[1][2].size()) 
            trades.push_back({{trade[1][2].back(), 2}, {trade[2][1].back(), 1}}),
            trade[1][2].pop_back(),
            trade[2][1].pop_back();
    
    } else if (trade[1][0].size()) {
        assert(trade[1][0].size() == trade[0][2].size());

        while (trade[1][0].size())
            trades.push_back({{trade[1][0].back(), 0}, {trade[0][2].back(), 2}}),
            trade[1][2].push_back(trade[1][0].back()),
            trade[1][0].pop_back(),
            trade[0][2].pop_back();
        
        while (trade[1][2].size()) 
            trades.push_back({{trade[1][2].back(), 2}, {trade[2][1].back(), 1}}),
            trade[1][2].pop_back(),
            trade[2][1].pop_back();
    }
    
    cout << trades.size() << nl;
    for (auto t : trades)
        cout << t.first.first + 1 << " " << (t.first.second == 0 ? 'w' : t.first.second == 1 ? 'i' : 'n') <<  " " << t.second.first + 1 << " " << (t.second.second == 0 ? 'w' : t.second.second == 1 ? 'i' : 'n') << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t; 
    while (t--)
        solve();
}
using namespace std;
#include <bits/stdc++.h>
#define nl '\n'
#define int long long
#define MAX (int)1e4 + 10
vector<int> a[MAX];

signed main() {
    int n; cin >> n;
    int splits = 0, comb = 0;

    vector<int> all;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int c; cin >> c; all.push_back(c);
            a[i].push_back(c);
        }
    }

    sort(all.begin(), all.end());
    unordered_map<int, int> rank;
    for (int i = 0; i < all.size(); i++)
        rank[all[i]] = i;
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i].size() - 1; j++) {
            int a1 = rank[a[i][j]], a2 = rank[a[i][j + 1]];
            if (a2 != a1 + 1)
                splits++;
        }
    }

    comb = n + splits - 1;

    cout << splits << " " << comb << nl;

}
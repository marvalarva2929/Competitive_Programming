#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define ff first
#define ss second
#define pi pair<int, int>

using namespace std;
const int mxn = 3000;
int pref[mxn+1][2];
bool a[mxn+1];

int cost(int l, int r, bool b) {
    return (pref[r][!b] - pref[l - 1][!b]);    
}

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        a[i] = c & 1;
    }
    
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 2; j++)
            pref[i][j] = pref[i - 1][j] + (a[i] == j);
    
    vector<vector<pi>> best(n + 1, vector<pi>(n + 1)); 
   
    vector<int> bf(k + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            int t = cost(j, i - 1, 1);
            if (t <= k) bf[t] = max(bf[t], i - j); 
        }
        for (int i = 1; i <= k; i++)
            bf[i] = max(bf[i], bf[i - 1]);

        for (int j = i; j <= n; j++) {
            int t = cost(i, j, 0);
            if (t <= k) best[i][j] = max(best[i][j], {(j - i + 1), bf[k - t]});
            else best[i][j] = {-1, -1};
        }
    }

    vector<int> af(k + 1, 0);
    for (int i = n; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            int t = cost(i + 1, j, 1);
            if (t <= k) af[t] = max(af[t], j - i);
        }    
        for (int i = 1; i <= k; i++)
            af[i] = max(af[i], af[i - 1]);
     
        for (int j = 1; j <= i; j++) {
            int t = cost(j, i, 0);
            if (t <= k) best[j][i] = max(best[j][i], {(i - j + 1), af[k - t]});
        } 
    }
    
    vector<int> sv(n + 1, -1);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            if (best[i][j].ff == -1) continue;
            sv[best[i][j].ff] = max(sv[best[i][j].ff], best[i][j].ss);
        }
    
    int bs = 0; 
    for (int i = 1; i <= n; i++) {
        if (cost(1, i, 1) <= k) bs = max(bs, i);
        if (cost(i, n, 1) <= k) bs = max(bs, n - i + 1); 
    }

    sv[0] = max({af[k], bf[k], bs});
    //for (int i = 0; i <= n; i++)
    //    cout << sv[i] << nl[i == n];

    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int j = 0; j <= n; j++)
            if (sv[j] != -1)
                mx = max(mx, (j * i) + sv[j]);
        cout << mx << " "; 
    }
    cout << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}

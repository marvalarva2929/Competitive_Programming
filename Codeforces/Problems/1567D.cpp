#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        b >>= 1;
        a *= a;
    }
    return ans;
}

bool isten(int x) {
    int a = 1;
    while (a < x) 
        a *= 10;
    return a == x;
}

int split(int x) {
    if (isten(x)) return x/10;
    else return power(10, log10(x));
}

void solve() {
    int s, n; cin >> s >> n;
    vector<int> cur;
    cur.push_back(s);

    for (int i = 0; i < n - 1; i++) {
        int x = -1;
        for (int j = 0; j < cur.size(); j++) 
            if (!isten(cur[j])) { x = cur[j], cur.erase(cur.begin() + j); break; }
        if (x == -1) {
            int mn = LLONG_MAX;
            for (int j = 0; j < cur.size(); j++)
                if (cur[j] != 1) mn = min(mn, cur[j]);
            for (int j = 0; j < cur.size(); j++)
                if (cur[j] == mn) {
                    x = cur[j];
                    cur.erase(cur.begin() + j); 
                    break;
                }
        }
        

        int t = split(x);

        cur.push_back(t);
        cur.push_back(x - t);
    }
    
    for (int x : cur)
        cout << x << " ";
    cout << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--)
        solve();
}

#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 20;
bool dp[mxn * 3 + 1][(1 << mxn)];
int rep[1 << mxn];
int n;

int stob(string x) {
    int ans = 0;
    for (int i = n-1; i >= 0; i--)
        ans += (x[i] & 1) << (n - i - 1);
    return ans;
}
    
void cyc(int& x) {
    x += (x & 1) << n;
    x >>= 1;
}

void solve() {
    string s, t; cin >> s >> t;
    int a = stob(s), b = stob(t);
    int cur = 0;

    for (int i = 0; i <= n * 3; i++) {
        if (dp[i][rep[a ^ cur]]) { cout << i << endl; return; }
        cur ^= b;
        cyc(b);
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t >> n;
    
    dp[0][0] = 1;
    for (int i = 1; i < 1 << n; i++) {
        int x = i; 
        for (int j = 0; j < n; j++) {
            cyc(x);
            if (rep[x]) { rep[i] = rep[x]; goto skip; };
        }
        rep[i] = i;
        skip:;
    }
    

    int cur = 0;
    for (int i = 1; i <= n * 3; i++) {
        cur ^= (1 << ((i - 1) % n));
        
        for (int j = 0; j < (1 << n); j++) {
            if (dp[i - 1][rep[j]]) dp[i][rep[j ^ cur]] = 1;
        }
    }

    while (t--)
        solve();
}

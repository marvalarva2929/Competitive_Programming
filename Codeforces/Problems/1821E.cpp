#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
bool a[mxn];
int b[mxn];
int prf[mxn];
int n;

void solve() {
    int k; cin >> k;
    string s; cin >> s;
    n = s.size();
    fill(b, b + n, -1);
    fill(prf, prf + n, 0);

    for (int i = 0; i < n; i++)
        a[i] = s[i] == ')';
    
    reverse(a, a + n); // 1 == '(' ---- 0 == ')'
    

    stack<int> prv;
    for (int i = 0; i < n; i++) {
        if (a[i]) prv.push(i), prf[i]++;
        else b[i] = prv.top(), b[prv.top()] = i, prv.pop(), prf[i]--;
    } 
    
    for (int i = 1; i < n; i++)
        prf[i] += prf[i - 1];

    int ans = 0;
    vector<int> lg;

    queue<pi> rng;
    rng.push({0, n - 1});

    while (rng.size()) {
        pi fr = rng.front();
        rng.pop();
        
        int cnt = 0;
        int l = fr.ff;
        while (l < fr.ss) {
            cnt++;
            lg.push_back(((b[l] - l) - 1)/2);
            rng.push({l + 1, b[l] - 1});
            l = b[l] + 1;
        }
    
        if (fr.ff != 0) ans += prf[fr.ff - 1] * cnt;
    }
    
    sort(lg.begin(), lg.end(), greater<int>());
    
    for (int i = 0; i < min((int)lg.size(), k); i++)
        ans -= lg[i];

    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}

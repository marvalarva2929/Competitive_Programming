#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 2e5;
int a[mxn];

int solve() {
    int n; cin >> n;
    set<int> all;
    for (int i = 0; i < n; i++)
        cin >> a[i], all.insert(a[i]); 
    
    if (n == 1) return 1;
    
    int g = abs(a[1] - a[0]);
    for (int i = 1; i < n; i++)
        g = gcd(g, abs(a[i] - a[i - 1]));
    
    int ans = 0;
    for (int x : all)
        ans += (abs(*all.rbegin() - x) / g);
    
    int cur = *all.rbegin();
    for (auto i = all.rbegin(); i != all.rend(); i++) {
        if (*i != cur) return ans += abs(*all.rbegin() - cur) / g; 
        cur -= g; 
    }
    
    return ans + n;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        cout << solve() << nl;        
}

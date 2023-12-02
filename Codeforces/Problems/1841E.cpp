#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 2e5;
int n, m;
int a[mxn];

void solve() {
    cin >> n;
    vector<int> is[n + 1];
    vector<int> segs(n + 1, 0);
    set<int> st;

    for (int i = 0; i < n; i++)
        cin >> a[i], a[i] = n - a[i], is[a[i]].push_back(i);
    cin >> m;
    int ans = m; 
    
    st.insert(-1);
    st.insert(n);
    segs[n] += n;
    //cout << nl;

    auto add = [&](int i, int j) -> void {
        int r = *st.lower_bound(j),
            l = *prev(st.lower_bound(j));
        segs[r - l - 1] -= (n - i);
        segs[j - l - 1] += (n - i);
        segs[r - j - 1] += (n - i);
        st.emplace(j); 
    };  
    
    for (int i = 0; i < n; i++)
        for (int j : is[i])
            add(i, j);
    
    int i = n;
    while (i && m) {
        int tk = i * segs[i];
        if (m - tk < 0) {
            ans -= ((m + i - 1) / i);
            break;
        } else m -= tk, ans -= segs[i--]; 
    }
    
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}

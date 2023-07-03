#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second
#define pb() push_back()
#define all(x) x.begin(), x.end()

using namespace std;

const int mxn = 2e5;
int a[mxn + 2];

void solve() {
    int n, d; cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    a[0] = 0;

    multiset<int> segs;

    pi mn = {INT_MAX, -1};

    for (int i = 1; i <= n; i++)
        segs.insert(a[i] - a[i - 1] - 1),
        mn = min(mn, {a[i] - a[i - 1] - 1, i});

        
    int ans = *segs.begin();
        
    vector<int> check;
    check.push_back(mn.second);
    if (mn.second > 1)
        check.push_back(mn.second - 1);
    //for (int x : segs)
    //    cout << x << " ";
    //cout << nl;

    for (int i : check) {
        multiset<int> t = segs;
        
        t.erase(t.find(a[i] - a[i - 1] - 1));
        
        if (i < n) { 
            t.erase(t.find(a[i + 1] - a[i] - 1));
            t.insert(a[i + 1] - a[i - 1] - 1);
        }

        //cout << i << " " << a[i] << " : ";
        //for (int x : t)
        //    cout << x << " ";
        //cout << nl;


        auto it = t.rbegin();
            
        //cout << i << " : " << *it << nl;

        int mn = max((*it - 1)/2, (d - a[n - (i == n)] - 1));
        
        ans = max(ans, min(mn, *t.begin()));
    }
    
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}

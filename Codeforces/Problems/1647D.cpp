#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

vector<int> factors(int x) {
    vector<int> ans;
    for (int i=1; i*i<= x; i++) {
        if (x % i == 0) {
            ans.push_back(i);
            if (i * i != x)
                ans.push_back(x/i);
        }
    }
    return ans;
}

void solve(int tt) {
    int x, d;
    cin >> x >> d;
    string ch = to_string(x) + ',' + to_string(d); 
    //if (tt == 41) {
    //    cout << ch << nl;
    //}
    int cnt = 0;
    int t = d;
    while (x % t == 0)
        t *= d,
        cnt++;
    t /= d;
    x /= t;
    
    if (cnt < 2) {
        cout << "NO" << nl;
        return;
    } 
    
    //cout << t << " " << cnt << nl;

    vector<int> one = factors(d), two = factors(x);
    
    //cout << one.size() << " " << two.size() << nl;

    if (two.size() > 2) {
        cout << "YES" << nl;
        return;
    }
    
    if (cnt < 3) {
        cout << "NO" << nl;
        return;
    }
    
    if (one.size() > 3) {
        cout << "YES" << nl;
        return;
    } else if (one.size() == 3) {
        if (one[2] == x && cnt < 4) cout << "NO" << nl;
        else cout << "YES" << nl;
        return;
    }
    
    cout << "NO" << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int t; cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}
     

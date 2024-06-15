#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e4;
int a[mxn];

vector<int> divs(int x) {
    vector<int> ans;
    
    for (int i = 1; i * i <= x; i++) {
        if (i * i == x) ans.push_back(i);
        else if (x % i == 0)
            ans.push_back(i), ans.push_back(x / i);
    }
    
    return ans;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    
    int mxl = a[0]/4;
    for (int i = n - 1; i >= 0; i--)
        a[i] -= a[0];

    set<int> all;
    for (int i = 0; i < n; i++)
        all.insert(a[i]);

    vector<int> b;
    for (int c : all)
        b.push_back(c);

    
    if (b.size() <= 3) {
        cout << (mxl * (mxl + 1)) / 2 << endl;
        return 0 ;
    }
    
//    for (int c : b)
//        cout << c << " ";
//    cout << nl;

    int ans = 6;
    for (int i = 4; i <= min(mxl, b[2]); i++) {
        set<int> l;
        for (int j = 0; j < b.size(); j++)
            l.insert(b[j] % i);

        ans += (i * (l.size() <= 3));
    }
    
    map<int, int> cnt;
    for (int i = 3; i < b.size(); i++) {
        for (int j = 0; j < 3; j++) 
            for (int d : divs(b[i] - b[j])) {
                if (d > b[2] && d <= mxl)
                    cnt[d]++;
            }
    }
    
    for (auto [f, s] : cnt)
        if (s == b.size() - 3) ans += f;

    cout << ans << endl;
}

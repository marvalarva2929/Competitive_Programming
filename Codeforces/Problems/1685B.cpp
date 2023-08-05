#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5;
bool x[mxn + 1];
int a, b, c, d;

void solve() {
    cin >> a >> b >> c >> d;
    string s; cin >> s;
    int n = s.size();

    int cnt = 0;

    for (int i = 0; i < n; i++)
        x[i] = (s[i] == 'A'),
        cnt += x[i];

    if (cnt != a + c + d) {
        cout << "NO" << nl;
        return;
    }
    
    x[n] = x[n - 1];

    vector<int> one, two, three;
    int last = 0;

    for (int i = 1; i <= n; i++)
        if (x[i] == x[i - 1]) {
//            cout << i << " : " << last << nl;
            int dist =  i - last;
            last = i;
            if (dist == 1) continue;
            else if (dist % 2) one.push_back(dist);
            else if (x[i]) three.push_back(dist);
            else two.push_back(dist);
        }
 
    sort(two.begin(), two.end());
    sort(three.begin(), three.end());

    //for (int x : one)
    //    cout << x << " ";
    //cout << nl;

    //for (int x : two)
    //    cout << x << " ";
    //cout << nl;

    //for (int x : three)
    //    cout << x << " ";
    //cout << nl << nl;

    for (int i = 0; i < two.size() && c; i++) {
        int tc = c;
        c -= min(tc, two[i]/2);
        two[i] -= min(two[i], tc*2);
    }

    for (int i = 0; i < three.size() && d; i++) {
        int tc = d;
        d -= min(tc, three[i]/2);
        three[i] -= min(three[i], tc*2);
    }
       
    //cout << c << " " << d << nl;

    if (c) {
        for (int i = 0; i < three.size(); i++)
            c -= min(c, max((int)0, three[i]/2 - 1));
    } else if (d) {
        for (int i = 0; i < two.size(); i++)
            d -= min(d, max((int)0, two[i]/2 - 1));
    }
    
    int cn = 0;
    for (int x : one)
        cn += x/2;

    int tc = c;
    c -= min(tc, cn);
    cn -= min(tc, cn);

    tc = d;
    d -= min(tc, cn);
    cn -= min(tc, cn);

    cout << (c + d == 0 ? "YES" : "NO") << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}



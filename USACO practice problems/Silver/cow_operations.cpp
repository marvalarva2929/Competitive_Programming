using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define pii pair<pi, pi>
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)

const int mxn = 2e5;
int a[mxn];
int pref[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    string __a; cin >> __a;
    int n = __a.size();
    for (int i = 1; i <= __a.size(); i++)
        a[i] = (__a[i - 1] == 'C' ? 
                    1 : 
                    (__a[i - 1] == 'O' ? 
                        2 : 
                        (__a[i - 1] == 'W' ? 
                            3 : 
                            -1)));

    for (int i = 1; i <= n; i++)
        pref[i] = a[i] ^ pref[i - 1];


    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << ((pref[r] ^ pref[l - 1]) == 1 ? "Y" : "N");
    }

    cout << nl;
    

}
using namespace std;
#include <bits/stdc++.h>
#include <string.h>
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
#define pb push_back
#define int long long
#define nl '\n'
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;



int32_t main() {
    int n; cin >> n;
    vector<int> pref(n + 1);
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    int l = 0, r = 0;
    set<int> s = {0};
    int ans = 0; 

    while (l < n) {
        while(r < n && !s.count(pref[r + 1])) {
            r++;
            s.insert(pref[r]);
        }
        ans += r - l;
        s.erase(pref[l]);
        l++;
    }
    cout << ans << nl;
} 
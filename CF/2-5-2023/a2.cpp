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

void solve() {
    int n; cin >> n;
    int aw = 0, ab = 0, bw = 0, bb = 0;

    aw += 1, n -= 1;
    int i = 2;

    while (n > 0) 
        if ((i/2) % 2) {
            int add = min((int)n, i + i + 1);
            bb += ceil((double)add/2);
            bw += floor((double)add/2);
            n -= add;
            i += 2;
        } else { 
            int add = min((int)n, i + i + 1);
            aw += ceil((double)add/2);
            ab += floor((double)add/2);
            n -= i + i + 1;
            i += 2;
        } 

    cout << aw << " " << ab << " " << bw << " " << bb << nl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    int t; cin >> t;
    while (t--)
        solve();
} 
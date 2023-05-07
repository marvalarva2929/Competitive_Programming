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
#define MAX (int)1e5 + 10
int n;
    
int query(int x) {
    if (x < 1 || x > n) return 0;
    cout << "? " << x << nl;
    cout.flush();
    int ret; cin >> ret; return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;

    int lo = 1, hi = n;

    while (lo < hi) {
        int mid = (lo + hi)/2;
        int m = query(mid);
        int m2 = query(mid + 1);
        if (m < m2)
            hi = mid;
        else   
            lo = mid + 1;
    }
    cout << "! " << lo << nl;

} 
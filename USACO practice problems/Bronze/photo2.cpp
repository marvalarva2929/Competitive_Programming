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
#define f first
#define s second


int32_t main() {
    int n;
    cin >> n;
    map<int, int> loc;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        loc[b[i]] = i;
    }
    int ans = 0;
    int m = 0;
    for (int i = 0; i < n; i++) {
        int l = a[i];
        m = max(m, loc[l]);
        if (m > loc[l]) ans++;
    }
    cout << ans << nl;
} 

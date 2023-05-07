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
#define MAX (int)5e5 + 10


void solve() {
    int n, k; cin >> n >> k;

    vector<int> cnt(2 * k  + 1, 0);
    vector<int> ch1(2 * k + 2, 0);
    vector<int> a(n, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int maxsum = INT_MIN;

    for (int i = 0; i < n/2; i++) {
        cnt[a[i] + a[n - i - 1]]++; // without changing any numbers
        maxsum = max(a[i] + a[n - i - 1], maxsum);
        ch1[min(a[i], a[n - i - 1]) + 1]++; // minimum value by changing 1
        ch1[max(a[i], a[n - i - 1]) + k + 1]--; // maximum value by changing 1
    }
    int ans = INT_MAX;

    for (int i = 1; i <= 2 * k + 1; i++) {
        ch1[i] += ch1[i - 1];
    }

    for (int i = 2; i <= 2 * k; i++) {
        // cout << i << ": " << ch1[i] << ": " << cnt[i] << nl;
        int atX = (ch1[i] - cnt[i]) + (((n/2) - ch1[i]) * 2);
        ans = min(ans, atX);
    }

    cout << ans << nl;
}

int32_t main() {
    int t; cin >> t;
    while (t--) 
        solve();
}
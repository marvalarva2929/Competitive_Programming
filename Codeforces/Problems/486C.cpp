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
#define min(x, y) (int)min((int)x, (int)y)

int diff(char x, char y) {
    int a = (int)x - 97;
    int b = (int)y - 97;
    if (b < a)
        swap(a, b);
    
    int ans = min(b - a, (26 - b) + a);
    return ans;
}

int32_t main() {
    int n, p, ans = 0;
    cin >> n >> p;
    string s; cin >> s;
    if (p > n/2) {
        reverse(s.begin(), s.end());
        p = n - p;
    } else p--;
    // p is now 0 indexed
    int l = n + 1, r = n + 1;
    bool changed = false;
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n - i - 1]) {
            ans += diff(s[i], s[n - i - 1]);
            r = i;
            changed = true;
            l = min(i, l);
        }
    }
    if (changed) 
        ans += min(abs(p - l), abs(p - r)) + abs(r - l);
    
    cout << ans << nl;
} 
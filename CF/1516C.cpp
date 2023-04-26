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
#define MAX (int)100 + 10
int a[MAX];
int n;
bool bad() {
    int s = 0;
    for (int i = 0; i < n; i++)
        s += a[i];
    
    if (s%2)
        return 0;
    
    bitset<200005> b;
    b[0] = 1;
    for (int i = 0; i < n; i++)
        b |= (b << a[i]);
    
    return b[s/2];
}

int32_t main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    if (bad()) {
        pair<int, int> mn = {20, 0};
        for (int i = 0; i < n; i++)
            mn = min(mn, {__builtin_ctz(a[i]), i + 1});
        cout << 1 << nl;
        cout << mn.second << nl;
    } else cout << 0 << nl;
} 
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

string solve() {
    int n; cin >> n;
    if (n % 2 == 1)
        return "Bob";

    double logg = log2(n);
    if (logg == (int)logg)
        if ((int)logg % 2 == 0)
            return "Alice";
        else 
            return "Bob";
    else    
        return "Alice";
    
}

int32_t main() {
    int t; cin >> t;
    while (t--)
        cout << solve() << nl;
} 
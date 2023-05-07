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
    int u, v; cin >> u >> v; // u is xor, v is sum
    if ((u > v) || (abs(u - v) % 2 == 1)) {
        cout << -1 << nl;
        return 0;
    }

    set<int> untouchable_bits;
    for (int i = 0; i <= log2(u); i++) 
        if ((u >> i)&1) 
            untouchable_bits.insert(i);
    

    int n = (u != 0);
    vector<int> ans;
    if (u != 0) ans.push_back(u);
    int diff = (v - u)/2;
    if (diff == 0) {
        cout << n << nl;
        for (int a : ans)
            cout << a << " ";
        cout << nl;
        return 0;
    }

    
    bool twoextra = false;
    for (int i : untouchable_bits) 
        if ((diff >> i)&1) {
            twoextra = true;
            break;
        }
    
    if (twoextra || ans.size() == 0) {
        ans.push_back(diff);
        ans.push_back(diff);
        n += 2;
    } else {
        ans[0] += diff;
        ans.push_back(diff);
        n += 1;
    } 
    
    cout << n << nl;
    for (int a : ans)
        cout << a << " ";
    cout << nl;

} 
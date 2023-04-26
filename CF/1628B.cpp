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
#define f first
#define s second
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

void solve() {
    unordered_map<string, int> existsMax;
    unordered_map<string, int> existsMin;
    vector<pair<string, int>> two, three;
    int n; cin >> n;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        string st; cin >> st;
        if (existsMin[st]) {
            existsMin[st] = min(existsMin[st], i);
        } else existsMin[st] = i;

        existsMax[st] = max(existsMax[st], i);
    
        if (st.size() == 1) 
            flag = true;
        else if (st.size() == 2)
            two.push_back({st, i});
        else 
            three.push_back({st, i});
    }

    if (flag) {
        cout << yes << nl;
        return;
    }

    for (auto t : two) { // 2 - 2 
        string rev = t.f;
        reverse(rev.begin(), rev.end());
        if (existsMax[rev]) {
            cout << yes << nl;
            return;
        }
        if (rev[0] == rev[1]) {
            cout << yes << nl;
            return;
        }
    }

    for (auto t : three) {  // 3 - 3 || 3 - 2 || 2 - 3
        string rev = t.f; // 3 - 3
        string rev2 = t.f.substr(0, 2); // 3 - 2
        string rev3 = t.f.substr(1, 2); // 2 - 3
        reverse(rev.begin(), rev.end());
        reverse(rev2.begin(), rev2.end());  
        reverse(rev3.begin(), rev3.end());  
        if ((existsMax[rev]) || (existsMax[rev2] > t.s) || (existsMin[rev3] < t.s && existsMin[rev3])) {
            cout << yes << nl;
            return;
        }
        if (rev[0] == rev[2]) {
            cout << yes << nl;
            return;
        }
    }

    cout << no << nl;
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--)
        solve();
} 
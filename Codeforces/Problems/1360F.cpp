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

int diff(string a, string b) {
    int ans = 0;
    assert(a.size() == b.size());
    for (int i = 0; i < a.size(); i++) 
        if (a[i] != b[i])
            ans++;

    return ans;
}

bool isSol(vector<string> check, string to) {
    for (string s : check) 
        if (diff(s, to) > 1)
            return false;
    
    return true;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<string> strings(n);
    for (int i = 0; i < n; i++)
        cin >> strings[i];

    string check = strings[0];
    for (int i = 0; i < m; i++) {
        string t = check;
        for (int j = 0; j < 26; j++) {
            t[i] = (char)(j + 97);
            if (isSol(strings, t)) {
                cout << t << nl;
                return;
            }
        }
    }
    cout << -1 << nl;
    return;
}       

int32_t main() {
     int t; cin >> t;
     while (t--)
        solve();
} 